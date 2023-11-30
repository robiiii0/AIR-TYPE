cmake_minimum_required(VERSION 3.10)

project(Networking)

set(CMAKE_CXX_STANDARD 20)

# Add any additional libraries here
set(LIBS -lpthread)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/GameEngine/NetworkingModule)
set(CLIENT_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/Client)
set(SERVER_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/Server)
set(BUILD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${BUILD_DIR})

# NetworkingModule library
file(GLOB_RECURSE SRCS ${SRC_DIR}/*.cpp)
add_library(engine_networking ${SRCS})

# Client executable
file(GLOB_RECURSE CLIENT_SRCS ${CLIENT_SRC_DIR}/*.cpp)
add_executable(r-type_client ${CLIENT_SRCS})
target_link_libraries(r-type_client engine_networking ${LIBS})

# Server executable
file(GLOB_RECURSE SERVER_SRCS ${SERVER_SRC_DIR}/*.cpp)
add_executable(r-type_server ${SERVER_SRCS})
target_link_libraries(r-type_server engine_networking ${LIBS})

# Set output directory for executables
set(EXECUTABLE_OUTPUT_PATH ${BUILD_DIR})

# Move executables to parent directory
add_custom_command(TARGET r-type_client POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:r-type_client> ../)

add_custom_command(TARGET r-type_server POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:r-type_server> ../)
