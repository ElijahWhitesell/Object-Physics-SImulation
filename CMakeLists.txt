cmake_minimum_required(VERSION 3.20)

project(PhysicsSandbox)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
)

FetchContent_MakeAvailable(SFML)

add_executable(PhysicsSandbox
    src/main.cpp
)

target_link_libraries(PhysicsSandbox PRIVATE
    SFML::Graphics
)
