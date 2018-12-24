// Copyright 2018, loganstone

#include <stdexcept>
#include <vector>

#include "grade.h"
#include "median.h"
#include "student_info.h"

double Grade(double midterm, double final, double homework) {
  return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double Grade(double midterm, double final, const std::vector<double>& hw) {
  if (hw.size() == 0) {
    throw std::domain_error("student has done no homework");
  }
  return Grade(midterm, final, Median(hw));
}

double Grade(const StudentInfo& s) {
  return Grade(s.midterm, s.final, s.homework);
}
