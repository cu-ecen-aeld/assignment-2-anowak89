#!/bin/bash


# Check number of arguments.
if [ $# -ne 2 ]; then
    echo "Usage: $0 <writefile> <writestr>"
    exit 1
fi

# Assign arguments to variables.
writefile="$1"
writestr="$2"

# Create a directory and a file.
mkdir -p "$(dirname "$1")" && touch "$1"

# Check the last operation result.
if [ $? -ne 0 ]; then
    echo "Error: cannot create the file."
	exit 1
fi

echo "$writestr" > "$writefile"

exit 0
