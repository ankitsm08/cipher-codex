#include <string>

#ifndef ROT13_H
#define ROT13_H

namespace rot13 {
  std::string encrypt(const std::string& text);
  std::string decrypt(const std::string& text);
}

#endif // ROT13_H