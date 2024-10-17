#!/bin/bash
g++ test.cpp \
  ciphers/morse.cpp \
  ciphers/caesar.cpp \
  ciphers/rot13.cpp \
  ciphers/substitution.cpp \
  ciphers/vigenere.cpp \
  ciphers/atbash.cpp \
  ciphers/bacon.cpp \
  ciphers/polybiusSquare.cpp \
  -o test

./test
