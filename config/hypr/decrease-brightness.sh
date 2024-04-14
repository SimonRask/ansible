#!/bin/bash
brightness_path="/tmp/current_brightness.txt"
if [ ! -f $brightness_path ]; then
  echo "0" > $brightness_path
fi
brightness=$(cat "$brightness_path")
new_brightness=$(($brightness - 20))
# check if new_brightness is less than 0
if [ $new_brightness -lt 0 ]; then
  new_brightness=0
fi
# current_value=$(ddcutil getvcp 0x10 | grep -Eo 'current value = *[0-9]+')
# brightness=$(echo $current_value | grep -Eo '[0-9]+')
ddcutil setvcp 0x10 $new_brightness
echo $new_brightness > $brightness_path
