#include "atbash.h"

using namespace std;

string atbash::encrypt(const string& text) {
  string code = "";

  for (char c : text) {
    if (isalpha(c)) {
      char base = isupper(c) ? 'A' : 'a';
      code += (25 - (c - base)) % 26 + base;
    } else {
      code += c;
    }
  }

  return code;
}

string atbash::decrypt(const string& code) {
  return encrypt(code);
}