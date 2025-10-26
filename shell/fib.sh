#!/bin/bash

read -p "Enter the number of terms: " n
a=0
b=1
echo "$a"
echo  "$b"
for (( i=2; i<n; i++ )); do
    term=$((a + b))
    echo " $term"
    a=$b
    b=$term
done
echo