#include <cstring>  // For memcpy
#include <iostream>

#include "./r_ena.hpp"

int main()
{
  utl::DR_ena dr_ena;
  int size = 10;

  // Allocate an array of 10 integers
  int *n = static_cast<int *>(dr_ena.allocate_raw(size * sizeof(int)));

  if (!n)
  {
    std::cerr << "[ERROR] Allocation failed!" << std::endl;
    return 1;
  }

  // Initialize the array with values
  int values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::memcpy(n, values, 10 * sizeof(int));  // Copy values into allocated memory

  for (int i{0}; i < size; i++) std::cout << n[i] << " ";
 
  std::cout << std::endl;

  char* str = static_cast<char*>(dr_ena.allocate_raw((strlen("Hello, World!") + 1) * sizeof(char)));
  std::memcpy(str, "Hello, World!", strlen("Hello, World!") + 1);

  std::cout << str << std::endl;

  return 0;
}
