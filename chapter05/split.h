// Copyright 2018, loganstone

#ifndef SPLIT_H_
#define SPLIT_H_

#include <string>
#include <vector>

typedef std::string::size_type str_size;
bool IsSpace(const char);
bool IsNotSpace(const char);
std::vector<std::string> Split(const std::string&);

#endif
