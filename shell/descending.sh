#!/bin/bash

echo "enter numbers separated by space:"
read -a arr

echo "Numbers in descending order:"
echo "${arr[@]}" | tr ' ' '\n' | sort -nr

