// Copyright 2018, loganstone

#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

#include "student.h"

int main() {
  std::vector<Student> students;
  Student record;

  std::string::size_type maxlen = 0;

  while (record.Read(std::cin)) {
    maxlen = std::max(maxlen, record.Name().size());
    students.push_back(record);
  }

  std::sort(students.begin(), students.end(), Compare);

  std::vector<Student>::const_iterator it;

  for (it = students.begin(); it != students.end(); ++it) {
    std::cout << (*it).Name()
              << std::string(maxlen + 1 - (*it).Name().size(), ' ');
    try {
      double final_grage = (*it).Grade();
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
