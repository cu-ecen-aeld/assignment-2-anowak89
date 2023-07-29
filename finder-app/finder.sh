#!/bin/bash


# Check number of arguments.
if [ $# -ne 2 ]; then
    echo "Usage: $0 <filesdir> <searchstr>"
    exit 1
fi

# Assign arguments to variables.
filesdir="$1"
searchstr="$2"

# Check whether given directory exists.
if [ ! -d "$filesdir" ]; then
    echo "Error: '$filesdir' does not exists."
    exit 1
fi

# Count number of files in a given directory.
num_files=$(find "$filesdir" -type f | wc -l)


matching_lines=$(grep -r "$searchstr" | wc -l)


echo "The number of files are $num_files and the number of matching lines are $matching_lines."

exit 0
