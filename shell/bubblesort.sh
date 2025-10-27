#!/bin/bash

read -p "enter elements of array separated by space: " -a arr
n=${#arr[@]}

for ((i = 0; i < n-1; i++)); do
    for ((j = 0; j < n-i-1; j++)); do
        if (( arr[j] > arr[j+1] )); then
            # swap arr[j] and arr[j+1]
            temp=${arr[j]}
            arr[j]=${arr[j+1]}
            arr[j+1]=$temp
        fi
    done
done
echo "Sorted array: ${arr[@]}"