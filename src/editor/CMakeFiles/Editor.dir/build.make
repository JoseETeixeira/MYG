# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/eduardo/Desktop/BYOND/MYG.gg/MYG

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/eduardo/Desktop/BYOND/MYG.gg/MYG

# Include any dependencies generated for this target.
include src/editor/CMakeFiles/Editor.dir/depend.make

# Include the progress variables for this target.
include src/editor/CMakeFiles/Editor.dir/progress.make

# Include the compile flags for this target's objects.
include src/editor/CMakeFiles/Editor.dir/flags.make

src/editor/CMakeFiles/Editor.dir/editor.cpp.o: src/editor/CMakeFiles/Editor.dir/flags.make
src/editor/CMakeFiles/Editor.dir/editor.cpp.o: src/editor/editor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eduardo/Desktop/BYOND/MYG.gg/MYG/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/editor/CMakeFiles/Editor.dir/editor.cpp.o"
	cd /home/eduardo/Desktop/BYOND/MYG.gg/MYG/src/editor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Editor.dir/editor.cpp.o -c /home/eduardo/Desktop/BYOND/MYG.gg/MYG/src/editor/editor.cpp

src/editor/CMakeFiles/Editor.dir/editor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Editor.dir/editor.cpp.i"
	cd /home/eduardo/Desktop/BYOND/MYG.gg/MYG/src/editor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eduardo/Desktop/BYOND/MYG.gg/MYG/src/editor/editor.cpp > CMakeFiles/Editor.dir/editor.cpp.i

src/editor/CMakeFiles/Editor.dir/editor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Editor.dir/editor.cpp.s"
	cd /home/eduardo/Desktop/BYOND/MYG.gg/MYG/src/editor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eduardo/Desktop/BYOND/MYG.gg/MYG/src/editor/editor.cpp -o CMakeFiles/Editor.dir/editor.cpp.s

# Object files for target Editor
Editor_OBJECTS = \
"CMakeFiles/Editor.dir/editor.cpp.o"

# External object files for target Editor
Editor_EXTERNAL_OBJECTS =

bin/Editor: src/editor/CMakeFiles/Editor.dir/editor.cpp.o
bin/Editor: src/editor/CMakeFiles/Editor.dir/build.make
bin/Editor: src/editor/CMakeFiles/Editor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/eduardo/Desktop/BYOND/MYG.gg/MYG/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/Editor"
	cd /home/eduardo/Desktop/BYOND/MYG.gg/MYG/src/editor && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Editor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/editor/CMakeFiles/Editor.dir/build: bin/Editor

.PHONY : src/editor/CMakeFiles/Editor.dir/build

src/editor/CMakeFiles/Editor.dir/clean:
	cd /home/eduardo/Desktop/BYOND/MYG.gg/MYG/src/editor && $(CMAKE_COMMAND) -P CMakeFiles/Editor.dir/cmake_clean.cmake
.PHONY : src/editor/CMakeFiles/Editor.dir/clean

src/editor/CMakeFiles/Editor.dir/depend:
	cd /home/eduardo/Desktop/BYOND/MYG.gg/MYG && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/eduardo/Desktop/BYOND/MYG.gg/MYG /home/eduardo/Desktop/BYOND/MYG.gg/MYG/src/editor /home/eduardo/Desktop/BYOND/MYG.gg/MYG /home/eduardo/Desktop/BYOND/MYG.gg/MYG/src/editor /home/eduardo/Desktop/BYOND/MYG.gg/MYG/src/editor/CMakeFiles/Editor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/editor/CMakeFiles/Editor.dir/depend

