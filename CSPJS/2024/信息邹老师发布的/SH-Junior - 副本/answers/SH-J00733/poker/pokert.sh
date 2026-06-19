#!/bin/bash

g++ poker.cpp -o poker

for i in {1..6}
do
    cp poker${i}.in poker.in
    ./poker
    diff poker${i}.out poker.out
done