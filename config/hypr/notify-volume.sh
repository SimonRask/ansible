#!/bin/bash
previd_path="/tmp/previous_volume_notification_id.txt"
if [ ! -f $previd_path ]; then
  echo "0" > $previd_path
fi
previd=$(cat "$previd_path")
muted=$(wpctl get-volume @DEFAULT_AUDIO_SINK@ | grep -Eo '\[.*\]')
muted=$(echo $muted | grep -Eo '[A-Z]+')
volume=$(wpctl get-volume @DEFAULT_AUDIO_SINK@ | grep -Eo '\.[0-9]+')
volume=$(echo $volume | grep -Eo '[0-9]+')
cent=$(wpctl get-volume @DEFAULT_AUDIO_SINK@ | grep -Eo '[0-9]+\.')
cent=$(echo $cent | grep -Eo '[0-9]+')
volume=$(echo $cent$volume)
volume=$(echo $volume | grep -Eo '[1-9][0-9]*|0$')

if [ -z "$muted" ]; then
  export makoid=$(notify-send "volume" "$volume%" --hint int:value:$volume -t 1000 --print-id --replace-id=$previd)
else
  export makoid=$(notify-send "volume" "<s>$volume%</s>" --hint int:value:$volume -t 1000 --print-id --replace-id=$previd)
fi

# notify-send -t 1000 "$previd"

echo $makoid > $previd_path
