cmake_minimum_required(VERSION 3.10)

project(Networking)

set(CMAKE_CXX_STANDARD 20)

# Add any additional libraries here
set(LIBS pthread)

add_subdirectory(src/Client)
add_subdirectory(src/Server)

# Call cmake in the src/client directory
execute_process(
        COMMAND ${CMAKE_COMMAND} ${CMAKE_SOURCE_DIR}/src/Client
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/src/Client
        RESULT_VARIABLE result
)

if(result)
    message(FATAL_ERROR "CMake step for src/Client failed: ${result}")
endif()

execute_process(
        COMMAND ${CMAKE_COMMAND} ${CMAKE_SOURCE_DIR}/src/Server
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/src/Server
        RESULT_VARIABLE result
)

if(result)
    message(FATAL_ERROR "CMake step for src/server failed: ${result}")
endif()

