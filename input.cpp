#include "input.h"
#include <ios>
#include <iostream>
#include <string>
bool ReadLine(const std::string &prompt, std::string &LineOut) {
  std::cout << prompt;
  if (!std::getline(std::cin, LineOut)) return false;
  return true;
}