// Copyright 2018, loganstone

#ifndef STUDENT_INFO_H_
#define STUDENT_INFO_H_

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

#endif
