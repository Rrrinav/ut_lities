#include "./test.hpp"

#define STR_IMPLEMENTATION
#include "./str_utl_funcs.hpp"

void add_trim(Test_suite &suite)
{
  suite.add_test("trim Hello world",
                 []()
                 {
                   std::string str = "   hello world   ";
                   std::string result = utl::trim(str);
                   Test_suite::assert_equals<std::string>("hello world", result, "Trim hello world");
                 });

  suite.add_test("trim empty string",
                 []()
                 {
                   std::string str = "";
                   std::string result = utl::trim(str);
                   Test_suite::assert_equals<std::string>("", result, "Trim empty");
                 });

  suite.add_test("trim single space",
                 []()
                 {
                   std::string str = " ";
                   std::string result = utl::trim(str);
                   Test_suite::assert_equals<std::string>("", result, "Trim single space");
                 });
}

void add_trim_right_left(Test_suite &suite)
{
  suite.add_test("trim Hello world right",
                 []()
                 {
                   std::string str = "hello world   ";
                   std::string result = utl::trim(str);
                   Test_suite::assert_equals<std::string>("hello world", result, "Trim hello world right");
                 });

  suite.add_test("trim Hello world left",
                 []()
                 {
                   std::string str = "   hello world ";
                   std::string result = utl::trim_left(str);
                   Test_suite::assert_equals<std::string>("hello world ", result, "Trim hello world left");
                 });
  suite.add_test("trim empty string left",
                 []()
                 {
                   std::string str = "";
                   std::string result = utl::trim_left(str);
                   Test_suite::assert_equals<std::string>("", result, "Trim empty");
                 });

  suite.add_test("trim empty string right",
                 []()
                 {
                   std::string str = "";
                   std::string result = utl::trim_right(str);
                   Test_suite::assert_equals<std::string>("", result, "Trim empty");
                 });
  suite.add_test("trim single space left",
                 []()
                 {
                   std::string str = " ";
                   std::string result = utl::trim_left(str);
                   Test_suite::assert_equals<std::string>("", result, "Trim single space");
                 });
  suite.add_test("trim single space right",
                 []()
                 {
                   std::string str = " ";
                   std::string result = utl::trim_right(str);
                   Test_suite::assert_equals<std::string>("", result, "Trim single space");
                 });
}
void add_lower_upper(Test_suite &suite)
{
  suite.add_test("to_lower Hello world",
                 []()
                 {
                   std::string str = "Hello world";
                   std::string result = utl::to_lower(str);
                   Test_suite::assert_equals<std::string>("hello world", result, "to_lower Hello world");
                 });
  suite.add_test("to_upper Hello world",
                 []()
                 {
                   std::string str = "Hello world";
                   std::string result = utl::to_upper(str);
                   Test_suite::assert_equals<std::string>("HELLO WORLD", result, "to_upper Hello world");
                 });
  suite.add_test("to_lower empty",
                 []()
                 {
                   std::string str = "";
                   std::string result = utl::to_lower(str);
                   Test_suite::assert_equals<std::string>("", result, "to_lower Hello world");
                 });
  suite.add_test("to_upper empty",
                 []()
                 {
                   std::string str = "";
                   std::string result = utl::to_upper(str);
                   Test_suite::assert_equals<std::string>("", result, "to_upper Hello world");
                 });

  suite.add_test("to_lower hello world",
                 []()
                 {
                   std::string str = "hello world";
                   std::string result = utl::to_lower(str);
                   Test_suite::assert_equals<std::string>("hello world", result, "to_lower Hello world");
                 });

  suite.add_test("to_upper hello world",
                 []()
                 {
                   std::string str = "HELLO WORLD";
                   std::string result = utl::to_upper(str);
                   Test_suite::assert_equals<std::string>("HELLO WORLD", result, "to_upper Hello world");
                 });
}

void add_replace(Test_suite &suite)
{
  suite.add_test("replace Hello world",
                 []()
                 {
                   std::string str = "Hello world";
                   std::string result = utl::replace(str, "world", "there");
                   Test_suite::assert_equals<std::string>("Hello there", result, "replace Hello world");
                 });
  suite.add_test("replace empty",
                 []()
                 {
                   std::string str = "";
                   std::string result = utl::replace(str, "", "");
                   Test_suite::assert_equals<std::string>("", result, "replace empty");
                 });
  suite.add_test("replace single space",
                 []()
                 {
                   std::string str = " ";
                   std::string result = utl::replace(str, " ", "");
                   Test_suite::assert_equals<std::string>("", result, "replace single space");
                 });
  suite.add_test("replace single space with space",
                 []()
                 {
                   std::string str = " ";
                   std::string result = utl::replace(str, " ", " ");
                   Test_suite::assert_equals<std::string>(" ", result, "replace single space with space");
                 });
  suite.add_test("replace empty with space",
                 []()
                 {
                   std::string str = "";
                   std::string result = utl::replace(str, "", " ");
                   Test_suite::assert_equals<std::string>(" ", result, "replace empty with space");
                 });

  suite.add_test("replace multiple",
                 []()
                 {
                   std::string str = "Hello world, hello world";
                   std::string result = utl::replace(str, "world", "there");
                   Test_suite::assert_equals<std::string>("Hello there, hello there", result, "replace multiple");
                 });
  suite.add_test("replace non-existent substring",
                 []()
                 {
                   std::string str = "Hello world";
                   std::string result = utl::replace(str, "universe", "galaxy");
                   Test_suite::assert_equals<std::string>("Hello world", result, "replace non-existent substring");
                 });

  suite.add_test("replace with longer replacement",
                 []()
                 {
                   std::string str = "Hello world";
                   std::string result = utl::replace(str, "world", "beautiful world");
                   Test_suite::assert_equals<std::string>("Hello beautiful world", result, "replace with longer replacement");
                 });

  suite.add_test("replace with shorter replacement",
                 []()
                 {
                   std::string str = "Hello world";
                   std::string result = utl::replace(str, "world", "all");
                   Test_suite::assert_equals<std::string>("Hello all", result, "replace with shorter replacement");
                 });

  suite.add_test("replace case-sensitive",
                 []()
                 {
                   std::string str = "Hello World";
                   std::string result = utl::replace(str, "world", "universe");
                   Test_suite::assert_equals<std::string>("Hello World", result, "replace case-sensitive");
                 });

  suite.add_test("replace with special characters",
                 []()
                 {
                   std::string str = "Hello, world! How are you?";
                   std::string result = utl::replace(str, "world", "planet");
                   Test_suite::assert_equals<std::string>("Hello, planet! How are you?", result, "replace with special characters");
                 });

  suite.add_test("replace entire string",
                 []()
                 {
                   std::string str = "Hello world";
                   std::string result = utl::replace(str, "Hello world", "Goodbye");
                   Test_suite::assert_equals<std::string>("Goodbye", result, "replace entire string");
                 });
}

void add_start_end_with(Test_suite &suite)
{
  suite.add_test("start_with Hello world",
                 []()
                 {
                   std::string str = "Hello world";
                   bool result = utl::starts_with(str, "Hello");
                   Test_suite::assert_equals<bool>(true, result, "start_with Hello world");
                 });

  suite.add_test("start_with empty string",
                 []()
                 {
                   std::string str = "";
                   bool result = utl::starts_with(str, "");
                   Test_suite::assert_equals<bool>(true, result, "start_with empty string with empty prefix");
                 });

  suite.add_test("start_with empty original string",
                 []()
                 {
                   std::string str = "";
                   bool result = utl::starts_with(str, "test");
                   Test_suite::assert_equals<bool>(false, result, "start_with empty original string");
                 });

  suite.add_test("start_with prefix longer than string",
                 []()
                 {
                   std::string str = "short";
                   bool result = utl::starts_with(str, "longer prefix");
                   Test_suite::assert_equals<bool>(false, result, "start_with prefix longer than string");
                 });

  suite.add_test("start_with case-sensitive match",
                 []()
                 {
                   std::string str = "Hello World";
                   bool result = utl::starts_with(str, "hello");
                   Test_suite::assert_equals<bool>(false, result, "start_with case-sensitive match");
                 });

  suite.add_test("start_with single character",
                 []()
                 {
                   std::string str = "Hello world";
                   bool result = utl::starts_with(str, "H");
                   Test_suite::assert_equals<bool>(true, result, "start_with single character");
                 });

  suite.add_test("start_with special characters",
                 []()
                 {
                   std::string str = "!@#$%^&* test";
                   bool result = utl::starts_with(str, "!@#");
                   Test_suite::assert_equals<bool>(true, result, "start_with special characters");
                 });

  suite.add_test("start_with unicode characters",
                 []()
                 {
                   std::string str = "こんにちは world";
                   bool result = utl::starts_with(str, "こんにちは");
                   Test_suite::assert_equals<bool>(true, result, "start_with unicode characters");
                 });

  suite.add_test("start_with whitespace",
                 []()
                 {
                   std::string str = "   trimmed text";
                   bool result = utl::starts_with(str, "   ");
                   Test_suite::assert_equals<bool>(true, result, "start_with whitespace");
                 });

  suite.add_test("start_with exact match",
                 []()
                 {
                   std::string str = "exact";
                   bool result = utl::starts_with(str, "exact");
                   Test_suite::assert_equals<bool>(true, result, "start_with exact match");
                 });

  suite.add_test("start_with no match at start",
                 []()
                 {
                   std::string str = "Hello world";
                   bool result = utl::starts_with(str, "world");
                   Test_suite::assert_equals<bool>(false, result, "start_with no match at start");
                 });

  suite.add_test("start_with mid-string substring",
                 []()
                 {
                   std::string str = "Hello world";
                   bool result = utl::starts_with(str, "ello");
                   Test_suite::assert_equals<bool>(false, result, "start_with mid-string substring");
                 });

  suite.add_test("start_with multiple consecutive matches",
                 []()
                 {
                   std::string str = "aaaaabc";
                   bool result = utl::starts_with(str, "aaa");
                   Test_suite::assert_equals<bool>(true, result, "start_with multiple consecutive matches");
                 });
}

void add_join(Test_suite &suite)
{
  suite.add_test("Join Hello and world with space",
                 []()
                 {
                   std::string result = utl::join({"Hello", "world"}, " ");
                   Test_suite::assert_equals<std::string>("Hello world", result, "Join Hello and world with space");
                 });

  suite.add_test("Join empty vector",
                 []()
                 {
                   std::vector<std::string> empty_vec;
                   std::string result = utl::join(empty_vec, ",");
                   Test_suite::assert_equals<std::string>("", result, "Join empty vector");
                 });

  suite.add_test("Join single element vector",
                 []()
                 {
                   std::string result = utl::join({"Hello"}, " ");
                   Test_suite::assert_equals<std::string>("Hello", result, "Join single element vector");
                 });

  suite.add_test("Join with empty separator",
                 []()
                 {
                   std::string result = utl::join({"Hello", "world"}, "");
                   Test_suite::assert_equals<std::string>("Helloworld", result, "Join with empty separator");
                 });

  suite.add_test("Join with multiple elements",
                 []()
                 {
                   std::string result = utl::join({"Hello", "beautiful", "world"}, ", ");
                   Test_suite::assert_equals<std::string>("Hello, beautiful, world", result, "Join with multiple elements");
                 });

  suite.add_test("Join with special characters separator",
                 []()
                 {
                   std::string result = utl::join({"Hello", "world"}, "||");
                   Test_suite::assert_equals<std::string>("Hello||world", result, "Join with special characters separator");
                 });

  suite.add_test("Join with numbers converted to strings",
                 []()
                 {
                   std::vector<std::string> nums = {"42", "17", "99"};
                   std::string result = utl::join(nums, "-");
                   Test_suite::assert_equals<std::string>("42-17-99", result, "Join with numbers converted to strings");
                 });

  suite.add_test("Join with unicode characters",
                 []()
                 {
                   std::vector<std::string> words = {"こんにちは", "世界"};
                   std::string result = utl::join(words, " ");
                   Test_suite::assert_equals<std::string>("こんにちは 世界", result, "Join with unicode characters");
                 });

  suite.add_test("Join with whitespace elements",
                 []()
                 {
                   std::vector<std::string> words = {"  Hello  ", "  world  "};
                   std::string result = utl::join(words, "|");
                   Test_suite::assert_equals<std::string>("  Hello  |  world  ", result, "Join with whitespace elements");
                 });

  suite.add_test("Join with mixed content",
                 []()
                 {
                   std::vector<std::string> mixed = {"Hello", "", "world"};
                   std::string result = utl::join(mixed, "-");
                   Test_suite::assert_equals<std::string>("Hello--world", result, "Join with mixed content including empty string");
                 });

  suite.add_test("Join with long separator",
                 []()
                 {
                   std::string result = utl::join({"Hello", "world"}, " --- ");
                   Test_suite::assert_equals<std::string>("Hello --- world", result, "Join with long separator");
                 });

  suite.add_test("Join with repeated separator behavior",
                 []()
                 {
                   std::vector<std::string> repeated = {"a", "a", "a"};
                   std::string result = utl::join(repeated, ",");
                   Test_suite::assert_equals<std::string>("a,a,a", result, "Join with repeated elements");
                 });
}

void add_trim_till(Test_suite &suite)
{
  suite.add_test("trim_till basic delimiter",
                 []()
                 {
                   std::string str = "Hello,world";
                   std::string result = utl::trim_till(str, ',');
                   Test_suite::assert_equals<std::string>("world", result, "trim_till basic delimiter");
                 });

  suite.add_test("trim_till delimiter at beginning",
                 []()
                 {
                   std::string str = ",Hello world";
                   std::string result = utl::trim_till(str, ',');
                   Test_suite::assert_equals<std::string>("Hello world", result, "trim_till delimiter at beginning");
                 });

  suite.add_test("trim_till no delimiter",
                 []()
                 {
                   std::string str = "Hello world";
                   std::string result = utl::trim_till(str, ',');
                   Test_suite::assert_equals<std::string>("Hello world", result, "trim_till no delimiter");
                 });

  suite.add_test("trim_till empty string",
                 []()
                 {
                   std::string str = "";
                   std::string result = utl::trim_till(str, ',');
                   Test_suite::assert_equals<std::string>("", result, "trim_till empty string");
                 });

  suite.add_test("trim_till multiple delimiters",
                 []()
                 {
                   std::string str = "first,second,third";
                   std::string result = utl::trim_till(str, ',');
                   Test_suite::assert_equals<std::string>("second,third", result, "trim_till multiple delimiters");
                 });

  suite.add_test("trim_till delimiter at end",
                 []()
                 {
                   std::string str = "Hello world,";
                   std::string result = utl::trim_till(str, ',');
                   Test_suite::assert_equals<std::string>("", result, "trim_till delimiter at end");
                 });

  suite.add_test("trim_till special characters",
                 []()
                 {
                   std::string str = "prefix#suffix";
                   std::string result = utl::trim_till(str, '#');
                   Test_suite::assert_equals<std::string>("suffix", result, "trim_till special characters");
                 });

  suite.add_test("trim_till whitespace delimiter",
                 []()
                 {
                   std::string str = "Hello world";
                   std::string result = utl::trim_till(str, ' ');
                   Test_suite::assert_equals<std::string>("world", result, "trim_till whitespace delimiter");
                 });

  suite.add_test("trim_till with unicode characters",
                 []()
                 {
                   std::string str = "こんにちは:世界";
                   std::string result = utl::trim_till(str, ':');
                   Test_suite::assert_equals<std::string>("世界", result, "trim_till with unicode characters");
                 });

  suite.add_test("trim_till consecutive delimiters",
                 []()
                 {
                   std::string str = "first,,second";
                   std::string result = utl::trim_till(str, ',');
                   Test_suite::assert_equals<std::string>(",second", result, "trim_till consecutive delimiters");
                 });

  suite.add_test(
      "trim_till non-ascii delimiter",
      []()
      {
        std::string str = "first§second";
        std::string result = utl::trim_till(str, '§');
        Test_suite::assert_equals<std::string>("second", result, "trim_till non-ascii delimiter (§)");
      },
      true);
}

void add_equal_ignorecase(Test_suite &suite)
{
  suite.add_test("equal_ignorecase basic match",
                 []()
                 {
                   bool result = utl::equal_ignorecase("Hello", "hello");
                   Test_suite::assert_equals<bool>(true, result, "equal_ignorecase basic match");
                 });

  suite.add_test("equal_ignorecase different cases",
                 []()
                 {
                   bool result = utl::equal_ignorecase("WORLD", "world");
                   Test_suite::assert_equals<bool>(true, result, "equal_ignorecase different cases");
                 });

  suite.add_test("equal_ignorecase empty strings",
                 []()
                 {
                   bool result = utl::equal_ignorecase("", "");
                   Test_suite::assert_equals<bool>(true, result, "equal_ignorecase empty strings");
                 });

  suite.add_test("equal_ignorecase mismatched length",
                 []()
                 {
                   bool result = utl::equal_ignorecase("Hello", "hello world");
                   Test_suite::assert_equals<bool>(false, result, "equal_ignorecase mismatched length");
                 });

  suite.add_test("equal_ignorecase mixed case complex",
                 []()
                 {
                   bool result = utl::equal_ignorecase("HeLLo WoRLd", "hello world");
                   Test_suite::assert_equals<bool>(true, result, "equal_ignorecase mixed case complex");
                 });

  suite.add_test(
      "equal_ignorecase unicode characters",
      []()
      {
        bool result = utl::equal_ignorecase("ÜBER", "über");
        Test_suite::assert_equals<bool>(true, result, "equal_ignorecase unicode characters");
      },
      true);

  suite.add_test("equal_ignorecase different strings",
                 []()
                 {
                   bool result = utl::equal_ignorecase("Hello", "World");
                   Test_suite::assert_equals<bool>(false, result, "equal_ignorecase different strings");
                 });

  suite.add_test("equal_ignorecase special characters",
                 []()
                 {
                   bool result = utl::equal_ignorecase("Hello!", "HELLO!");
                   Test_suite::assert_equals<bool>(true, result, "equal_ignorecase special characters");
                 });

  suite.add_test("equal_ignorecase whitespace",
                 []()
                 {
                   bool result = utl::equal_ignorecase("  Hello  ", "  HELLO  ");
                   Test_suite::assert_equals<bool>(true, result, "equal_ignorecase whitespace");
                 });
}

void add_chop_by_delimiter(Test_suite &suite)
{
  suite.add_test("chop_by_delimiter basic string delimiter",
                 []()
                 {
                   std::vector<std::string> result = utl::chop_by_delimiter("a||b||c", "||");
                   std::vector<std::string> expected = {"a", "b", "c"};

                   Test_suite::assert_equals(expected.size(), result.size(), "Size mismatch in chop_by_delimiter basic string delimiter");
                   for (size_t i = 0; i < result.size(); ++i)
                   {
                     Test_suite::assert_equals(
                         expected[i], result[i], "Mismatch at index " + std::to_string(i) + " in chop_by_delimiter basic string delimiter");
                   }
                 });

  suite.add_test("chop_by_delimiter empty string",
                 []()
                 {
                   std::vector<std::string> result = utl::chop_by_delimiter("", "||");
                   std::vector<std::string> expected = {""};

                   Test_suite::assert_equals(expected.size(), result.size(), "Size mismatch in chop_by_delimiter empty string");
                   for (size_t i = 0; i < result.size(); ++i)
                     Test_suite::assert_equals(
                         expected[i], result[i], "Mismatch at index " + std::to_string(i) + " in chop_by_delimiter empty string");
                 });

  suite.add_test("chop_by_delimiter no delimiter",
                 []()
                 {
                   std::vector<std::string> result = utl::chop_by_delimiter("hello", "xyz");
                   std::vector<std::string> expected = {"hello"};

                   Test_suite::assert_equals(expected.size(), result.size(), "Size mismatch in chop_by_delimiter no delimiter");
                   for (size_t i = 0; i < result.size(); ++i)
                     Test_suite::assert_equals(
                         expected[i], result[i], "Mismatch at index " + std::to_string(i) + " in chop_by_delimiter no delimiter");
                 });

  suite.add_test("chop_by_delimiter consecutive delimiters",
                 []()
                 {
                   std::vector<std::string> result = utl::chop_by_delimiter("a||||b||c", "||");
                   std::vector<std::string> expected = {"a", "", "b", "c"};

                   Test_suite::assert_equals(expected.size(), result.size(), "Size mismatch in chop_by_delimiter consecutive delimiters");
                   for (size_t i = 0; i < result.size(); ++i)
                   {
                     Test_suite::assert_equals(
                         expected[i], result[i], "Mismatch at index " + std::to_string(i) + " in chop_by_delimiter consecutive delimiters");
                   }
                 });

  suite.add_test("chop_by_delimiter trailing delimiter",
                 []()
                 {
                   std::vector<std::string> result = utl::chop_by_delimiter("a||b||c||", "||");
                   std::vector<std::string> expected = {"a", "b", "c", ""};

                   Test_suite::assert_equals(expected.size(), result.size(), "Size mismatch in chop_by_delimiter trailing delimiter");
                   for (size_t i = 0; i < result.size(); ++i)
                   {
                     Test_suite::assert_equals(
                         expected[i], result[i], "Mismatch at index " + std::to_string(i) + " in chop_by_delimiter trailing delimiter");
                   }
                 });

  suite.add_test("chop_by_delimiter leading delimiter",
                 []()
                 {
                   std::vector<std::string> result = utl::chop_by_delimiter("||a||b||c", "||");
                   std::vector<std::string> expected = {"", "a", "b", "c"};

                   Test_suite::assert_equals(expected.size(), result.size(), "Size mismatch in chop_by_delimiter leading delimiter");
                   for (size_t i = 0; i < result.size(); ++i)
                   {
                     Test_suite::assert_equals(
                         expected[i], result[i], "Mismatch at index " + std::to_string(i) + " in chop_by_delimiter leading delimiter");
                   }
                 });

  suite.add_test(
      "chop_by_delimiter single character delimiter",
      []()
      {
        std::vector<std::string> result = utl::chop_by_delimiter("a,b,c", ",");
        std::vector<std::string> expected = {"a", "b", "c"};

        Test_suite::assert_equals(expected.size(), result.size(), "Size mismatch in chop_by_delimiter single character delimiter");
        for (size_t i = 0; i < result.size(); ++i)
        {
          Test_suite::assert_equals(
              expected[i], result[i], "Mismatch at index " + std::to_string(i) + " in chop_by_delimiter single character delimiter");
        }
      });

  suite.add_test("chop_by_delimiter empty delimiter",
                 []()
                 {
                   std::vector<std::string> result = utl::chop_by_delimiter("hello", "");
                   std::vector<std::string> expected = {"hello"};

                   Test_suite::assert_equals(expected.size(), result.size(), "Size mismatch in chop_by_delimiter empty delimiter");
                   for (size_t i = 0; i < result.size(); ++i)
                     Test_suite::assert_equals(
                         expected[i], result[i], "Mismatch at index " + std::to_string(i) + " in chop_by_delimiter empty delimiter");
                 });

  suite.add_test("chop_by_delimiter complex string delimiter",
                 []()
                 {
                   std::vector<std::string> result = utl::chop_by_delimiter("part1###part2###part3", "###");
                   std::vector<std::string> expected = {"part1", "part2", "part3"};

                   Test_suite::assert_equals(expected.size(), result.size(), "Size mismatch in chop_by_delimiter complex string delimiter");
                   for (size_t i = 0; i < result.size(); ++i)
                   {
                     Test_suite::assert_equals(expected[i],
                                               result[i],
                                               "Mismatch at index " + std::to_string(i) + " in chop_by_delimiter complex string delimiter");
                   }
                 });
}

void add_remove_duplicates(Test_suite &suite)
{
  // Test empty string
  suite.add_test("remove_duplicates empty string",
                 []()
                 {
                   std::string input = "";
                   std::string result = utl::remove_duplicates(input);
                   Test_suite::assert_equals(input, result, "Empty string should remain unchanged");
                 });

  // Test string with no duplicates
  suite.add_test("remove_duplicates no duplicates",
                 []()
                 {
                   std::string input = "abcde";
                   std::string result = utl::remove_duplicates(input);
                   Test_suite::assert_equals(input, result, "String with no duplicates should remain unchanged");
                 });

  // Test string with consecutive duplicates
  suite.add_test("remove_duplicates consecutive duplicates",
                 []()
                 {
                   std::string input = "aabbccddee";
                   std::string expected = "abcde";
                   std::string result = utl::remove_duplicates(input);
                   Test_suite::assert_equals(expected, result, "Consecutive duplicates should be removed");
                 });

  // Test string with non-consecutive duplicates
  suite.add_test("remove_duplicates non-consecutive duplicates",
                 []()
                 {
                   std::string input = "abcadbefc";
                   std::string expected = "abcdef";
                   std::string result = utl::remove_duplicates(input);
                   Test_suite::assert_equals(expected, result, "Non-consecutive duplicates should be removed");
                 });

  // Test string with mixed case duplicates
  suite.add_test("remove_duplicates mixed case duplicates",
                 []()
                 {
                   std::string input = "aAAbBcCdDeE";
                   std::string expected = "aAbBcCdDeE";
                   std::string result = utl::remove_duplicates(input);
                   Test_suite::assert_equals(expected, result, "Duplicates with different cases should be preserved");
                 });

  // Test string with special characters and duplicates
  suite.add_test("remove_duplicates special characters",
                 []()
                 {
                   std::string input = "!@##$%%^&*()";
                   std::string expected = "!@#$%^&*()";
                   std::string result = utl::remove_duplicates(input);
                   Test_suite::assert_equals(expected, result, "Consecutive special character duplicates should be removed");
                 });

  // Test string with repeated non-adjacent duplicates
  suite.add_test("remove_duplicates repeated non-adjacent duplicates",
                 []()
                 {
                   std::string input = "abcabcabc";
                   std::string expected = "abc";
                   std::string result = utl::remove_duplicates(input);
                   Test_suite::assert_equals(expected, result, "Repeated non-adjacent duplicates should be handled");
                 });
}

void add_remove_duplicates_case_insensitive(Test_suite &suite)
{
  // Test empty string
  suite.add_test("remove_duplicates_case_insensitive empty string",
                 []()
                 {
                   std::string input = "";
                   std::string result = utl::remove_duplicates_case_insensitive(input);
                   Test_suite::assert_equals(input, result, "Empty string should remain unchanged");
                 });

  // Test string with no duplicates
  suite.add_test("remove_duplicates_case_insensitive no duplicates",
                 []()
                 {
                   std::string input = "abcde";
                   std::string result = utl::remove_duplicates_case_insensitive(input);
                   Test_suite::assert_equals(input, result, "String with no duplicates should remain unchanged");
                 });

  // Test basic mixed case duplicates
  suite.add_test("remove_duplicates_case_insensitive basic mixed case duplicates",
                 []()
                 {
                   std::string input = "aAbBcC";
                   std::string expected = "abc";
                   std::string result = utl::remove_duplicates_case_insensitive(input);
                   Test_suite::assert_equals(expected, result, "Mixed case duplicates should be removed");
                 });

  // Test complex mixed case duplicates
  suite.add_test("remove_duplicates_case_insensitive complex mixed case duplicates",
                 []()
                 {
                   std::string input = "HeLLoWoRLd";
                   std::string expected = "HeLoWRd";
                   std::string result = utl::remove_duplicates_case_insensitive(input);
                   Test_suite::assert_equals(expected, result, "Complex mixed case duplicates should be removed");
                 });

  // Test preserving first occurrence's case
  suite.add_test("remove_duplicates_case_insensitive preserve first occurrence case",
                 []()
                 {
                   std::string input = "HeLLo";
                   std::string expected = "HeLo";
                   std::string result = utl::remove_duplicates_case_insensitive(input);
                   Test_suite::assert_equals(expected, result, "First occurrence case should be preserved");
                 });

  // Test with repeated characters in different cases
  suite.add_test("remove_duplicates_case_insensitive repeated characters different cases",
                 []()
                 {
                   std::string input = "aAaAaA";
                   std::string expected = "a";
                   std::string result = utl::remove_duplicates_case_insensitive(input);
                   Test_suite::assert_equals(expected, result, "Repeated characters in different cases should be reduced");
                 });

  // Test with mixed alphanumeric characters
  suite.add_test("remove_duplicates_case_insensitive mixed alphanumeric",
                 []()
                 {
                   std::string input = "a1A2b3B4c15C";
                   std::string expected = "a12b34c5";
                   std::string result = utl::remove_duplicates_case_insensitive(input);
                   Test_suite::assert_equals(expected, result, "Mixed alphanumeric case-insensitive duplicates");
                 });

  // Test with special characters
  suite.add_test("remove_duplicates_case_insensitive special characters",
                 []()
                 {
                   std::string input = "a!A@b#B$c%C@";
                   std::string expected = "a!@b#$c%";
                   std::string result = utl::remove_duplicates_case_insensitive(input);
                   Test_suite::assert_equals(expected, result, "Case-insensitive removal with special characters");
                 });

  // Test with long string of mixed cases
  suite.add_test("remove_duplicates_case_insensitive long mixed case string",
                 []()
                 {
                   std::string input = "AbCdEfGhIjKlMnOpQrStUvWxYz";
                   std::string expected = "AbCdEfGhIjKlMnOpQrStUvWxYz";
                   std::string result = utl::remove_duplicates_case_insensitive(input);
                   Test_suite::assert_equals(expected, result, "Long string with no duplicates should remain unchanged");
                 });
}

void add_is_numeric_tests(Test_suite &suite)
{
  // Positive integer tests
  suite.add_test("is_numeric positive integers",
                 []()
                 {
                   Test_suite::assert_true(utl::is_numeric("0"), "Zero should be numeric");
                   Test_suite::assert_true(utl::is_numeric("123"), "Positive integer should be numeric");
                   Test_suite::assert_true(utl::is_numeric("+123"), "Positive integer with + sign should be numeric");
                 });

  // Negative integer tests
  suite.add_test("is_numeric negative integers",
                 []() { Test_suite::assert_true(utl::is_numeric("-123"), "Negative integer should be numeric"); });

  // Floating point tests
  suite.add_test("is_numeric floating point numbers",
                 []()
                 {
                   Test_suite::assert_true(utl::is_numeric("123.45"), "Positive float should be numeric");
                   Test_suite::assert_true(utl::is_numeric("-123.45"), "Negative float should be numeric");
                   Test_suite::assert_true(utl::is_numeric("0.123"), "Float less than 1 should be numeric");
                   Test_suite::assert_true(utl::is_numeric(".123"), "Float starting with decimal should be numeric");
                 });

  // Invalid numeric tests
  suite.add_test("is_numeric invalid inputs",
                 []()
                 {
                   // Empty and whitespace
                   Test_suite::assert_false(utl::is_numeric(""), "Empty string should not be numeric");
                   Test_suite::assert_false(utl::is_numeric(" "), "Whitespace should not be numeric");

                   // Multiple decimal points
                   Test_suite::assert_false(utl::is_numeric("123.45.67"), "Multiple decimal points should not be numeric");

                   // Non-numeric characters
                   Test_suite::assert_false(utl::is_numeric("123a45"), "String with letters should not be numeric");
                   Test_suite::assert_false(utl::is_numeric("12 34"), "String with spaces should not be numeric");

                   // Multiple signs
                   Test_suite::assert_false(utl::is_numeric("+-123"), "Multiple signs should not be numeric");
                   Test_suite::assert_false(utl::is_numeric("123-"), "Sign in wrong position should not be numeric");
                 });
}

void add_replace_all_tests(Test_suite &suite)
{
  // Basic replacement tests
  suite.add_test("replace_all basic replacements",
                 []()
                 {
                   // Simple single replacement
                   Test_suite::assert_equals(utl::replace_all("hello world", "world", "universe"),
                                             (std::string) "hello universe",
                                             "Should replace substring at end");

                   // Multiple replacements
                   Test_suite::assert_equals(
                       utl::replace_all("hello hello hello", "hello", "hi"), (std::string) "hi hi hi", "Should replace all occurrences");
                 });

  // Edge case replacements
  suite.add_test("replace_all edge cases",
                 []()
                 {
                   // Empty string cases
                   Test_suite::assert_equals(
                       utl::replace_all("", "test", "replace"), (std::string) "", "Replacing in empty string should return empty string");

                   // Replacing with empty string
                   Test_suite::assert_equals(utl::replace_all("hello world", "o", ""),
                                             (std::string) "hell wrld",
                                             "Replacing with empty string should remove characters");

                   // Substring not found
                   Test_suite::assert_equals(
                       utl::replace_all("hello world", "xyz", "abc"), (std::string) "hello world", "No replacement if substring not found");
                 });

  // Complex replacement scenarios
  suite.add_test("replace_all complex scenarios",
                 []()
                 {
                   // Overlapping replacements
                   Test_suite::assert_equals(
                       utl::replace_all("aaaaa", "aa", "b"), (std::string) "bba", "Handle overlapping replacement carefully");

                   // Case-sensitive replacement
                   Test_suite::assert_equals(
                       utl::replace_all("Hello HELLO hello", "hello", "hi"), (std::string) "Hello HELLO hi", "Should be case-sensitive");

                   // Replacement with longer string
                   Test_suite::assert_equals(utl::replace_all("quick quick", "quick", "very quick"),
                                             (std::string) "very quick very quick",
                                             "Replacement with longer string");
                 });
}

int main()
{
  Test_suite suite("String Utility Tests");

  add_trim(suite);

  add_trim_right_left(suite);

  add_lower_upper(suite);

  add_replace(suite);

  add_start_end_with(suite);

  add_join(suite);

  add_trim_till(suite);

  add_equal_ignorecase(suite);

  add_chop_by_delimiter(suite);

  add_remove_duplicates(suite);

  add_remove_duplicates_case_insensitive(suite);

  add_is_numeric_tests(suite);

  add_replace_all_tests(suite);

  suite.run_all_tests();

  suite.log_summary();

  std::cin.get();

  return 0;
}
