#include <iostream>
#include "ciphers/simple/morse.h"
#include "ciphers/simple/caesar.h"

using namespace std;

int clamp(int value, int low, int high) {
  return (value < low) ? low : (value > high) ? high : value;
}

int main() {

  string input;
  string line;

  cout << endl << "Enter your paragraph (press Enter twice to finish):" << endl;

  getline(cin, line);
  input += line;
  
  // Loop until an empty line is entered
  while (true) {
      getline(cin, line);
      
      if (line.empty()) {
          break;
      }

      input += "\n" + line;
  }

  int choice;

  cout << "1. Morse Code" << endl;
  cout << "2. Caesar Cipher" << endl;
  cout << endl << "Choose algorithm: ";
  cin >> choice;

  int algorithm = clamp(choice, 1, 2);

  cout << endl;
  cout << "1. Encrypt (default)" << endl;
  cout << "2. Decrypt" << endl;
  cout << endl << "Choose operation: ";
  cin >> choice;
  cout << endl;

  bool enc = !(choice == 2);

  string result;

  switch (algorithm) {
    case 1: {

      if (enc) result = morse::encrypt(input);
      else result = morse::decrypt(input);

      break;
    }
    case 2: {

      int shift;
      cout << "Enter shift: ";
      cin >> shift;

      if (enc) result = caesar::encrypt(input, shift);
      else result = caesar::decrypt(input, shift);
      
      break;
    }

    default:
      cout << "Invalid algorithm" << endl;
  }

  cout << "Result: " << result << endl;

  return 0;
}
