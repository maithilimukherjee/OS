#!/bin/bash

while true; do :; done &
pid1=$!

while true; do :; done &
pid2=$!

echo "Started two infinite loops with PIDs: $pid1 and $pid2"
sleep 2
kill $pid1 $pid2
echo "Terminated both processes."
