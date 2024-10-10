#include <string>
#include <map>
#include <sstream>

#ifndef MORSE_H
#define MORSE_H

namespace morse {
  std::string encrypt(const std::string&);
  std::string decrypt(const std::string&);
}

#endif // MORSE_H