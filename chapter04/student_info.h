// Copyright 2018, loganstone

#ifndef CHAPTER04_STUDENT_INFO_H_
#define CHAPTER04_STUDENT_INFO_H_

#include <iostream>
#include <string>
#include <vector>

struct StudentInfo {
  std::string name;
  double midterm;
  double final;
  std::vector<double> homework;
};

bool Compare(const StudentInfo&, const StudentInfo&);
std::istream& Read(std::istream&, StudentInfo*);
std::istream& ReadHomework(std::istream&, std::vector<double>*);

#endif  // CHAPTER04_STUDENT_INFO_H_
