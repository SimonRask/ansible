#!/bin/bash
color=$(hyprpicker --autocopy)
notify-send "hyprpicker" "color pasted to clipboard: $color" -t 5000
