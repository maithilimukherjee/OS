#!/bin/bash

read -p "Enter elements (space separated): " -a arr
read -p "Enter position to delete (0-based index): " pos

unset arr[$pos]
# re-index the array
arr=("${arr[@]}")

echo "Array after deletion: ${arr[@]}"
