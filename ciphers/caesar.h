#include <string>

#ifndef CAESAR_H
#define CAESAR_H

namespace caesar {
  std::string encrypt(const std::string&, const int);
  std::string decrypt(const std::string&, const int);
}

#endif // CAESAR_H