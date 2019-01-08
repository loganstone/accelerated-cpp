// Copyright 2018, loganstone

#ifndef CHAPTER09_MEDIAN_H_
#define CHAPTER09_MEDIAN_H_

#include <algorithm>
#include <stdexcept>
#include <vector>

template <class T>
T Median(std::vector<T> vec) {
  typedef typename std::vector<T>::size_type vec_sz;
  vec_sz size = vec.size();

  if (size == 0) {
    throw std::domain_error("median of an empty std::vector");
  }
  std::sort(vec.begin(), vec.end());
  vec_sz mid = size / 2;
  bool is_even = size % 2 == 0;
  return is_even ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

#endif  // CHAPTER09_MEDIAN_H_
