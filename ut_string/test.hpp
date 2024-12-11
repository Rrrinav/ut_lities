#include <chrono>
#include <functional>
#include <iostream>
#include <map>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

namespace AnsiColor
{
  const std::string RESET = "\033[0m";
  const std::string RED = "\033[38;5;196m";     // Bright red
  const std::string GREEN = "\033[38;5;46m";    // Bright green
  const std::string YELLOW = "\033[38;5;226m";  // Bright yellow
  const std::string BLUE = "\033[38;5;21m";     // Bright blue
  const std::string CYAN = "\033[38;5;51m";     // Bright cyan
  const std::string WHITE = "\033[38;5;231m";   // Bright white
  const std::string GRAY = "\033[38;5;240m";    // Dark gray
}  // namespace AnsiColor

class Logger
{
public:
  void log(const std::string &message) { std::cout << message << std::endl; }

  void log_success(const std::string &message) { std::cout << AnsiColor::GREEN << "[PASS] " << AnsiColor::RESET << message << std::endl; }

  void log_failuree(const std::string &message) { std::cout << AnsiColor::RED << "[FAIL] " << AnsiColor::RESET << message << std::endl; }

  void log_skip(const std::string &message) { std::cout << AnsiColor::YELLOW << "[SKIP] " << AnsiColor::RESET << message << std::endl; }

  void log_summary(int total, int passed, int failed, int skipped)
  {
    std::cout << "\n" << AnsiColor::CYAN << "Test Suite Summary:\n" << AnsiColor::RESET;
    std::cout << "Total Tests: " << total << "\n";
    std::cout << "Passed: " << passed << "\n";
    std::cout << "Failed: " << failed << "\n";
    std::cout << "Skipped: " << skipped << "\n";
  }
};

class Test_suite
{
private:
  std::string name;
  Logger logger;
  int passed = 0, failed = 0, skipped = 0;
  std::map<std::string, std::function<void()>> tests;
  std::map<std::string, bool> test_skipped;

public:
  Test_suite(std::string name) : name(name) {}

  void add_test(const std::string &testName, const std::function<void()> &testFunc, bool skip = false)
  {
    tests[testName] = testFunc;
    test_skipped[testName] = skip;
  }

  void run_test(const std::string &testName)
  {
    if (tests.find(testName) != tests.end())
    {
      if (test_skipped[testName])
      {
        std::cout << "\nSkipping Test: " << testName << '\n';
        logger.log_skip("Test " + testName + " skipped.");
        skipped++;
        return;
      }

      try
      {
        std::cout << "\nRunning Test: " << testName << std::endl;
        auto start = std::chrono::high_resolution_clock::now();

        // Execute the test function (lambda)
        tests[testName]();

        auto end = std::chrono::high_resolution_clock::now();
        double duration = std::chrono::duration<double>(end - start).count();
        passed++;

        logger.log_success(testName + " passed (" + std::to_string(duration) + "s)");
      }
      catch (const std::exception &e)
      {
        failed++;
        logger.log_failuree(testName + " failed: " + e.what());
      }
      catch (...)
      {
        failed++;
        logger.log_failuree(testName + " failed: Unknown error");
      }
    }
    else
    {
      std::cerr << "Test with name '" << testName << "' not found!" << std::endl;
    }
  }

  void run_all_tests()
  {
    std::cout << "=====================================" << " Running Test Suite: " << name
              << " ======================================" << std::endl;
    for (const auto &test : tests)
      run_test(test.first);
  }

  static void assertEquals(const std::string &expected, const std::string &actual, const std::string &message)
  {
    if (expected != actual)
      throw std::runtime_error(message + ": Expected '" + expected + "' but got '" + actual + "'");
  }

  template <typename T>
  static void assert_equals(const T &expected, const T &actual, const std::string &message)
  {
    if (expected != actual)
    {
      std::ostringstream error_msg;
      error_msg << "Assertion failed: " << (message.empty() ? "Values not equal" : message) << "\nExpected: " << expected
                << "\nActual:   " << actual;
      throw std::runtime_error(error_msg.str());
    }
  }

  static void assert_true(bool condition, const std::string &message)
  {
    if (!condition)
      throw std::runtime_error(message + ": Expected true but got false");
  }

  static void assert_false(bool condition, const std::string &message)
  {
    if (condition)
      throw std::runtime_error(message + ": Expected false but got true");
  }

  void log_summary() { logger.log_summary(passed + failed + skipped, passed, failed, skipped); }
};
