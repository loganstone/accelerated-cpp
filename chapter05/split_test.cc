// Copyright 2018, loganstone

#include <iostream>
#include <string>
#include <vector>

#include "split.h"

int main() {
  std::string s = "string1 string2 string3";
  std::vector<std::string> v = Split(s);

  for (std::vector<std::string>::size_type i = 0; i != v.size(); i++) {
    std::cout << v[i] << std::endl;
  }
  return 0;
}
