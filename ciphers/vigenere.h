#include <string>

#ifndef VIGENERE_H
#define VIGENERE_H

namespace vigenere {
  std::string encrypt(const std::string& text, const std::string& keyword);
  std::string decrypt(const std::string& text, const std::string& keyword);
}

#endif // VIGENERE_H