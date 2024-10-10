#include "morse.h"

using namespace std;

// ! The special characters for morse code are MADE-UP and
// ! in no way are they part of the standard morse code.

map<char, string> morseCodeMap = {
  // Uppercase Letters
  {'A', ".-"},    {'B', "-..."},  {'C', "-.-."},  {'D', "-.."},
  {'E', "."},     {'F', "..-."},  {'G', "--."},   {'H', "...."},
  {'I', ".."},    {'J', ".---"},  {'K', "-.-"},   {'L', ".-.."},
  {'M', "--"},    {'N', "-."},    {'O', "---"},   {'P', ".--."},
  {'Q', "--.-"},  {'R', ".-."},   {'S', "..."},   {'T', "-"},
  {'U', "..-"},   {'V', "...-"},  {'W', ".--"},   {'X', "-..-"},
  {'Y', "-.--"},  {'Z', "--.."}, 

  // Lowercase Letters (same as uppercase)
  {'a', ".-"},    {'b', "-..."},  {'c', "-.-."},  {'d', "-.."},
  {'e', "."},     {'f', "..-."},  {'g', "--."},   {'h', "...."},
  {'i', ".."},    {'j', ".---"},  {'k', "-.-"},   {'l', ".-.."},
  {'m', "--"},    {'n', "-."},    {'o', "---"},   {'p', ".--."},
  {'q', "--.-"},  {'r', ".-."},   {'s', "..."},   {'t', "-"},
  {'u', "..-"},   {'v', "...-"},  {'w', ".--"},   {'x', "-..-"},
  {'y', "-.--"},  {'z', "--.."},

  // Numbers
  {'0', "-----"}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"},
  {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."},
  {'8', "---.."}, {'9', "----."},

  // Punctuation and Symbols
  {'.', ".-.-.-"},   {',', "--..--"},  {'?', "..--.."},   {'\'', ".----."},
  {'!', "-.-.--"},   {'/', "-..-."},   {'(', "-.--."},    {')', "-.--.-"},
  {'&', ".-..."},    {':', "---..."},  {';', "-.-.-."},   {'=', "-...-"},
  {'+', ".-.-."},    {'-', "-....-"},  {'_', "..--.-"},   {'"', ".-..-."},
  {'$', "...-..-"},  {'@', ".--.-."},  {'#', "...-.-"},   {'%', "-----."},
  {'^', "-...-."},   {'|', "-.-.."},   {'~', ".--.--."},  {'`', ".----."},
  {'\\', ".-..-."},  {'[', "-.--."},   {']', "-.--.-"},   {'{', "-..--"},
  {'}', "--..-"},    {'<', "-.-.."},   {'>', "-.--.."},   {'*', "-.-.-"},
  {' ', "/"},        {'\n', ".-.-.."}
};

map<string, char> reverseMorseCodeMap = {
  // Uppercase Letters
  {".-", 'A'},    {"-...", 'B'},   {"-.-.", 'C'},   {"-..", 'D'},
  {".", 'E'},     {"..-.", 'F'},   {"--.", 'G'},    {"....", 'H'},
  {"..", 'I'},    {".---", 'J'},   {"-.-", 'K'},    {".-..", 'L'},
  {"--", 'M'},    {"-.", 'N'},      {"---", 'O'},    {".--.", 'P'},
  {"--.-", 'Q'},  {".-.", 'R'},     {"...", 'S'},     {"-", 'T'},
  {"..-", 'U'},   {"...-", 'V'},    {".--", 'W'},    {"-..-", 'X'},
  {"-.--", 'Y'},  {"--..", 'Z'},

  // Lowercase Letters (same as uppercase)
  {".-", 'a'},    {"-...", 'b'},   {"-.-.", 'c'},   {"-..", 'd'},
  {".", 'e'},     {"..-.", 'f'},   {"--.", 'g'},    {"....", 'h'},
  {"..", 'i'},    {".---", 'j'},   {"-.-", 'k'},    {".-..", 'l'},
  {"--", 'm'},    {"-.", 'n'},      {"---", 'o'},    {".--.", 'p'},
  {"--.-", 'q'},  {".-.", 'r'},     {"...", 's'},     {"-", 't'},
  {"..-", 'u'},   {"...-", 'v'},    {".--", 'w'},    {"-..-", 'x'},
  {"-.--", 'y'},  {"--..", 'z'},

  // Numbers
  {"-----", '0'}, {".----", '1'},  {"..---", '2'},  {"...--", '3'},
  {"....-", '4'}, {".....", '5'},   {"-....", '6'},  {"--...", '7'},
  {"---..", '8'}, {"----.", '9'},

  // Punctuation and Symbols
  {".-.-.-", '.'},   {"--..--", ','},  {"..--..", '?'},   {".----.", '\''},
  {"-.-.--", '!'},   {"-..-.", '/'},    {"-.--.", '('},    {"-.--.-", ')'},
  {".-...", '&'},    {"---...", ':'},   {"-.-.-.", ';'},   {"-...-", '='},
  {".-.-.", '+'},    {"-....-", '-'},   {"..--.-", '_'},   {".-..-.", '"'},
  {"...-..-", '$'},  {".--.-.", '@'},   {"...-.-", '#'},   {"-----.", '%'},
  {"-...-.", '^'},   {"-.-..", '|'},    {".--.--.", '~'},  {".----.", '`'},
  {".-..-.", '\\'},  {"-.--.", '['},     {"-.--.-", ']'},   {"-..--", '{'},
  {"--..-", '}'},    {"-.-..", '<'},    {"-.--..", '>'},   {"-.-.-", '*'},
  {" ", ' '},        {".-.-..", '\n'}
};

string morse::encrypt(const string& text) {
  string code = "";

  for (char c : text) {
    if (morseCodeMap.find(c) != morseCodeMap.end()) {
      code += morseCodeMap[c] + " ";
    } else if (c == ' ') {
      code += "/ ";
    } else continue;
  }

  return code;
}

string morse::decrypt(const string& code) {
  string text = "", token;

  stringstream ss(code);

  while (ss >> token) {
    if (reverseMorseCodeMap.find(token) != reverseMorseCodeMap.end()) {
      text += reverseMorseCodeMap[token];
    } else if (token == "/") {
      text += " ";
    } else continue;
  }

  return text;
}