#include <string>

#ifndef ATBASH_H
#define ATBASH_H

namespace atbash {
  std::string encrypt(const std::string& text);
  std::string decrypt(const std::string& text);
}

#endif // ATBASH_H