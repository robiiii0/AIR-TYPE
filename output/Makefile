# Makefile for Networking project

CXX := g++
CXXFLAGS := -std=c++20 -Wall -Wextra
LIBS := -lpthread  # Add any additional libraries here

SRC_DIR := ./src/GameEngine/NetworkingModule
BUILD_DIR := build
TARGET := libengine_networking.a

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

.PHONY: all clean

all: $(BUILD_DIR) $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET): $(OBJS)
	ar rcs $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $@

clean:
	rm -rf $(BUILD_DIR)
