#include "rot13.h"

using namespace std;

string rot13::encrypt(const string& text) {
  string code = "";

  for (char c : text) {
    if (isalpha(c)) {
      char base = isupper(c) ? 'A' : 'a';
      code += (char) (((c - base + 13) % 26) + base);
    } else {
      code += c;
    }
  }

  return code;
}

string rot13::decrypt(const string& code) {
  string text = "";

  for (char c : text) {
    if (isalpha(c)) {
      char base = isupper(c) ? 'A' : 'a';
      text += (char) (((c - base - 13) % 26) + base);
    } else {
      text += c;
    }
  }

  return text;
}