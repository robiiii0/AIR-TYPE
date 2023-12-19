cmake_minimum_required(VERSION 3.10)

project(Networking)

set(CMAKE_CXX_STANDARD 20)

# Add any additional libraries here
set(LIBS pthread)

add_subdirectory(src/client)
add_subdirectory(src/Server)

# Call cmake in the src/client directory
execute_process(
        COMMAND ${CMAKE_COMMAND} ${CMAKE_SOURCE_DIR}/src/client
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/src/client
        RESULT_VARIABLE result
        COMMAND cp r-type_client ${CMAKE_SOURCE_DIR}
        COMMAND echo "done client"

)

if(result)
    message(FATAL_ERROR "CMake step for src/client failed: ${result}")
endif()

execute_process(
        COMMAND ${CMAKE_COMMAND} ${CMAKE_SOURCE_DIR}/src/Server
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/src/Server
        RESULT_VARIABLE result
        COMMAND cp r-type_server ${CMAKE_SOURCE_DIR}
        COMMAND echo "done serv"
)

if(result)
    message(FATAL_ERROR "CMake step for src/server failed: ${result}")
endif()




# You can add additional targets or commands here if needed
