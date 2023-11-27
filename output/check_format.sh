#!/bin/bash

CURRENT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# Search for all files in the current directory and subdirectories
find "$CURRENT_DIR" \( -name '*.hpp' -o -name '*.cpp' \) > "$CURRENT_DIR/files_list.tmp"

# Then check if they are formatted properly
while IFS= read -r file; do
    if ! clang-format "$file" | diff "$file" -; then
        echo "File $file is not formatted properly"
        rm "$CURRENT_DIR/files_list.tmp"
        exit 1
    fi
done < "$CURRENT_DIR/files_list.tmp"

rm "$CURRENT_DIR/files_list.tmp"
echo "All C++ files are formatted properly"