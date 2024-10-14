#include "bacon.h"

using namespace std;

string toBinary(unsigned char num, const char& c0, const char& c1) {
  string bin;
  while (num > 0) {
    bin = ((num % 2 == 0) ? c0 : c1) + bin;
    num /= 2;
  }
  while (bin.length() < 5) {
    bin = c0 + bin;
  }
  return bin;
}

// Uses bit-shifting for conversion
unsigned char toCharacter(const string& s, const char& c1) {
  char binary = 0;
  for (const char& c : s) {
    binary <<= 1; //  shift bits to left once, i.e. multiply by 2
    if (c == c1) binary |= 1; //  set last bit to 1
  }
  return (char)binary;
}

string bacon::encrypt(const string& text, char c0, char c1) {
  string code = "";
  c0 = toupper(c0); c1 = toupper(c1);

  for (const char& c : text) {
    if (isalpha(c)) {
      code += toBinary(toupper(c) - 'A', c0, c1);
    } else if (isspace(c)) {
      code += c;
    } //  ignore non-alphabetic chars
  }

  return code;
}

string bacon::decrypt(const string& code, char c0, char c1) {
  string text = "";
  c0 = toupper(c0); c1 = toupper(c1);

  for (int i = 0; i < code.length();) {
    if (code[i] == c0 || code[i] == c1) {
      text += 'A' + toCharacter(code.substr(i, 5), c1);
      i += 5; continue;
    } else if (isspace(code[i])) {
      text += code[i];
    }
    i++;
  }

  return text;
}