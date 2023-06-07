#!/bin/bash

g++ -std=c++17 brute.cpp -o brute
g++ -std=c++17 sol.cpp -o sol

python3 gen.py

./brute <input.in> brute.out
./sol <input.in> output.out

python3 checker.py