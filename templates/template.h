#include <string>

#ifndef TEMPLATE_H
#define TEMPLATE_H

namespace temp {
  std::string encrypt(const std::string& text);
  std::string decrypt(const std::string& code);
}

#endif // TEMPLATE_H