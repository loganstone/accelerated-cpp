// Copyright 2018, loganstone

#include <algorithm>
#include <cctype>
#include <string>
#include <vector>
#include "split.h"

bool IsSpace(const char c) { return std::isspace(c); }

bool IsNotSpace(const char c) { return !std::isspace(c); }

std::vector<std::string> Split(const std::string& s) {
  std::string::const_iterator i = s.begin();
  std::vector<std::string> ret;

  while (i != s.end()) {
    i = std::find_if(i, s.end(), IsNotSpace);

    std::string::const_iterator j = std::find_if(i, s.end(), IsSpace);

    if (i != s.end()) {
      ret.push_back(std::string(i, j));
    }
    i = j;
  }
  return ret;
}
