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
include third_party/glfw/tests/CMakeFiles/tearing.dir/depend.make

# Include the progress variables for this target.
include third_party/glfw/tests/CMakeFiles/tearing.dir/progress.make

# Include the compile flags for this target's objects.
include third_party/glfw/tests/CMakeFiles/tearing.dir/flags.make

third_party/glfw/tests/CMakeFiles/tearing.dir/tearing.c.o: third_party/glfw/tests/CMakeFiles/tearing.dir/flags.make
third_party/glfw/tests/CMakeFiles/tearing.dir/tearing.c.o: third_party/glfw/tests/tearing.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eduardo/Desktop/BYOND/MYG.gg/MYG/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object third_party/glfw/tests/CMakeFiles/tearing.dir/tearing.c.o"
	cd /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tearing.dir/tearing.c.o   -c /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/tests/tearing.c

third_party/glfw/tests/CMakeFiles/tearing.dir/tearing.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tearing.dir/tearing.c.i"
	cd /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/tests/tearing.c > CMakeFiles/tearing.dir/tearing.c.i

third_party/glfw/tests/CMakeFiles/tearing.dir/tearing.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tearing.dir/tearing.c.s"
	cd /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/tests/tearing.c -o CMakeFiles/tearing.dir/tearing.c.s

third_party/glfw/tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.o: third_party/glfw/tests/CMakeFiles/tearing.dir/flags.make
third_party/glfw/tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.o: third_party/glfw/deps/glad_gl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eduardo/Desktop/BYOND/MYG.gg/MYG/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object third_party/glfw/tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.o"
	cd /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tearing.dir/__/deps/glad_gl.c.o   -c /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/deps/glad_gl.c

third_party/glfw/tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tearing.dir/__/deps/glad_gl.c.i"
	cd /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/deps/glad_gl.c > CMakeFiles/tearing.dir/__/deps/glad_gl.c.i

third_party/glfw/tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tearing.dir/__/deps/glad_gl.c.s"
	cd /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/deps/glad_gl.c -o CMakeFiles/tearing.dir/__/deps/glad_gl.c.s

# Object files for target tearing
tearing_OBJECTS = \
"CMakeFiles/tearing.dir/tearing.c.o" \
"CMakeFiles/tearing.dir/__/deps/glad_gl.c.o"

# External object files for target tearing
tearing_EXTERNAL_OBJECTS =

bin/tearing: third_party/glfw/tests/CMakeFiles/tearing.dir/tearing.c.o
bin/tearing: third_party/glfw/tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.o
bin/tearing: third_party/glfw/tests/CMakeFiles/tearing.dir/build.make
bin/tearing: third_party/glfw/src/libglfw3.a
bin/tearing: /usr/lib/x86_64-linux-gnu/libm.so
bin/tearing: /usr/lib/x86_64-linux-gnu/librt.so
bin/tearing: /usr/lib/x86_64-linux-gnu/libm.so
bin/tearing: /usr/lib/x86_64-linux-gnu/libX11.so
bin/tearing: third_party/glfw/tests/CMakeFiles/tearing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/eduardo/Desktop/BYOND/MYG.gg/MYG/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable ../../../bin/tearing"
	cd /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tearing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
third_party/glfw/tests/CMakeFiles/tearing.dir/build: bin/tearing

.PHONY : third_party/glfw/tests/CMakeFiles/tearing.dir/build

third_party/glfw/tests/CMakeFiles/tearing.dir/clean:
	cd /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/tests && $(CMAKE_COMMAND) -P CMakeFiles/tearing.dir/cmake_clean.cmake
.PHONY : third_party/glfw/tests/CMakeFiles/tearing.dir/clean

third_party/glfw/tests/CMakeFiles/tearing.dir/depend:
	cd /home/eduardo/Desktop/BYOND/MYG.gg/MYG && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/eduardo/Desktop/BYOND/MYG.gg/MYG /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/tests /home/eduardo/Desktop/BYOND/MYG.gg/MYG /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/tests /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/tests/CMakeFiles/tearing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : third_party/glfw/tests/CMakeFiles/tearing.dir/depend

