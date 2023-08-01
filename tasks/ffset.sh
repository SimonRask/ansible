#!/bin/bash
# From https://askubuntu.com/questions/313483/how-do-i-change-firefoxs-aboutconfig-from-a-shell-script
sed -i 's/user_pref("'$1'",.*);/user_pref("'$1'",'$2');/' user.js
grep -q $1 user.js || echo "user_pref(\"$1\",$2);" >> user.js