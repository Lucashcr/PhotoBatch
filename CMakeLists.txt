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

set(FETCHCONTENT_QUIET OFF CACHE BOOL "Desabilita o modo quiet do FetchContent" FORCE)
include(FetchContent)

add_subdirectory(tests)
add_subdirectory(externals)
