# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lucas_rocha/ProjetosPessoais/PhotoBatch

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lucas_rocha/ProjetosPessoais/PhotoBatch

# Include any dependencies generated for this target.
include tests/CMakeFiles/TestArgumentParser.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/TestArgumentParser.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/TestArgumentParser.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/TestArgumentParser.dir/flags.make

tests/CMakeFiles/TestArgumentParser.dir/TestArgumentParser.cpp.o: tests/CMakeFiles/TestArgumentParser.dir/flags.make
tests/CMakeFiles/TestArgumentParser.dir/TestArgumentParser.cpp.o: tests/TestArgumentParser.cpp
tests/CMakeFiles/TestArgumentParser.dir/TestArgumentParser.cpp.o: tests/CMakeFiles/TestArgumentParser.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lucas_rocha/ProjetosPessoais/PhotoBatch/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/TestArgumentParser.dir/TestArgumentParser.cpp.o"
	cd /home/lucas_rocha/ProjetosPessoais/PhotoBatch/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/TestArgumentParser.dir/TestArgumentParser.cpp.o -MF CMakeFiles/TestArgumentParser.dir/TestArgumentParser.cpp.o.d -o CMakeFiles/TestArgumentParser.dir/TestArgumentParser.cpp.o -c /home/lucas_rocha/ProjetosPessoais/PhotoBatch/tests/TestArgumentParser.cpp

tests/CMakeFiles/TestArgumentParser.dir/TestArgumentParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestArgumentParser.dir/TestArgumentParser.cpp.i"
	cd /home/lucas_rocha/ProjetosPessoais/PhotoBatch/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lucas_rocha/ProjetosPessoais/PhotoBatch/tests/TestArgumentParser.cpp > CMakeFiles/TestArgumentParser.dir/TestArgumentParser.cpp.i

tests/CMakeFiles/TestArgumentParser.dir/TestArgumentParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestArgumentParser.dir/TestArgumentParser.cpp.s"
	cd /home/lucas_rocha/ProjetosPessoais/PhotoBatch/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lucas_rocha/ProjetosPessoais/PhotoBatch/tests/TestArgumentParser.cpp -o CMakeFiles/TestArgumentParser.dir/TestArgumentParser.cpp.s

tests/CMakeFiles/TestArgumentParser.dir/__/src/ArgumentParser.cpp.o: tests/CMakeFiles/TestArgumentParser.dir/flags.make
tests/CMakeFiles/TestArgumentParser.dir/__/src/ArgumentParser.cpp.o: src/ArgumentParser.cpp
tests/CMakeFiles/TestArgumentParser.dir/__/src/ArgumentParser.cpp.o: tests/CMakeFiles/TestArgumentParser.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lucas_rocha/ProjetosPessoais/PhotoBatch/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tests/CMakeFiles/TestArgumentParser.dir/__/src/ArgumentParser.cpp.o"
	cd /home/lucas_rocha/ProjetosPessoais/PhotoBatch/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/TestArgumentParser.dir/__/src/ArgumentParser.cpp.o -MF CMakeFiles/TestArgumentParser.dir/__/src/ArgumentParser.cpp.o.d -o CMakeFiles/TestArgumentParser.dir/__/src/ArgumentParser.cpp.o -c /home/lucas_rocha/ProjetosPessoais/PhotoBatch/src/ArgumentParser.cpp

tests/CMakeFiles/TestArgumentParser.dir/__/src/ArgumentParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestArgumentParser.dir/__/src/ArgumentParser.cpp.i"
	cd /home/lucas_rocha/ProjetosPessoais/PhotoBatch/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lucas_rocha/ProjetosPessoais/PhotoBatch/src/ArgumentParser.cpp > CMakeFiles/TestArgumentParser.dir/__/src/ArgumentParser.cpp.i

tests/CMakeFiles/TestArgumentParser.dir/__/src/ArgumentParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestArgumentParser.dir/__/src/ArgumentParser.cpp.s"
	cd /home/lucas_rocha/ProjetosPessoais/PhotoBatch/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lucas_rocha/ProjetosPessoais/PhotoBatch/src/ArgumentParser.cpp -o CMakeFiles/TestArgumentParser.dir/__/src/ArgumentParser.cpp.s

tests/CMakeFiles/TestArgumentParser.dir/__/src/utils.cpp.o: tests/CMakeFiles/TestArgumentParser.dir/flags.make
tests/CMakeFiles/TestArgumentParser.dir/__/src/utils.cpp.o: src/utils.cpp
tests/CMakeFiles/TestArgumentParser.dir/__/src/utils.cpp.o: tests/CMakeFiles/TestArgumentParser.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lucas_rocha/ProjetosPessoais/PhotoBatch/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object tests/CMakeFiles/TestArgumentParser.dir/__/src/utils.cpp.o"
	cd /home/lucas_rocha/ProjetosPessoais/PhotoBatch/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/TestArgumentParser.dir/__/src/utils.cpp.o -MF CMakeFiles/TestArgumentParser.dir/__/src/utils.cpp.o.d -o CMakeFiles/TestArgumentParser.dir/__/src/utils.cpp.o -c /home/lucas_rocha/ProjetosPessoais/PhotoBatch/src/utils.cpp

tests/CMakeFiles/TestArgumentParser.dir/__/src/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestArgumentParser.dir/__/src/utils.cpp.i"
	cd /home/lucas_rocha/ProjetosPessoais/PhotoBatch/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lucas_rocha/ProjetosPessoais/PhotoBatch/src/utils.cpp > CMakeFiles/TestArgumentParser.dir/__/src/utils.cpp.i

tests/CMakeFiles/TestArgumentParser.dir/__/src/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestArgumentParser.dir/__/src/utils.cpp.s"
	cd /home/lucas_rocha/ProjetosPessoais/PhotoBatch/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lucas_rocha/ProjetosPessoais/PhotoBatch/src/utils.cpp -o CMakeFiles/TestArgumentParser.dir/__/src/utils.cpp.s

# Object files for target TestArgumentParser
TestArgumentParser_OBJECTS = \
"CMakeFiles/TestArgumentParser.dir/TestArgumentParser.cpp.o" \
"CMakeFiles/TestArgumentParser.dir/__/src/ArgumentParser.cpp.o" \
"CMakeFiles/TestArgumentParser.dir/__/src/utils.cpp.o"

# External object files for target TestArgumentParser
TestArgumentParser_EXTERNAL_OBJECTS =

tests/TestArgumentParser: tests/CMakeFiles/TestArgumentParser.dir/TestArgumentParser.cpp.o
tests/TestArgumentParser: tests/CMakeFiles/TestArgumentParser.dir/__/src/ArgumentParser.cpp.o
tests/TestArgumentParser: tests/CMakeFiles/TestArgumentParser.dir/__/src/utils.cpp.o
tests/TestArgumentParser: tests/CMakeFiles/TestArgumentParser.dir/build.make
tests/TestArgumentParser: lib/libgtest_main.a
tests/TestArgumentParser: lib/libgtest.a
tests/TestArgumentParser: tests/CMakeFiles/TestArgumentParser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lucas_rocha/ProjetosPessoais/PhotoBatch/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable TestArgumentParser"
	cd /home/lucas_rocha/ProjetosPessoais/PhotoBatch/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestArgumentParser.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/TestArgumentParser.dir/build: tests/TestArgumentParser
.PHONY : tests/CMakeFiles/TestArgumentParser.dir/build

tests/CMakeFiles/TestArgumentParser.dir/clean:
	cd /home/lucas_rocha/ProjetosPessoais/PhotoBatch/tests && $(CMAKE_COMMAND) -P CMakeFiles/TestArgumentParser.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/TestArgumentParser.dir/clean

tests/CMakeFiles/TestArgumentParser.dir/depend:
	cd /home/lucas_rocha/ProjetosPessoais/PhotoBatch && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lucas_rocha/ProjetosPessoais/PhotoBatch /home/lucas_rocha/ProjetosPessoais/PhotoBatch/tests /home/lucas_rocha/ProjetosPessoais/PhotoBatch /home/lucas_rocha/ProjetosPessoais/PhotoBatch/tests /home/lucas_rocha/ProjetosPessoais/PhotoBatch/tests/CMakeFiles/TestArgumentParser.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/TestArgumentParser.dir/depend

