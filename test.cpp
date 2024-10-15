#include "ciphers.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Function to read ciphers from file in order
vector<string> readCipherList(const string &filename) {
  vector<string> cipherList;
  ifstream file(filename);
  if (!file.is_open()) {
    cout << "Failed to open cipher list file." << endl;
    return cipherList;
  }

  string line;
  while (getline(file, line)) {
    cipherList.push_back(line); // Add each cipher name from file
  }
  file.close();
  return cipherList;
}

int clamp(int value, int low, int high) {
    return (value < low) ? low : (value > high) ? high : value;
}

int main() {
  string input;
  string line;

  cout << endl
       << "Enter your paragraph (press Enter twice to finish):" << endl;

  getline(cin, line);
  input += line;

  // Loop until an empty line is entered
  while (true) {
    getline(cin, line);
    if (line.empty()) break;
    input += "\n" + line;
  }

  // Load available ciphers from file
  vector<string> cipherList = readCipherList("ciphers.txt");

  if (cipherList.empty()) {
    cout << "No ciphers available." << endl;
    return 1;
  }

  // Display available ciphers in file order
  cout << "Available ciphers:" << endl;
  for (size_t i = 0; i < cipherList.size(); ++i) {
    cout << i + 1 << ". " << cipherList[i] << endl;
  }

  int choice;
  cout << endl << "Choose algorithm: ";
  cin >> choice;

  // Use the string from file to determine the cipher
  string selectedCipher = cipherList[choice - 1];
  
  // Clamp choice to the range of the cipher list size
  choice = clamp(choice, 1, cipherList.size());

  cout << endl;
  cout << "1. Encrypt (default)" << endl;
  cout << "2. Decrypt" << endl;
  cout << endl << "Choose operation: ";
  cin >> choice;
  cout << endl;

  bool enc = !(choice == 2);

  string result;

  if (selectedCipher == "Morse Code") {

    if (enc) result = morse::encrypt(input);
    else result = morse::decrypt(input);

  } else if (selectedCipher == "Caesar Cipher") {

    int shift;
    cout << "Enter shift: ";
    cin >> shift;

    if (enc) result = caesar::encrypt(input, shift);
    else result = caesar::decrypt(input, shift);

  } else if (selectedCipher == "ROT13 Cipher"){

    if (enc) result = rot13::encrypt(input);
    else result = rot13::decrypt(input);

  } else if (selectedCipher == "Substitution Cipher"){

    string keyword;
    cout << "Enter keyword: ";
    cin >> keyword;

    if (enc) result = substitution::encrypt(input, keyword);
    else result = substitution::decrypt(input, keyword);

  } else if (selectedCipher == "Vigenere Cipher"){

    string keyword;
    cout << "Enter keyword: ";
    cin >> keyword;

    if (enc) result = vigenere::encrypt(input, keyword);
    else result = vigenere::decrypt(input, keyword);

  } else if (selectedCipher == "Atbash Cipher"){

    if (enc) result = atbash::encrypt(input);
    else result = atbash::decrypt(input);

  } else if (selectedCipher == "Bacon Cipher"){

    char c0, c1;
    cout << "Enter binary digits (char): ";
    cin >> c0 >> c1; 

    if (enc) result = bacon::encrypt(input, c0, c1);
    else result = bacon::decrypt(input, c0, c1);

  } else {
    cout << "Unknown cipher: " << selectedCipher << endl;
  }

  cout << endl << "Result: " << result << endl << endl;

  return 0;
}
