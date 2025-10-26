#!/bin/bash

read -p "Enter the number of terms: " n
a=0
b=1

echo "Fibonacci sequence up to $n terms:"
for (( i=0; i<n; i++ )); do
    echo -n "$a "
    term=$((a + b))
    a=$b
    b=$term
done
echo