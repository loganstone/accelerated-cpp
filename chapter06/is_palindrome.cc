// Copyright 2018, loganstone

#include <algorithm>

#include "is_palindrome.h"

bool IsPalindrome(const std::string& s) {
  return std::equal(s.begin(), s.end(), s.rbegin());
}
