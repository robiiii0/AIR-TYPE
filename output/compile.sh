#!/bin/bash

CURRENT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

make -C "$CURRENT_DIR"

# Tests compilation
if [ "$?" -ne 0 ]; then
    echo "Client compilation failed"
    exit 1
fi

# Binary must be present
if [ ! -e "$CURRENT_DIR/pbrain-gomoku-ai" ]; then
  echo "Binary is missing"
  exit 1
fi

echo "Compilation succeeded"