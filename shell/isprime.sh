#!/bin/bash

isPrime() {
    num=$1
    if (( num < 2 )); then
        echo "false"
        return
    fi

    for ((i=2; i*i<=num; i++)); do
        if (( num % i == 0 )); then
            echo "false"
            return
        fi
    done

    echo "true"
}

read -p "Enter the lower bound: " l
read -p "Enter the upper bound: " r

for ((i=l; i<=r; i++)); do
    if [[ $(isPrime $i) == "true" ]]; then
        echo "$i"
    
    fi
done
