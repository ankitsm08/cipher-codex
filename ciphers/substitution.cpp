#include "substitution.h"

using namespace std;

string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

bool isInKey(const string& key, char c) {
  return key.find(c) != string::npos;
}

// Generates a capitalised key 
string generateKey(const string& keyword) {
  string key = "";

  for (char c : keyword) {
    c = toupper(c);
    if (!isInKey(key, c)) {
      key += c;
    }
  }

  for (char c : alphabet) {
    if (!isInKey(key, c)) {
      key += c;
    }
  }

  return key;
}

string generateReverseKey(const string& keyword) {
  string key = generateKey(keyword);
  string reverseKey = alphabet;

  for (int i = 0; i < alphabet.length(); i++) {
    reverseKey[key[i] - 'A'] = alphabet[i];
  }

  return reverseKey;
}

string substitute(const string& text, const string& key) {
  string code = "";

  for (char c : text) {
    if (isalpha(c)) {
      char base = isupper(c) ? 'A' : 'a';
      // Subtract capital 'A' since key is capital
      code += key[c - base] - 'A' + base;
    } else {
      code += c;
    }
  }

  return code;
}

string substitution::encrypt(const string& text, const string& keyword) {
  return substitute(text, generateKey(keyword));
}

string substitution::decrypt(const string& code, const string& keyword) {
  return substitute(code, generateReverseKey(keyword));
}