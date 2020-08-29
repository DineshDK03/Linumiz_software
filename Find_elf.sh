#!/bin/bash

[ "$UID" -eq 0 ] || exec sudo "$0" "$@"

#du -ha --apparent-size -a $1/ | grep -i .elf |sort -n
#find $1 -type f -exec "file {} | grep -Pi ': elf (32|64)-bit' > /dev/null" \; -print
#find $1 -type f -exec du -ha --apparent-size {} \; | sort -n

ls -shSr $(find $1 -type f -exec sh -c "file {} | grep -Pi ': elf (32|64)-bit' > /dev/null " \; -print)

