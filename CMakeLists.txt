cmake_minimum_required(VERSION 3.10)
project(Compiler)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directory for header files
include_directories(include)

# Add executable
add_executable(MyCompiler src/main.cpp src/lexer.cpp src/parser.cpp src/token.cpp)

# Link libraries if you have any
# target_link_libraries(MyCompiler someLibrary)
