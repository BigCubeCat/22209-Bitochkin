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
include CMakeFiles/SoundProcessor.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SoundProcessor.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SoundProcessor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SoundProcessor.dir/flags.make

CMakeFiles/SoundProcessor.dir/src/main.cpp.o: CMakeFiles/SoundProcessor.dir/flags.make
CMakeFiles/SoundProcessor.dir/src/main.cpp.o: /home/bigcubecat/Projects/NSU/second_sem/22209-Bitochkin/lab3/SoundProcessor/src/main.cpp
CMakeFiles/SoundProcessor.dir/src/main.cpp.o: CMakeFiles/SoundProcessor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/bigcubecat/Projects/NSU/second_sem/22209-Bitochkin/lab3/SoundProcessor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SoundProcessor.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SoundProcessor.dir/src/main.cpp.o -MF CMakeFiles/SoundProcessor.dir/src/main.cpp.o.d -o CMakeFiles/SoundProcessor.dir/src/main.cpp.o -c /home/bigcubecat/Projects/NSU/second_sem/22209-Bitochkin/lab3/SoundProcessor/src/main.cpp

CMakeFiles/SoundProcessor.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SoundProcessor.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bigcubecat/Projects/NSU/second_sem/22209-Bitochkin/lab3/SoundProcessor/src/main.cpp > CMakeFiles/SoundProcessor.dir/src/main.cpp.i

CMakeFiles/SoundProcessor.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SoundProcessor.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bigcubecat/Projects/NSU/second_sem/22209-Bitochkin/lab3/SoundProcessor/src/main.cpp -o CMakeFiles/SoundProcessor.dir/src/main.cpp.s

CMakeFiles/SoundProcessor.dir/src/Processor/Processor.cpp.o: CMakeFiles/SoundProcessor.dir/flags.make
CMakeFiles/SoundProcessor.dir/src/Processor/Processor.cpp.o: /home/bigcubecat/Projects/NSU/second_sem/22209-Bitochkin/lab3/SoundProcessor/src/Processor/Processor.cpp
CMakeFiles/SoundProcessor.dir/src/Processor/Processor.cpp.o: CMakeFiles/SoundProcessor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/bigcubecat/Projects/NSU/second_sem/22209-Bitochkin/lab3/SoundProcessor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SoundProcessor.dir/src/Processor/Processor.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SoundProcessor.dir/src/Processor/Processor.cpp.o -MF CMakeFiles/SoundProcessor.dir/src/Processor/Processor.cpp.o.d -o CMakeFiles/SoundProcessor.dir/src/Processor/Processor.cpp.o -c /home/bigcubecat/Projects/NSU/second_sem/22209-Bitochkin/lab3/SoundProcessor/src/Processor/Processor.cpp

CMakeFiles/SoundProcessor.dir/src/Processor/Processor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SoundProcessor.dir/src/Processor/Processor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bigcubecat/Projects/NSU/second_sem/22209-Bitochkin/lab3/SoundProcessor/src/Processor/Processor.cpp > CMakeFiles/SoundProcessor.dir/src/Processor/Processor.cpp.i

CMakeFiles/SoundProcessor.dir/src/Processor/Processor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SoundProcessor.dir/src/Processor/Processor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bigcubecat/Projects/NSU/second_sem/22209-Bitochkin/lab3/SoundProcessor/src/Processor/Processor.cpp -o CMakeFiles/SoundProcessor.dir/src/Processor/Processor.cpp.s

# Object files for target SoundProcessor
SoundProcessor_OBJECTS = \
"CMakeFiles/SoundProcessor.dir/src/main.cpp.o" \
"CMakeFiles/SoundProcessor.dir/src/Processor/Processor.cpp.o"

# External object files for target SoundProcessor
SoundProcessor_EXTERNAL_OBJECTS =

SoundProcessor: CMakeFiles/SoundProcessor.dir/src/main.cpp.o
SoundProcessor: CMakeFiles/SoundProcessor.dir/src/Processor/Processor.cpp.o
SoundProcessor: CMakeFiles/SoundProcessor.dir/build.make
SoundProcessor: lib/WAV/libWAV.a
SoundProcessor: lib/Configurator/libConfigurator.a
SoundProcessor: lib/ArgParser/libArgParser.a
SoundProcessor: lib/Converter/libConverter.a
SoundProcessor: lib/WAV/libWAV.a
SoundProcessor: CMakeFiles/SoundProcessor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/bigcubecat/Projects/NSU/second_sem/22209-Bitochkin/lab3/SoundProcessor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable SoundProcessor"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SoundProcessor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SoundProcessor.dir/build: SoundProcessor
.PHONY : CMakeFiles/SoundProcessor.dir/build

CMakeFiles/SoundProcessor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SoundProcessor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SoundProcessor.dir/clean

CMakeFiles/SoundProcessor.dir/depend:
	cd /home/bigcubecat/Projects/NSU/second_sem/22209-Bitochkin/lab3/SoundProcessor/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bigcubecat/Projects/NSU/second_sem/22209-Bitochkin/lab3/SoundProcessor /home/bigcubecat/Projects/NSU/second_sem/22209-Bitochkin/lab3/SoundProcessor /home/bigcubecat/Projects/NSU/second_sem/22209-Bitochkin/lab3/SoundProcessor/build /home/bigcubecat/Projects/NSU/second_sem/22209-Bitochkin/lab3/SoundProcessor/build /home/bigcubecat/Projects/NSU/second_sem/22209-Bitochkin/lab3/SoundProcessor/build/CMakeFiles/SoundProcessor.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/SoundProcessor.dir/depend

