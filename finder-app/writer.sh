#!/bin/bash

if [ -z "$1" ] || [ -z "$2" ]; then
  echo "Error: Both file path and text string must be provided."
  exit 1
fi

writefile="$1"
writestr="$2"


if [ ! -d $writefile ]
then 
    mkdir -p $(dirname "$writefile")
    echo "$writestr" > "$writefile"
else 
    echo "$writestr" > "$writestr"
fi 