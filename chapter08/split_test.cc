// Copyright 2018, loganstone

#include <iostream>
#include <iterator>
#include <string>

#include "split.h"

int main() {
  std::string s = "string1 string2 string3";
  std::vector<std::string> v;
  Split(s, std::back_inserter(v));

  for (std::vector<std::string>::size_type i = 0; i != v.size(); i++) {
    std::cout << v[i] << std::endl;
  }

  s = "string4 string5 string6";
  Split(s, std::ostream_iterator<std::string>(std::cout, "\n"));
  return 0;
}
