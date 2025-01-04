#include "railFence.h"

using namespace std;

// * Uses text length amount of space
string railFence::encrypt(const string& text, const int key) {
  if (key == 1) return text; // edge case

  string code(text.size(), ' ');

  for (int row = 0; row < key; row++) {
    bool movingDown = true;
    for (int col = row; col < text.length();) {
      code += text[col];

      int dist = movingDown ? 2*(key-row-1)-1 : 2*(row)-1;
      // dist is -ve => no direction change
      // Sum of distance traversed for up and down = 2*key-4
      col += (dist > 0 ? dist : (2*key-4 - dist)) + 1;
      movingDown = !movingDown; // Flip traverse direction
    }
  }

  return code;
}

string railFence::decrypt(const string& code, const int key) {
  string text(code.size(), ' ');

  int idx = 0;
  for (int row = 0; row < key; row++) {
    bool movingDown = true;
    for (int col = row; col < code.length();) {
      text[col] = code[idx++]; // Reverse the encryption

      int dist = movingDown ? 2*(key-row-1)-1 : 2*(row)-1;
      col += (dist > 0 ? dist : (2*key-4 - dist)) + 1;
      movingDown = !movingDown;
    }
  }

  return text;
}
