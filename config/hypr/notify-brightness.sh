#!/bin/bash
previd_path="/tmp/previous_brightness_notification_id.txt"
if [ ! -f $previd_path ]; then
  echo "0" > $previd_path
fi
previd=$(cat "$previd_path")

brightness=$(brightnessctl get)
brightness=$(echo "scale=2; $brightness * 100 / 255" | bc)
brightness=${brightness%.*}
if [ -z "$brightness" ]; then
  current_value=$(ddcutil getvcp 0x10 | grep -Eo 'current value = *[0-9]+')
  brightness=$(echo $current_value | grep -Eo '[0-9]+')
fi

if [ -z "$muted" ]; then
  export makoid=$(notify-send "BRIGHTNESS" "$brightness%" --hint int:value:$brightness -t 1000 --print-id --replace-id=$previd)
else
  export makoid=$(notify-send "BRIGHTNESS" "<s>$brightness%</s>" --hint int:value:$brightness -t 1000 --print-id --replace-id=$previd)
fi

# notify-send -t 1000 "$previd"

echo $makoid > $previd_path
