// Copyright 2019, loganstone

#ifndef CHAPTER12_STR_H_
#define CHAPTER12_STR_H_

#include <algorithm>
#include <cstring>
#include <istream>
#include <iterator>
#include "vec.h"

class Str {
  friend std::istream& operator>>(std::istream&, Str&);

 public:
  Str& operator+=(const Str& s) {
    std::copy(s.data.Begin(), s.data.End(), std::back_inserter(data));
    return *this;
  }

  typedef Vec<char>::SizeType size_type;

  Str() {}
  Str(size_type n, char c) : data(n, c) {}

  Str(const char* cp) {
    std::copy(cp, cp + std::strlen(cp), std::back_inserter(data));
  }

  template <class In>
  Str(In b, In e) {
    std::copy(b, e, std::back_inserter(data));
  }

  char& operator[](size_type i) { return data[i]; }
  const char& operator[](size_type i) const { return data[i]; }

  size_type Size() const { return data.Size(); }

 private:
  Vec<char> data;
};

std::ostream& operator<<(std::ostream&, const Str&);
Str operator+(const Str&, const Str&);

std::istream& operator>>(std::istream& is, Str& s) {
  s.data.Clear();
  char c;
  while (is.get(c) && std::isspace(c)) {
  }

  if (is) {
    do {
      s.data.PushBack(c);
    } while (is.get(c) && !std::isspace(c));
    if (is) {
      is.unget();
    }
  }
  return is;
}

std::ostream& operator<<(std::ostream& os, const Str& s) {
  for (Str::size_type i = 0; i != s.Size(); ++i) {
    os << s[i];
  }
  return os;
}

Str operator+(const Str& s, const Str& t) {
  Str r = s;
  r += t;
  return r;
}

#endif  // CHAPTER12_STR_H_
