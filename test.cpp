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
  string inputString;
  string line;

  cout << endl
       << "Enter your paragraph (press Enter twice to finish):" << endl;

  getline(cin, line);
  inputString += line;

  // Loop until an empty line is entered
  while (true) {
    getline(cin, line);
    if (line.empty()) break;
    inputString += "\n" + line;
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

  bool to_encrypt = !(choice == 2);

  string result;

  result = cipher(selectedCipher, to_encrypt, inputString);

  cout << endl << "Result: " << result << endl << endl;

  return 0;
}

string cipher(const string& cipherType, bool enc, const string& input) {

  if (cipherType == "Morse Code") {

    return (enc) ? morse::encrypt(input) : morse::decrypt(input);

  } else if (cipherType == "Caesar Cipher") {

    int shift;
    cout << "Enter shift: ";
    cin >> shift;

    return (enc) ? caesar::encrypt(input, shift) : caesar::decrypt(input, shift);

  } else if (cipherType == "ROT13 Cipher") {

    return (enc) ? rot13::encrypt(input) : rot13::decrypt(input);

  } else if (cipherType == "Substitution Cipher") {

    string keyword;
    cout << "Enter keyword: ";
    cin >> keyword;

    return (enc) ? substitution::encrypt(input, keyword) : substitution::decrypt(input, keyword);

  } else if (cipherType == "Vigenere Cipher") {

    string keyword;
    cout << "Enter keyword: ";
    cin >> keyword;

    return (enc) ? vigenere::encrypt(input, keyword) : vigenere::decrypt(input, keyword);

  } else if (cipherType == "Atbash Cipher") {

    return (enc) ? atbash::encrypt(input) : atbash::decrypt(input);

  } else if (cipherType == "Bacon Cipher") {

    char c0, c1;
    cout << "Enter binary digits (char): ";
    cin >> c0 >> c1; 

    return (enc) ? bacon::encrypt(input, c0, c1) : bacon::decrypt(input, c0, c1);

  } else if (cipherType == "Polybius-Square Cipher") {

    return (enc) ? polybiusSquare::encrypt(input) : polybiusSquare::decrypt(input);

  }  else {
    cout << "Unknown cipher: " << cipherType << endl;
    return "Nan";
  }
}