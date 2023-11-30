#!/bin/bash

CURRENT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
echo "Current directory: $CURRENT_DIR"
make -C "$CURRENT_DIR"


# Binary must be present
if [ ! -e "$CURRENT_DIR/r-type_client" ]; then
  echo "Client binary is missing"
  exit 1
fi

if [ ! -e "$CURRENT_DIR/r-type_server" ]; then
  echo "Server binary is missing"
  exit 1
fi

echo "Compilation succeeded"