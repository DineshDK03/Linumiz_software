#!/bin/bash

[ "$UID" -eq 0 ] || exec sudo "$0" "$@"

du -ha --apparent-size -a $1/ |grep -i .elf |sort -n
