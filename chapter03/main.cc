// Copyright 2018, loganstone

#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::cout << "Plase enter your first name: ";

  std::string name;
  std::cin >> name;

  const std::string greeting = "Hello , " + name + "!";

  std::cout << "Plase enter your midterm and final exam grades: ";
  double midterm, final;
  std::cin >> midterm >> final;

  std::cout << "Enter all your homework grades, "
               "followed by end-of-file: ";

  std::vector<double> homework;

  double x;

  while (std::cin >> x) {
    homework.push_back(x);
  }

  typedef std::vector<double>::size_type vec_sz;
  vec_sz size = homework.size();

  if (size == 0) {
    std::cout << std::endl
              << "You must enter your grades. "
                 "Please try again."
              << std::endl;
    return 1;
  }

  std::sort(homework.begin(), homework.end());
  vec_sz mid = size / 2;
  bool is_even = size % 2 == 0;
  double median;
  if (is_even) {
    median = (homework[mid] + homework[mid - 1]) / 2;
  } else {
    median = homework[mid];
  }

  std::streamsize prec = std::cout.precision();
  std::cout << "Your final grade is " << std::setprecision(3)
            << 0.2 * midterm + 0.4 * final + 0.4 * median
            << std::setprecision(prec) << std::endl;
}
