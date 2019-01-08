// Copyright 2018, loganstone

#ifndef CHAPTER04_GRADE_H_
#define CHAPTER04_GRADE_H_

#include <list>
#include <vector>
#include "student_info.h"

double Grade(double, double, double);
double Grade(double, double, const std::vector<double>&);
double Grade(const StudentInfo&);
bool IsFGrade(const StudentInfo&);
std::list<StudentInfo> ExtractFails(std::list<StudentInfo>);

#endif  // CHAPTER04_GRADE_H_
