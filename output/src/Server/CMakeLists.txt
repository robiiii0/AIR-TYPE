cmake_minimum_required(VERSION 3.10)

project(r-type_server)

set(CMAKE_CXX_STANDARD 20)

set(LIBS -lpthread)

# Specify the source file
set(SERVER_SRC ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

# Create the executable for the server with only main.cpp
add_executable(r-type_server ${SERVER_SRC})

# Link libraries if needed
target_link_libraries(r-type_server ${LIBS})
