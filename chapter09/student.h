// Copyright 2018, loganstone

#ifndef CHAPTER09_STUDENT_H_
#define CHAPTER09_STUDENT_H_

#include <iostream>
#include <string>
#include <vector>

#include "median.h"

class Student {
 public:
  Student();
  explicit Student(std::istream&);
  std::string Name() const { return n; }
  bool Valid() const { return !homework.empty(); }
  double Grade() const;
  std::istream& Read(std::istream&);

 private:
  std::string n;
  double midterm, final;
  std::vector<double> homework;
};

double Grade(double, double, double);
double Grade(double, double, const std::vector<double>&);
bool Compare(const Student&, const Student&);
std::istream& ReadHomework(std::istream&, std::vector<double>*);

Student::Student() : midterm(0), final(0) {}

Student::Student(std::istream& is) { Read(is); }

std::istream& Student::Read(std::istream& in) {
  in >> n >> midterm >> final;
  ReadHomework(in, &homework);
  return in;
}

double Student::Grade() const { return ::Grade(midterm, final, homework); }

double Grade(double midterm, double final, double homework) {
  return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double Grade(double midterm, double final, const std::vector<double>& hw) {
  if (hw.size() == 0) {
    throw std::domain_error("student has done no homework");
  }
  return Grade(midterm, final, Median(hw));
}

bool Compare(const Student& x, const Student& y) { return x.Name() < y.Name(); }

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

#endif  // CHAPTER09_STUDENT_H_
