// Copyright 2018, loganstone

#include <iostream>
#include <stdexcept>

#include "nrand.h"

int GetNRand(int n) {
  if (n <= 0 || n > RAND_MAX) {
    throw std::domain_error("argument to NRand is out of range");
  }

  const int bucket_size = RAND_MAX / n;
  int r;
  do {
    r = std::rand() / bucket_size;
  } while (r >= n);

  return r;
}
