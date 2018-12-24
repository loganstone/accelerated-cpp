// Copyright 2018, loganstone

#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

#include "grade.h"
#include "student_info.h"

int main() {
  std::vector<StudentInfo> students;
  StudentInfo record;

  std::string::size_type maxlen = 0;

  while (Read(std::cin, &record)) {
    maxlen = std::max(maxlen, record.name.size());
    students.push_back(record);
  }

  std::sort(students.begin(), students.end(), Compare);

  for (std::vector<StudentInfo>::size_type i = 0; i != students.size(); i++) {
    std::cout << students[i].name
      << std::string(maxlen + 1 - students[i].name.size(), ' ');
    try {
      double final_grage = Grade(students[i]);
      std::streamsize prec = std::cout.precision();
      std::cout << std::setprecision(3)
        << final_grage << std::setprecision(prec);
    } catch (std::domain_error e) {
      std::cout << e.what();
    }
    std::cout << std::endl;
  }
  return 0;
}
