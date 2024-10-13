#include "substitution.h"

using namespace std;

const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

bool isInKey(const unordered_set<char>& keySet, char c) {
  return keySet.find(c) != keySet.end();
}

// Generates a capitalised key 
string generateKey(const string& keyword) {
  string key = "";
  unordered_set<char> keySet;

  for (char c : keyword) {
    c = toupper(c);
    if (!isInKey(keySet, c)) {
      key += c;
      keySet.insert(c);
    }
  }

  for (char c : alphabet) {
    if (!isInKey(keySet, c)) {
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