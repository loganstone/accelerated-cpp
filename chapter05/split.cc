// Copyright 2018, loganstone

#include <cctype>
#include <string>
#include <vector>
#include "split.h"

std::vector<std::string>Split(const std::string& s) {
  std::vector<std::string> ret;
  str_size i = 0;

  while (i != s.size()) {
    while (i != s.size() && std::isspace(s[i])) {
      i++;
    }

    str_size j = i;

    while (j != s.size() && !std::isspace(s[j])) {
      j++;
    }

    if (i != j) {
      ret.push_back(s.substr(i, j - i));
      i = j;
    }
  }
  return ret;
}
