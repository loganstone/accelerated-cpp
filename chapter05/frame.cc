// Copyright 2018, loganstone

#include <algorithm>
#include <cctype>
#include <string>
#include <vector>

#include "frame.h"
#include "split.h"

std::string::size_type GetMaxLen(const std::vector<std::string>& v) {
  std::string::size_type maxlen = 0;
  for (std::vector<std::string>::size_type i = 0; i != v.size(); i++) {
    maxlen = std::max(maxlen, v[i].size());
  }
  return maxlen;
}

std::vector<std::string> Frame(const std::vector<std::string>& v) {
  std::vector<std::string> ret;

  std::string::size_type maxlen = GetMaxLen(v);
  std::string border(maxlen + 4, '*');

  ret.push_back(border);

  for (std::vector<std::string>::size_type i = 0; i != v.size(); i++) {
    std::string margin_for_maxlen = std::string(maxlen - v[i].size(), ' ');
    ret.push_back("* " + v[i] + margin_for_maxlen + " *");
  }

  ret.push_back(border);
  return ret;
}

std::vector<std::string> Vcat(const std::vector<std::string>& top,
                              const std::vector<std::string>& bottom) {
  std::vector<std::string> ret = top;
  /*
  for (std::vector<std::string>::const_iterator it = bottom.begin();
       it != bottom.end(); it++) {
    ret.push_back(*it);
  }
  */
  ret.insert(ret.end(), bottom.begin(), bottom.end());
  return ret;
}

std::vector<std::string> Hcat(const std::vector<std::string>& left,
                              const std::vector<std::string>& right) {
  std::vector<std::string> ret;
  std::string::size_type divide_str_position = GetMaxLen(left) + 1;
  std::vector<std::string>::size_type i = 0, j = 0;
  while (i != left.size() || j != right.size()) {
    std::string s;

    if (i != left.size()) {
      s = left[i++];
    }

    s += std::string(divide_str_position - s.size(), ' ');


    if (j != right.size()) {
      s += right[j++];
    }

    ret.push_back(s);
  }
  return ret;
}
