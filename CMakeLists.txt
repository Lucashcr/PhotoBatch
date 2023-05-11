cmake_minimum_required(VERSION 3.14)

project(PhotoBatch)

add_executable(PhotoBatch 
    "PhotoBatch.cpp"
    "src/ArgumentParser.h"
    "src/ArgumentParser.cpp"
    "src/Mode.h"
    "src/Mode.cpp"
    "src/RenameMode.h"
    "src/RenameMode.cpp"
    "src/utils.h"
    "src/utils.cpp"
)

set_target_properties(PhotoBatch PROPERTIES CXX_STANDARD 17)

add_subdirectory(tests)