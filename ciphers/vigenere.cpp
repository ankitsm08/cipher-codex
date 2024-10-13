#include "vigenere.h"

using namespace std;

string toLower(const string& s) {
  string lower = "";
  for (char c: s) {
    lower += tolower(c);
  }
  return lower;
}

string vigenere::encrypt(const string& text, const std::string& keyword) {
  string code = "";
  string key = toLower(keyword);
  
  for (int i = 0; i < text.length(); i++) {
    if (isalpha(text[i])) {
      char base = isupper(text[i]) ? 'A' : 'a';
      code += (text[i] + key[i % key.length()] - 'a' - base + 26) % 26 + base;
    } else {
      code += text[i];
    }
  }


  return code;
}

string vigenere::decrypt(const string& code, const std::string& keyword) {
  string text = "";
  string key = toLower(keyword);
  
  for (int i = 0; i < code.length(); i++) {
    if (isalpha(code[i])) {
      char base = isupper(code[i]) ? 'A' : 'a';
      text += (code[i] - key[i % key.length()] - 'a' - base + 26) % 26 + base;
    } else {
      text += code[i];
    }
  }

  return text;
}