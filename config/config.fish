abbr -a o xdg-open
abbr -a g git
abbr -a gah 'git stash; and git pull --rebase; and git stash pop'
abbr -a ls exa
abbr -a ll 'exa -la'

# Fish git prompt
set __fish_git_prompt_showuntrackedfiles yes
set __fish_git_prompt_showdirtystate yes
set __fish_git_prompt_showstashstate ''
set __fish_git_prompt_showupstream none
set -U __done_allow_nongraphical 1
set -U __done_notification_command "notify-send \$title \$message"
set -U __done_notify_sound 1
set -g fish_prompt_pwd_dir_length 3

set -gx CDPATH . ~ ~/dev ~/dev/mine ~/dev/others

function fish_prompt
    set_color green
    echo -n (date "+%H:%M")" "
    set_color grey
    printf $USER
    set_color brblack
    printf "@"
    set_color grey
    printf $hostname
    if [ $PWD != $HOME ]
        set_color brblack
        echo -n ':'
        set_color yellow
        echo -n (basename $PWD)
    end
    set_color green
    printf '%s ' (__fish_git_prompt)
    set_color yellow
    echo -n '> '
    set_color normal
end

function fish_greeting
    echo
    echo -e (uname -ro | awk '{print " \\\\e[1mOS: \\\\e[0;32m"$0"\\\\e[0m"}')
    echo -e (uptime -p | sed 's/^up //' | awk '{print " \\\\e[1mUptime: \\\\e[0;32m"$0"\\\\e[0m"}')
    echo

    echo -e " \\e[1mNetwork:\\e[0m"
    echo
    # http://tdt.rocks/linux_network_interface_naming.html
    echo -ne (\
		ip addr show up scope global | \
			grep -E ': <|inet' | \
			sed \
				-e 's/^[[:digit:]]\+: //' \
				-e 's/: <.*//' \
				-e 's/.*inet[[:digit:]]* //' \
				-e 's/\/.*//'| \
			awk 'BEGIN {i=""} /\.|:/ {print i" "$0"\\\n"; next} // {i = $0}' | \
			sort | \
			column -t -R1 | \
			# public addresses are underlined for visibility \
			sed 's/ \([^ ]\+\)$/ \\\e[4m\1/' | \
			# private addresses are not \
			sed 's/m\(\(10\.\|172\.\(1[6-9]\|2[0-9]\|3[01]\)\|192\.168\.\).*\)/m\\\e[24m\1/' | \
			# unknown interfaces are cyan \
			sed 's/^\( *[^ ]\+\)/\\\e[36m\1/' | \
			# ethernet interfaces are normal \
			sed 's/\(\(en\|em\|eth\)[^ ]* .*\)/\\\e[39m\1/' | \
			# wireless interfaces are purple \
			sed 's/\(wl[^ ]* .*\)/\\\e[35m\1/' | \
			# wwan interfaces are yellow \
			sed 's/\(ww[^ ]* .*\).*/\\\e[33m\1/' | \
			sed 's/$/\\\e[0m/' | \
			sed 's/^/\t/' \
		)
    echo

    set_color normal
end


function p
    fish -c "cd ~/dev && ls mine others"
end

function c
    code . && exit
end
