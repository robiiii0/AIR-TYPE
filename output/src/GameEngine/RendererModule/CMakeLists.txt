cmake_minimum_required(VERSION 3.10)

project(Networking)

set(CMAKE_CXX_STANDARD 20)

include_directories(./)

find_package(SFML COMPONENTS system window  audio graphics CONFIG REQUIRED)

add_library(WindowModule
    WindowManager/Window.cpp
        Components/AnimationComponent/AnimationComponent.cpp)

if (APPLE)
        find_library(COREAUDIO_LIBRARY CoreAudio)
        find_library(AUDIOTOOLBOX_LIBRARY AudioToolbox)
        find_library(AUDIOUNIT_LIBRARY AudioUnit)
    
        target_link_libraries(WindowModule PRIVATE ${COREAUDIO_LIBRARY} ${AUDIOTOOLBOX_LIBRARY} ${AUDIOUNIT_LIBRARY})
    endif()


target_link_libraries(WindowModule PRIVATE sfml-system sfml-network sfml-graphics sfml-window sfml-audio)