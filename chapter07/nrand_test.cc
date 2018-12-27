// Copyright 2018, loganstone

#include <algorithm>
#include <ctime>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "nrand.h"

int main() {
  std::srand(static_cast<unsigned int>(std::time(0)));

  std::vector<int> v = {5, 7, 8, 16};
  std::vector<int>::const_iterator i;
  std::map<int, std::vector<int> > result;
  std::map<int, std::vector<int> >::const_iterator m_i;

  int cnt = 0;
  while (cnt != 50) {
    for (i = v.begin(); i != v.end(); ++i) {
      result[*i].push_back(GetNRand(*i));
    }
    cnt++;
  }

  for (m_i = result.begin(); m_i != result.end(); ++m_i) {
    std::ostringstream oss;

    std::copy(m_i->second.begin(),
              m_i->second.end() - 1,
              std::ostream_iterator<int>(oss, ", "));
    oss << m_i->second.back();
    std::cout << "n : " << m_i->first
              << ", GetNRand numbers : {" << oss.str() << "}" << std::endl;
  }
  return 0;
}
