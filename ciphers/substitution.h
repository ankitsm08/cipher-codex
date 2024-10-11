#include <string>
#include <unordered_map>

#ifndef SUBSTITUTION_H
#define SUBSTITUTION_H

namespace substitution {
  std::string encrypt(const std::string& text, const std::string& key);
  std::string decrypt(const std::string& text, const std::string& key);
}

#endif // SUBSTITUTION_H