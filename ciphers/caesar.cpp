#include "caesar.h"

using namespace std;

string caesar::encrypt(const string& text, const int shift) {
  string code = "";

  for (char c : text) {
    if (isalpha(c)) {
      char base = isupper(c) ? 'A' : 'a';
      code += (char) (((c - base + shift) % 26) + base);
    } else {
      code += c;
    }
  }

  return code;
}

string caesar::decrypt(const string& code, const int shift) {
  string text = "";

  for (char c : text) {
    if (isalpha(c)) {
      char base = isupper(c) ? 'A' : 'a';
      text += (char) (((c - base - shift) % 26) + base);
    } else {
      text += c;
    }
  }
  
  return text;
}