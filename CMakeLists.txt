cmake_minimum_required(VERSION 3.10)

project(QCSF LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_subdirectory(quantum_simulation)
add_subdirectory(tests)

enable_testing()
