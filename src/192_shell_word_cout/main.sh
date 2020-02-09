#!/bin/bash

cat words.txt | xargs -n 1 | sort | uniq -c | sort -k1,1rn | awk -F " " '{print $2" "$1}'

