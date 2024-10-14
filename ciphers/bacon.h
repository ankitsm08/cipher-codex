#include <string>

#ifndef BACON_H
#define BACON_H

namespace bacon {
  std::string encrypt(const std::string& text, char c0, char c1);
  std::string decrypt(const std::string& code, char c0, char c1);
}

#endif // BACON_H