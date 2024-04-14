#!/bin/bash
gap_mult_path="$HOME/.config/hypr/gap_mult.txt"
if [ ! -f $gap_mult_path ]; then
  echo "0" > $gap_mult_path
fi
gap_mult=$(cat "$gap_mult_path")
gap_size=5
gap_mult=$(($gap_mult - 1))
if [ $gap_mult -lt 0 ]; then
  gap_mult=0
fi
gaps_in=$(($gap_size * $gap_mult))
gaps_out=$(($gap_size * $gap_mult * 2))
hyprctl keyword general:gaps_in $gaps_in
hyprctl keyword general:gaps_out $gaps_out
echo $gap_mult > $gap_mult_path
