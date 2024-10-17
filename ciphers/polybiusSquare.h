#include <string>

#ifndef POLYBIUS_SQUARE_H
#define POLYBIUS_SQUARE_H

namespace polybiusSquare {
  std::string encrypt(const std::string& text);
  std::string decrypt(const std::string& code);
}

#endif // POLYBIUS_SQUARE_H