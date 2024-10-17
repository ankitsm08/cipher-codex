#include "polybiusSquare.h"

using namespace std;

// * Uses a 5x5 square, 'I' and 'J' have same value
// ! defaults to 'I' for both in case of decryption

string polybiusSquare::encrypt(const string& text) {
  string code = "";
  
  // ignores non-alphabetic characters
  for (char c : text) {
    if (isalpha(c)) {
      c = toupper(c);

      char row = (c - 'A') / 5;
      char column = (c - 'A') % 5;

      // Push each letter back once after 'I'
      if (c > 'I') {
        column--;
        if (column < 0) {
          column = 4;
          row--;
        }
      }

      code += '1' + row;
      code += '1' + column;

    } else if (isspace(c)) {
      code += c;
    }
  }

  return code;
}

string polybiusSquare::decrypt(const string& code) {
  string text = "";

  for (int i = 0; i < code.length();) {
    if (isdigit(code[i])) {
      char row = code[i] - '1';
      char column = code[i + 1] - '1';

      char c = 'A' + (row * 5) + column;

      // Discarding 'J', shift once to get other characters
      if (c >= 'J') {
        c++;
      }
      text += c;
      i += 2; // Two digits at a time

    } else if (isspace(code[i])) {
      text += code[i];
      i++;
    }
  }

  return text;
}

