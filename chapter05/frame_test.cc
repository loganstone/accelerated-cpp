// Copyright 2018, loganstone

#include <iostream>
#include <string>
#include <vector>

#include "frame.h"
#include "split.h"

int main() {
  std::string s = "string1 string2 string3";
  std::vector<std::string> v = Split(s);
  std::vector<std::string> f = Frame(v);
  std::vector<std::string> h = Hcat(v, f);

  for (std::vector<std::string>::size_type i = 0; i != f.size(); i++) {
    std::cout << f[i] << std::endl;
  }

  for (std::vector<std::string>::size_type i = 0; i != h.size(); i++) {
    std::cout << h[i] << std::endl;
  }
  return 0;
}
