#!/bin/bash

T=10

if [[ "$1" == "-c" ]]; then
    g++ -std=c++20 brute.cpp -o brute
    g++ -std=c++20 sol.cpp -o sol
fi

for ((i = 0; i < $T; i++))
do
    python3 gen.py
    ./brute <input.in> brute.out
    ./sol <input.in> output.out

    python3 checker.py

    if [ $? != 0 ]
    then
        echo "[WA] on ${i}th test case."
        exit 1
    fi
done

echo "[OK] all $T test cases."