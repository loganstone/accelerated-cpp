// Copyright 2018, loganstone

#include <list>
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

bool IsFGrade(const StudentInfo& student) {
  return Grade(student) < 60;
}

std::list<StudentInfo> ExtractFails(std::list<StudentInfo>* students) {
  std::list<StudentInfo> fail;
  std::list<StudentInfo>::iterator iter = students->begin();

  while (iter != students->end()) {
    if (IsFGrade(*iter)) {
      fail.push_back(*iter);
      iter = students->erase(iter);
    } else {
      ++iter;
    }
  }
  return fail;
}
