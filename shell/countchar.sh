#!/bin/bash

read -p "enter text: " text

words=$(echo $text | wc -w)
chars=$(echo -n $text | wc -c)
echo "Number of words: $words"

spaces=$(echo -n "$text" | grep -o " " | wc -l)
echo "Number of spaces: $spaces"

special_chars=$(echo -n "$text" | grep -o "[^a-zA-Z0-9 ]" | wc -l)
echo "Number of special characters: $special_chars"

