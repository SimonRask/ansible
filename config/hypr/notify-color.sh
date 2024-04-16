#!/bin/bash
color=$(hyprpicker --autocopy)
notify-send "COLOR" "Pasted $color to clipboard" -t 5000
