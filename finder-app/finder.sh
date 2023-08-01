#!/bin/bash

if [ $# -ne 2 ]; then
    exit 1
fi 

if [ ! -d "$1" ]; then
    exit 1 
fi 

number_of_files=$(find "$1" -type f | wc -l)
number_of_files_with_target_string=$(grep -r "$2" "$1" | wc -l)

# echo $number_of_files
# echo $number_of_files_with_target_string
echo "The number of files are $number_of_files and the number of matching lines are $number_of_files_with_target_string"