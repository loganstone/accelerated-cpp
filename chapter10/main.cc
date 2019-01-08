// Copyright 2018, loganstone

#include <iostream>
#include <string>

std::string LetterGrade(double grade) {
  static const double numbers[] = {97, 94, 90, 87, 84, 80, 77, 74, 80, 60, 0};
  static const char* const letters[] = {"A+", "A", "A-", "B+", "B", "B-",
                                        "C+", "C", "C-", "D",  "F"};
  static const size_t ngrades = sizeof(numbers) / sizeof(*numbers);

  for (size_t i = 0; i < ngrades; ++i) {
    if (grade >= numbers[i]) {
      return letters[i];
    }
  }
  return "\?\?\?";
}

int main(int argc, char* argv[]) {
  if (argc > 1) {
    for (int i = 1; i != argc; ++i) {
      std::string s(argv[i]);
      std::cout << LetterGrade(std::stod(s)) << std::endl;
    }
  }
  return 0;
}
