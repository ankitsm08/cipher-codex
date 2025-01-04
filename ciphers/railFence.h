#include <string>

#ifndef RAIL_FENCE_H
#define RAIL_FENCE_H

namespace railFence {
  std::string encrypt(const std::string& text, const int key);
  std::string decrypt(const std::string& code, const int key);
}

#endif // RAIL_FENCE_H