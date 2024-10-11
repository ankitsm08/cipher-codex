#!/bin/bash
g++ test.cpp \
  ciphers/morse.cpp \
  ciphers/caesar.cpp \
  ciphers/rot13.cpp \
  -o test

./test
