// Copyright 2018, loganstone

#include <iostream>
#include <string>
#include <vector>

#include "is_palindrome.h"

int main() {
  std::vector<std::string> v;
  v.push_back("civic");
  v.push_back("eye");
  v.push_back("level");
  v.push_back("madam");
  v.push_back("rotor");
  v.push_back("loganstone");  // false

  for (std::vector<std::string>::iterator i = v.begin(); i != v.end(); ++i) {
    std::cout << IsPalindrome(*i) << std::endl;
  }
  return 0;
}
