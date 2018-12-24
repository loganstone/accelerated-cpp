// Copyright 2018, loganstone

#ifndef GRADE_H_
#define GRADE_H_

#include <vector>
#include "student_info.h"

double Grade(double, double, double);
double Grade(double, double, const std::vector<double>&);
double Grade(const StudentInfo&);

#endif
