// Copyright 2018, loganstone

#ifndef FRAME_H_
#define FRAME_H_

#include <string>
#include <vector>

typedef std::string::size_type str_size;
std::string::size_type GetMaxLen(const std::vector<std::string>&);
std::vector<std::string> Frame(const std::vector<std::string>&);
std::vector<std::string> Vcat(const std::vector<std::string>&,
                              const std::vector<std::string>&);
std::vector<std::string> Hcat(const std::vector<std::string>&,
                              const std::vector<std::string>&);

#endif
