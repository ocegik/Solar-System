#!/bin/zsh
clang++ main.cpp -o solar-system \
  -I/opt/homebrew/include \
  -L/opt/homebrew/lib \
  -lsfml-graphics -lsfml-window -lsfml-system \
  -std=c++20
