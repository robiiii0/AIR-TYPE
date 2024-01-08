#!/bin/bash

print_blue() {
    echo -e "\033[34m$1\033[0m"
}

print_green() {
    echo -e "\033[32m$1\033[0m"
}

print_red() {
    echo -e "\033[31m$1\033[0m"
}

print_blue "Installing vcpkg..."
git clone https://github.com/Microsoft/vcpkg.git &

while [ ! -e "vcpkg/README.md" ]; do
    echo -n "."
    sleep 5
done

print_green "Download complete."

print_blue "Building vcpkg..."
./vcpkg/bootstrap-vcpkg.sh

if [ $? -eq 0 ]; then
    print_green "Building done!"
else
    print_red "Error during build!"
    exit 1
fi

print_blue "cd vcpkg/"
cd vcpkg/

print_blue "Installing sfml..."
./vcpkg install sfml

if [ $? -eq 0 ]; then
    print_green "SFML installed successfully."
else
    print_red "Error installing SFML!"
    exit 1
fi

./vcpkg integrate install
