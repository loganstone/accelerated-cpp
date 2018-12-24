// Copyright 2018, loganstone

#include <iostream>
#include <vector>

#include "student_info.h"

bool Compare(const StudentInfo& x, const StudentInfo& y) {
  return x.name < y.name;
}

std::istream& Read(std::istream& is, StudentInfo* s) {
  is >> s->name >> s->midterm >> s->final;
  ReadHomework(is, &s->homework);
  return is;
}

std::istream& ReadHomework(std::istream& in, std::vector<double>* hw) {
  if (in) {
    hw->clear();

    double x;

    while (in >> x) {
      hw->push_back(x);
    }

    in.clear();
  }
  return in;
}
