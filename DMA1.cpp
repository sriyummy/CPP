// Dynamically allocate an integer, a character and a string and assign a value to them

#include <iostream>
#include <string>

int main()
{
  int* dynamicInt = new int;
  * dynamicInt = 20;

  char* dynamicChar = new char;
  * dynamicChar = 'C';

  // Dynamically allocate a string
  std::string * dynamicString = new std::string;
  * dynamicString = "C++ Dynamically allocated string.";

  // Display the values
  std::cout << "Dynamically allocated integer: " << * dynamicInt << std::endl;
  std::cout << "Dynamically allocated character: " << * dynamicChar << std::endl;
  std::cout << "Dynamically allocated string: " << * dynamicString << std::endl;

  // Deallocate the memory
  delete dynamicInt;
  delete dynamicChar;
  delete dynamicString;

  return 0;
}
