cmake_minimum_required(VERSION 3.14)

project(PhotoBatch)

add_executable(PhotoBatch 
    "src/PhotoBatch.cpp"
    "src/ArgumentParser.cpp"
    "src/utils.cpp"
    
    "src/Modes/Mode.cpp"
    "src/Modes/RenameMode.cpp"
)

set_target_properties(PhotoBatch PROPERTIES CXX_STANDARD 17)

add_subdirectory(tests)