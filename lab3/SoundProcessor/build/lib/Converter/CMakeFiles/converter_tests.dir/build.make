# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_SOURCE_DIR = /home/bigcubecat/Projects/NSU/second_sem/22209-Bitochkin/lab3/SoundProcessor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bigcubecat/Projects/NSU/second_sem/22209-Bitochkin/lab3/SoundProcessor/build

# Include any dependencies generated for this target.
include lib/Converter/CMakeFiles/converter_tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lib/Converter/CMakeFiles/converter_tests.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/Converter/CMakeFiles/converter_tests.dir/progress.make

# Include the compile flags for this target's objects.
include lib/Converter/CMakeFiles/converter_tests.dir/flags.make

lib/Converter/CMakeFiles/converter_tests.dir/test/converter_tests.cpp.o: lib/Converter/CMakeFiles/converter_tests.dir/flags.make
lib/Converter/CMakeFiles/converter_tests.dir/test/converter_tests.cpp.o: /home/bigcubecat/Projects/NSU/second_sem/22209-Bitochkin/lab3/SoundProcessor/lib/Converter/test/converter_tests.cpp
lib/Converter/CMakeFiles/converter_tests.dir/test/converter_tests.cpp.o: lib/Converter/CMakeFiles/converter_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/bigcubecat/Projects/NSU/second_sem/22209-Bitochkin/lab3/SoundProcessor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/Converter/CMakeFiles/converter_tests.dir/test/converter_tests.cpp.o"
	cd /home/bigcubecat/Projects/NSU/second_sem/22209-Bitochkin/lab3/SoundProcessor/build/lib/Converter && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT lib/Converter/CMakeFiles/converter_tests.dir/test/converter_tests.cpp.o -MF CMakeFiles/converter_tests.dir/test/converter_tests.cpp.o.d -o CMakeFiles/converter_tests.dir/test/converter_tests.cpp.o -c /home/bigcubecat/Projects/NSU/second_sem/22209-Bitochkin/lab3/SoundProcessor/lib/Converter/test/converter_tests.cpp

lib/Converter/CMakeFiles/converter_tests.dir/test/converter_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/converter_tests.dir/test/converter_tests.cpp.i"
	cd /home/bigcubecat/Projects/NSU/second_sem/22209-Bitochkin/lab3/SoundProcessor/build/lib/Converter && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bigcubecat/Projects/NSU/second_sem/22209-Bitochkin/lab3/SoundProcessor/lib/Converter/test/converter_tests.cpp > CMakeFiles/converter_tests.dir/test/converter_tests.cpp.i

lib/Converter/CMakeFiles/converter_tests.dir/test/converter_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/converter_tests.dir/test/converter_tests.cpp.s"
	cd /home/bigcubecat/Projects/NSU/second_sem/22209-Bitochkin/lab3/SoundProcessor/build/lib/Converter && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bigcubecat/Projects/NSU/second_sem/22209-Bitochkin/lab3/SoundProcessor/lib/Converter/test/converter_tests.cpp -o CMakeFiles/converter_tests.dir/test/converter_tests.cpp.s

# Object files for target converter_tests
converter_tests_OBJECTS = \
"CMakeFiles/converter_tests.dir/test/converter_tests.cpp.o"

# External object files for target converter_tests
converter_tests_EXTERNAL_OBJECTS =

lib/Converter/converter_tests: lib/Converter/CMakeFiles/converter_tests.dir/test/converter_tests.cpp.o
lib/Converter/converter_tests: lib/Converter/CMakeFiles/converter_tests.dir/build.make
lib/Converter/converter_tests: lib/libgtest_main.a
lib/Converter/converter_tests: lib/Converter/libConverter.a
lib/Converter/converter_tests: lib/libgtest.a
lib/Converter/converter_tests: lib/WAV/libWAV.a
lib/Converter/converter_tests: lib/Converter/CMakeFiles/converter_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/bigcubecat/Projects/NSU/second_sem/22209-Bitochkin/lab3/SoundProcessor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable converter_tests"
	cd /home/bigcubecat/Projects/NSU/second_sem/22209-Bitochkin/lab3/SoundProcessor/build/lib/Converter && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/converter_tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/Converter/CMakeFiles/converter_tests.dir/build: lib/Converter/converter_tests
.PHONY : lib/Converter/CMakeFiles/converter_tests.dir/build

lib/Converter/CMakeFiles/converter_tests.dir/clean:
	cd /home/bigcubecat/Projects/NSU/second_sem/22209-Bitochkin/lab3/SoundProcessor/build/lib/Converter && $(CMAKE_COMMAND) -P CMakeFiles/converter_tests.dir/cmake_clean.cmake
.PHONY : lib/Converter/CMakeFiles/converter_tests.dir/clean

lib/Converter/CMakeFiles/converter_tests.dir/depend:
	cd /home/bigcubecat/Projects/NSU/second_sem/22209-Bitochkin/lab3/SoundProcessor/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bigcubecat/Projects/NSU/second_sem/22209-Bitochkin/lab3/SoundProcessor /home/bigcubecat/Projects/NSU/second_sem/22209-Bitochkin/lab3/SoundProcessor/lib/Converter /home/bigcubecat/Projects/NSU/second_sem/22209-Bitochkin/lab3/SoundProcessor/build /home/bigcubecat/Projects/NSU/second_sem/22209-Bitochkin/lab3/SoundProcessor/build/lib/Converter /home/bigcubecat/Projects/NSU/second_sem/22209-Bitochkin/lab3/SoundProcessor/build/lib/Converter/CMakeFiles/converter_tests.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : lib/Converter/CMakeFiles/converter_tests.dir/depend

