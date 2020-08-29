#!/bin/bash

[ "$UID" -eq 0 ] || exec sudo "$0" "$@"

ls -shSr $(find $1 -type f -exec sh -c "file {} | grep -Pi ': elf (32|64)-bit' > /dev/null " \; -print)

