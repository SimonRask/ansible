#!/bin/bash
mode_path="$1"
if [ ! -f $mode_path ]; then
  echo "0" > $mode_path
fi
mode=$(cat "$mode_path")
# set mode to 1 if it os 0 and set mode to 0 if it is 1
mode=$((1 - $mode))
echo $mode > $mode_path

if [ $mode -eq 1 ]; then
  $2
else
  $3
fi

