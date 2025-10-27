#!/bin/bash

echo "Enter an array of numbers:"
read -a arr

min=${arr[0]}
max=${arr[0]}

for num in "${arr[@]}"; do
    if (( num < min )); then
        min=$num
    fi
    if (( num > max )); then
        max=$num
    fi
done

echo "Minimum value: $min"
echo "Maximum value: $max"