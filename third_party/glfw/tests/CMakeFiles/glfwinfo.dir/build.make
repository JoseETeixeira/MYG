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
include third_party/glfw/tests/CMakeFiles/glfwinfo.dir/depend.make

# Include the progress variables for this target.
include third_party/glfw/tests/CMakeFiles/glfwinfo.dir/progress.make

# Include the compile flags for this target's objects.
include third_party/glfw/tests/CMakeFiles/glfwinfo.dir/flags.make

third_party/glfw/tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o: third_party/glfw/tests/CMakeFiles/glfwinfo.dir/flags.make
third_party/glfw/tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o: third_party/glfw/tests/glfwinfo.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eduardo/Desktop/BYOND/MYG.gg/MYG/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object third_party/glfw/tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o"
	cd /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfwinfo.dir/glfwinfo.c.o   -c /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/tests/glfwinfo.c

third_party/glfw/tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfwinfo.dir/glfwinfo.c.i"
	cd /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/tests/glfwinfo.c > CMakeFiles/glfwinfo.dir/glfwinfo.c.i

third_party/glfw/tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfwinfo.dir/glfwinfo.c.s"
	cd /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/tests/glfwinfo.c -o CMakeFiles/glfwinfo.dir/glfwinfo.c.s

third_party/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o: third_party/glfw/tests/CMakeFiles/glfwinfo.dir/flags.make
third_party/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o: third_party/glfw/deps/getopt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eduardo/Desktop/BYOND/MYG.gg/MYG/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object third_party/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o"
	cd /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o   -c /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/deps/getopt.c

third_party/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfwinfo.dir/__/deps/getopt.c.i"
	cd /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/deps/getopt.c > CMakeFiles/glfwinfo.dir/__/deps/getopt.c.i

third_party/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfwinfo.dir/__/deps/getopt.c.s"
	cd /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/deps/getopt.c -o CMakeFiles/glfwinfo.dir/__/deps/getopt.c.s

third_party/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.o: third_party/glfw/tests/CMakeFiles/glfwinfo.dir/flags.make
third_party/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.o: third_party/glfw/deps/glad_gl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eduardo/Desktop/BYOND/MYG.gg/MYG/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object third_party/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.o"
	cd /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.o   -c /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/deps/glad_gl.c

third_party/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.i"
	cd /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/deps/glad_gl.c > CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.i

third_party/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.s"
	cd /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/deps/glad_gl.c -o CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.s

third_party/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.o: third_party/glfw/tests/CMakeFiles/glfwinfo.dir/flags.make
third_party/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.o: third_party/glfw/deps/glad_vulkan.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eduardo/Desktop/BYOND/MYG.gg/MYG/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object third_party/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.o"
	cd /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.o   -c /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/deps/glad_vulkan.c

third_party/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.i"
	cd /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/deps/glad_vulkan.c > CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.i

third_party/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.s"
	cd /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/deps/glad_vulkan.c -o CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.s

# Object files for target glfwinfo
glfwinfo_OBJECTS = \
"CMakeFiles/glfwinfo.dir/glfwinfo.c.o" \
"CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o" \
"CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.o" \
"CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.o"

# External object files for target glfwinfo
glfwinfo_EXTERNAL_OBJECTS =

bin/glfwinfo: third_party/glfw/tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o
bin/glfwinfo: third_party/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o
bin/glfwinfo: third_party/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.o
bin/glfwinfo: third_party/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.o
bin/glfwinfo: third_party/glfw/tests/CMakeFiles/glfwinfo.dir/build.make
bin/glfwinfo: third_party/glfw/src/libglfw3.a
bin/glfwinfo: /usr/lib/x86_64-linux-gnu/libm.so
bin/glfwinfo: /usr/lib/x86_64-linux-gnu/librt.so
bin/glfwinfo: /usr/lib/x86_64-linux-gnu/libm.so
bin/glfwinfo: /usr/lib/x86_64-linux-gnu/libX11.so
bin/glfwinfo: third_party/glfw/tests/CMakeFiles/glfwinfo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/eduardo/Desktop/BYOND/MYG.gg/MYG/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable ../../../bin/glfwinfo"
	cd /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glfwinfo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
third_party/glfw/tests/CMakeFiles/glfwinfo.dir/build: bin/glfwinfo

.PHONY : third_party/glfw/tests/CMakeFiles/glfwinfo.dir/build

third_party/glfw/tests/CMakeFiles/glfwinfo.dir/clean:
	cd /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/tests && $(CMAKE_COMMAND) -P CMakeFiles/glfwinfo.dir/cmake_clean.cmake
.PHONY : third_party/glfw/tests/CMakeFiles/glfwinfo.dir/clean

third_party/glfw/tests/CMakeFiles/glfwinfo.dir/depend:
	cd /home/eduardo/Desktop/BYOND/MYG.gg/MYG && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/eduardo/Desktop/BYOND/MYG.gg/MYG /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/tests /home/eduardo/Desktop/BYOND/MYG.gg/MYG /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/tests /home/eduardo/Desktop/BYOND/MYG.gg/MYG/third_party/glfw/tests/CMakeFiles/glfwinfo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : third_party/glfw/tests/CMakeFiles/glfwinfo.dir/depend

