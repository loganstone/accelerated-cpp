// Copyright 2018, loganstone

#ifndef SPLIT_H_
#define SPLIT_H_

#include <algorithm>
#include <string>
#include <vector>

typedef std::string::size_type str_size;
bool IsSpace(const char c) {
  return std::isspace(c);
}

bool IsNotSpace(const char c) {
  return !std::isspace(c);
}

template<class Out>
void Split(const std::string& s, Out os) {
  std::string::const_iterator i = s.begin();

  while (i != s.end()) {
    i = std::find_if(i, s.end(), IsNotSpace);

    std::string::const_iterator j = std::find_if(i, s.end(), IsSpace);

    if (i != s.end()) {
      *os++ = std::string(i, j);
    }
    i = j;
  }
}

#endif
