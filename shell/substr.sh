#!/bin/bash

read -p "enter string: " str
read -p "enter substring: " substr

expr index "$str" "$substr"