#!/bin/bash

read -p "enter first number: " a
read -p "enter second number: " b

while [ $b -ne 0 ]; do
    temp=$b
    b=$((a % b))
    a=$temp
done

echo "GCD is: $a"