// Copyright 2018, loganstone

#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

double Median(std::vector<double> vec) {
  typedef std::vector<double>::size_type vec_sz;
  vec_sz size = vec.size();

  if (size == 0) {
    throw std::domain_error("median of an empty std::vector");
  }
  std::sort(vec.begin(), vec.end());
  vec_sz mid = size / 2;
  bool is_even = size % 2 == 0;
  return is_even ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

double Grade(double midterm, double final, double homework) {
  return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double Grade(double midterm, double final, const std::vector<double>& hw) {
  if (hw.size() == 0) {
    throw std::domain_error("student has done no homework");
  }
  return Grade(midterm, final, Median(hw));
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

  ReadHomework(std::cin, &homework);

  try {
    double final_grade = Grade(midterm, final, homework);
    std::streamsize prec = std::cout.precision();
    std::cout << "Your final grade is " << std::setprecision(3)
      << final_grade
      << std::setprecision(prec) << std::endl;
  } catch (std::domain_error) {
    std::cout << std::endl << "You must enter your grades. "
      "Please try again." << std::endl;
    return 1;
  }

  return 0;
}
