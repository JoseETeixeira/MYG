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
CMAKE_SOURCE_DIR = /home/eduardo/Desktop/BYOND/MYG

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/eduardo/Desktop/BYOND/MYG

# Include any dependencies generated for this target.
include src/editor/CMakeFiles/Editor.dir/depend.make

# Include the progress variables for this target.
include src/editor/CMakeFiles/Editor.dir/progress.make

# Include the compile flags for this target's objects.
include src/editor/CMakeFiles/Editor.dir/flags.make

src/editor/CMakeFiles/Editor.dir/editor.cpp.o: src/editor/CMakeFiles/Editor.dir/flags.make
src/editor/CMakeFiles/Editor.dir/editor.cpp.o: src/editor/editor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eduardo/Desktop/BYOND/MYG/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/editor/CMakeFiles/Editor.dir/editor.cpp.o"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Editor.dir/editor.cpp.o -c /home/eduardo/Desktop/BYOND/MYG/src/editor/editor.cpp

src/editor/CMakeFiles/Editor.dir/editor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Editor.dir/editor.cpp.i"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eduardo/Desktop/BYOND/MYG/src/editor/editor.cpp > CMakeFiles/Editor.dir/editor.cpp.i

src/editor/CMakeFiles/Editor.dir/editor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Editor.dir/editor.cpp.s"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eduardo/Desktop/BYOND/MYG/src/editor/editor.cpp -o CMakeFiles/Editor.dir/editor.cpp.s

src/editor/CMakeFiles/Editor.dir/__/byond/DMI/DMI.cpp.o: src/editor/CMakeFiles/Editor.dir/flags.make
src/editor/CMakeFiles/Editor.dir/__/byond/DMI/DMI.cpp.o: src/byond/DMI/DMI.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eduardo/Desktop/BYOND/MYG/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/editor/CMakeFiles/Editor.dir/__/byond/DMI/DMI.cpp.o"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Editor.dir/__/byond/DMI/DMI.cpp.o -c /home/eduardo/Desktop/BYOND/MYG/src/byond/DMI/DMI.cpp

src/editor/CMakeFiles/Editor.dir/__/byond/DMI/DMI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Editor.dir/__/byond/DMI/DMI.cpp.i"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eduardo/Desktop/BYOND/MYG/src/byond/DMI/DMI.cpp > CMakeFiles/Editor.dir/__/byond/DMI/DMI.cpp.i

src/editor/CMakeFiles/Editor.dir/__/byond/DMI/DMI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Editor.dir/__/byond/DMI/DMI.cpp.s"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eduardo/Desktop/BYOND/MYG/src/byond/DMI/DMI.cpp -o CMakeFiles/Editor.dir/__/byond/DMI/DMI.cpp.s

src/editor/CMakeFiles/Editor.dir/__/byond/DMI/codecs/file.cpp.o: src/editor/CMakeFiles/Editor.dir/flags.make
src/editor/CMakeFiles/Editor.dir/__/byond/DMI/codecs/file.cpp.o: src/byond/DMI/codecs/file.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eduardo/Desktop/BYOND/MYG/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/editor/CMakeFiles/Editor.dir/__/byond/DMI/codecs/file.cpp.o"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Editor.dir/__/byond/DMI/codecs/file.cpp.o -c /home/eduardo/Desktop/BYOND/MYG/src/byond/DMI/codecs/file.cpp

src/editor/CMakeFiles/Editor.dir/__/byond/DMI/codecs/file.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Editor.dir/__/byond/DMI/codecs/file.cpp.i"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eduardo/Desktop/BYOND/MYG/src/byond/DMI/codecs/file.cpp > CMakeFiles/Editor.dir/__/byond/DMI/codecs/file.cpp.i

src/editor/CMakeFiles/Editor.dir/__/byond/DMI/codecs/file.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Editor.dir/__/byond/DMI/codecs/file.cpp.s"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eduardo/Desktop/BYOND/MYG/src/byond/DMI/codecs/file.cpp -o CMakeFiles/Editor.dir/__/byond/DMI/codecs/file.cpp.s

src/editor/CMakeFiles/Editor.dir/__/byond/DMI/codecs/png.cpp.o: src/editor/CMakeFiles/Editor.dir/flags.make
src/editor/CMakeFiles/Editor.dir/__/byond/DMI/codecs/png.cpp.o: src/byond/DMI/codecs/png.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eduardo/Desktop/BYOND/MYG/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/editor/CMakeFiles/Editor.dir/__/byond/DMI/codecs/png.cpp.o"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Editor.dir/__/byond/DMI/codecs/png.cpp.o -c /home/eduardo/Desktop/BYOND/MYG/src/byond/DMI/codecs/png.cpp

src/editor/CMakeFiles/Editor.dir/__/byond/DMI/codecs/png.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Editor.dir/__/byond/DMI/codecs/png.cpp.i"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eduardo/Desktop/BYOND/MYG/src/byond/DMI/codecs/png.cpp > CMakeFiles/Editor.dir/__/byond/DMI/codecs/png.cpp.i

src/editor/CMakeFiles/Editor.dir/__/byond/DMI/codecs/png.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Editor.dir/__/byond/DMI/codecs/png.cpp.s"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eduardo/Desktop/BYOND/MYG/src/byond/DMI/codecs/png.cpp -o CMakeFiles/Editor.dir/__/byond/DMI/codecs/png.cpp.s

src/editor/CMakeFiles/Editor.dir/__/byond/DMI/codecs/webp.cpp.o: src/editor/CMakeFiles/Editor.dir/flags.make
src/editor/CMakeFiles/Editor.dir/__/byond/DMI/codecs/webp.cpp.o: src/byond/DMI/codecs/webp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eduardo/Desktop/BYOND/MYG/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/editor/CMakeFiles/Editor.dir/__/byond/DMI/codecs/webp.cpp.o"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Editor.dir/__/byond/DMI/codecs/webp.cpp.o -c /home/eduardo/Desktop/BYOND/MYG/src/byond/DMI/codecs/webp.cpp

src/editor/CMakeFiles/Editor.dir/__/byond/DMI/codecs/webp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Editor.dir/__/byond/DMI/codecs/webp.cpp.i"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eduardo/Desktop/BYOND/MYG/src/byond/DMI/codecs/webp.cpp > CMakeFiles/Editor.dir/__/byond/DMI/codecs/webp.cpp.i

src/editor/CMakeFiles/Editor.dir/__/byond/DMI/codecs/webp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Editor.dir/__/byond/DMI/codecs/webp.cpp.s"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eduardo/Desktop/BYOND/MYG/src/byond/DMI/codecs/webp.cpp -o CMakeFiles/Editor.dir/__/byond/DMI/codecs/webp.cpp.s

src/editor/CMakeFiles/Editor.dir/__/byond/DMI/errors.cpp.o: src/editor/CMakeFiles/Editor.dir/flags.make
src/editor/CMakeFiles/Editor.dir/__/byond/DMI/errors.cpp.o: src/byond/DMI/errors.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eduardo/Desktop/BYOND/MYG/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/editor/CMakeFiles/Editor.dir/__/byond/DMI/errors.cpp.o"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Editor.dir/__/byond/DMI/errors.cpp.o -c /home/eduardo/Desktop/BYOND/MYG/src/byond/DMI/errors.cpp

src/editor/CMakeFiles/Editor.dir/__/byond/DMI/errors.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Editor.dir/__/byond/DMI/errors.cpp.i"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eduardo/Desktop/BYOND/MYG/src/byond/DMI/errors.cpp > CMakeFiles/Editor.dir/__/byond/DMI/errors.cpp.i

src/editor/CMakeFiles/Editor.dir/__/byond/DMI/errors.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Editor.dir/__/byond/DMI/errors.cpp.s"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eduardo/Desktop/BYOND/MYG/src/byond/DMI/errors.cpp -o CMakeFiles/Editor.dir/__/byond/DMI/errors.cpp.s

src/editor/CMakeFiles/Editor.dir/source_navigation/source_navigation.cpp.o: src/editor/CMakeFiles/Editor.dir/flags.make
src/editor/CMakeFiles/Editor.dir/source_navigation/source_navigation.cpp.o: src/editor/source_navigation/source_navigation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eduardo/Desktop/BYOND/MYG/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/editor/CMakeFiles/Editor.dir/source_navigation/source_navigation.cpp.o"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Editor.dir/source_navigation/source_navigation.cpp.o -c /home/eduardo/Desktop/BYOND/MYG/src/editor/source_navigation/source_navigation.cpp

src/editor/CMakeFiles/Editor.dir/source_navigation/source_navigation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Editor.dir/source_navigation/source_navigation.cpp.i"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eduardo/Desktop/BYOND/MYG/src/editor/source_navigation/source_navigation.cpp > CMakeFiles/Editor.dir/source_navigation/source_navigation.cpp.i

src/editor/CMakeFiles/Editor.dir/source_navigation/source_navigation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Editor.dir/source_navigation/source_navigation.cpp.s"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eduardo/Desktop/BYOND/MYG/src/editor/source_navigation/source_navigation.cpp -o CMakeFiles/Editor.dir/source_navigation/source_navigation.cpp.s

src/editor/CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/getopt.c.o: src/editor/CMakeFiles/Editor.dir/flags.make
src/editor/CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/getopt.c.o: third_party/glfw/deps/getopt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eduardo/Desktop/BYOND/MYG/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object src/editor/CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/getopt.c.o"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/getopt.c.o   -c /home/eduardo/Desktop/BYOND/MYG/third_party/glfw/deps/getopt.c

src/editor/CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/getopt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/getopt.c.i"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/eduardo/Desktop/BYOND/MYG/third_party/glfw/deps/getopt.c > CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/getopt.c.i

src/editor/CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/getopt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/getopt.c.s"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/eduardo/Desktop/BYOND/MYG/third_party/glfw/deps/getopt.c -o CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/getopt.c.s

src/editor/CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/glad_gl.c.o: src/editor/CMakeFiles/Editor.dir/flags.make
src/editor/CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/glad_gl.c.o: third_party/glfw/deps/glad_gl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eduardo/Desktop/BYOND/MYG/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object src/editor/CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/glad_gl.c.o"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/glad_gl.c.o   -c /home/eduardo/Desktop/BYOND/MYG/third_party/glfw/deps/glad_gl.c

src/editor/CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/glad_gl.c.i"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/eduardo/Desktop/BYOND/MYG/third_party/glfw/deps/glad_gl.c > CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/glad_gl.c.i

src/editor/CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/glad_gl.c.s"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/eduardo/Desktop/BYOND/MYG/third_party/glfw/deps/glad_gl.c -o CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/glad_gl.c.s

src/editor/CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/glad_vulkan.c.o: src/editor/CMakeFiles/Editor.dir/flags.make
src/editor/CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/glad_vulkan.c.o: third_party/glfw/deps/glad_vulkan.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eduardo/Desktop/BYOND/MYG/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object src/editor/CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/glad_vulkan.c.o"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/glad_vulkan.c.o   -c /home/eduardo/Desktop/BYOND/MYG/third_party/glfw/deps/glad_vulkan.c

src/editor/CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/glad_vulkan.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/glad_vulkan.c.i"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/eduardo/Desktop/BYOND/MYG/third_party/glfw/deps/glad_vulkan.c > CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/glad_vulkan.c.i

src/editor/CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/glad_vulkan.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/glad_vulkan.c.s"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/eduardo/Desktop/BYOND/MYG/third_party/glfw/deps/glad_vulkan.c -o CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/glad_vulkan.c.s

src/editor/CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/tinycthread.c.o: src/editor/CMakeFiles/Editor.dir/flags.make
src/editor/CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/tinycthread.c.o: third_party/glfw/deps/tinycthread.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eduardo/Desktop/BYOND/MYG/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object src/editor/CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/tinycthread.c.o"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/tinycthread.c.o   -c /home/eduardo/Desktop/BYOND/MYG/third_party/glfw/deps/tinycthread.c

src/editor/CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/tinycthread.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/tinycthread.c.i"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/eduardo/Desktop/BYOND/MYG/third_party/glfw/deps/tinycthread.c > CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/tinycthread.c.i

src/editor/CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/tinycthread.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/tinycthread.c.s"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/eduardo/Desktop/BYOND/MYG/third_party/glfw/deps/tinycthread.c -o CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/tinycthread.c.s

src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/TextEditor.cpp.o: src/editor/CMakeFiles/Editor.dir/flags.make
src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/TextEditor.cpp.o: third_party/imgui/TextEditor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eduardo/Desktop/BYOND/MYG/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/TextEditor.cpp.o"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Editor.dir/__/__/third_party/imgui/TextEditor.cpp.o -c /home/eduardo/Desktop/BYOND/MYG/third_party/imgui/TextEditor.cpp

src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/TextEditor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Editor.dir/__/__/third_party/imgui/TextEditor.cpp.i"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eduardo/Desktop/BYOND/MYG/third_party/imgui/TextEditor.cpp > CMakeFiles/Editor.dir/__/__/third_party/imgui/TextEditor.cpp.i

src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/TextEditor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Editor.dir/__/__/third_party/imgui/TextEditor.cpp.s"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eduardo/Desktop/BYOND/MYG/third_party/imgui/TextEditor.cpp -o CMakeFiles/Editor.dir/__/__/third_party/imgui/TextEditor.cpp.s

src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui.cpp.o: src/editor/CMakeFiles/Editor.dir/flags.make
src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui.cpp.o: third_party/imgui/imgui.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eduardo/Desktop/BYOND/MYG/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui.cpp.o"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui.cpp.o -c /home/eduardo/Desktop/BYOND/MYG/third_party/imgui/imgui.cpp

src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui.cpp.i"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eduardo/Desktop/BYOND/MYG/third_party/imgui/imgui.cpp > CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui.cpp.i

src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui.cpp.s"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eduardo/Desktop/BYOND/MYG/third_party/imgui/imgui.cpp -o CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui.cpp.s

src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_demo.cpp.o: src/editor/CMakeFiles/Editor.dir/flags.make
src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_demo.cpp.o: third_party/imgui/imgui_demo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eduardo/Desktop/BYOND/MYG/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_demo.cpp.o"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_demo.cpp.o -c /home/eduardo/Desktop/BYOND/MYG/third_party/imgui/imgui_demo.cpp

src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_demo.cpp.i"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eduardo/Desktop/BYOND/MYG/third_party/imgui/imgui_demo.cpp > CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_demo.cpp.i

src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_demo.cpp.s"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eduardo/Desktop/BYOND/MYG/third_party/imgui/imgui_demo.cpp -o CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_demo.cpp.s

src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_draw.cpp.o: src/editor/CMakeFiles/Editor.dir/flags.make
src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_draw.cpp.o: third_party/imgui/imgui_draw.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eduardo/Desktop/BYOND/MYG/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_draw.cpp.o"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_draw.cpp.o -c /home/eduardo/Desktop/BYOND/MYG/third_party/imgui/imgui_draw.cpp

src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_draw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_draw.cpp.i"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eduardo/Desktop/BYOND/MYG/third_party/imgui/imgui_draw.cpp > CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_draw.cpp.i

src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_draw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_draw.cpp.s"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eduardo/Desktop/BYOND/MYG/third_party/imgui/imgui_draw.cpp -o CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_draw.cpp.s

src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_file_browser.cpp.o: src/editor/CMakeFiles/Editor.dir/flags.make
src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_file_browser.cpp.o: third_party/imgui/imgui_file_browser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eduardo/Desktop/BYOND/MYG/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_file_browser.cpp.o"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_file_browser.cpp.o -c /home/eduardo/Desktop/BYOND/MYG/third_party/imgui/imgui_file_browser.cpp

src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_file_browser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_file_browser.cpp.i"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eduardo/Desktop/BYOND/MYG/third_party/imgui/imgui_file_browser.cpp > CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_file_browser.cpp.i

src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_file_browser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_file_browser.cpp.s"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eduardo/Desktop/BYOND/MYG/third_party/imgui/imgui_file_browser.cpp -o CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_file_browser.cpp.s

src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_impl_glfw.cpp.o: src/editor/CMakeFiles/Editor.dir/flags.make
src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_impl_glfw.cpp.o: third_party/imgui/imgui_impl_glfw.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eduardo/Desktop/BYOND/MYG/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_impl_glfw.cpp.o"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_impl_glfw.cpp.o -c /home/eduardo/Desktop/BYOND/MYG/third_party/imgui/imgui_impl_glfw.cpp

src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_impl_glfw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_impl_glfw.cpp.i"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eduardo/Desktop/BYOND/MYG/third_party/imgui/imgui_impl_glfw.cpp > CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_impl_glfw.cpp.i

src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_impl_glfw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_impl_glfw.cpp.s"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eduardo/Desktop/BYOND/MYG/third_party/imgui/imgui_impl_glfw.cpp -o CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_impl_glfw.cpp.s

src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_impl_opengl3.cpp.o: src/editor/CMakeFiles/Editor.dir/flags.make
src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_impl_opengl3.cpp.o: third_party/imgui/imgui_impl_opengl3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eduardo/Desktop/BYOND/MYG/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_impl_opengl3.cpp.o"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_impl_opengl3.cpp.o -c /home/eduardo/Desktop/BYOND/MYG/third_party/imgui/imgui_impl_opengl3.cpp

src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_impl_opengl3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_impl_opengl3.cpp.i"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eduardo/Desktop/BYOND/MYG/third_party/imgui/imgui_impl_opengl3.cpp > CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_impl_opengl3.cpp.i

src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_impl_opengl3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_impl_opengl3.cpp.s"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eduardo/Desktop/BYOND/MYG/third_party/imgui/imgui_impl_opengl3.cpp -o CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_impl_opengl3.cpp.s

src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_tables.cpp.o: src/editor/CMakeFiles/Editor.dir/flags.make
src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_tables.cpp.o: third_party/imgui/imgui_tables.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eduardo/Desktop/BYOND/MYG/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building CXX object src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_tables.cpp.o"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_tables.cpp.o -c /home/eduardo/Desktop/BYOND/MYG/third_party/imgui/imgui_tables.cpp

src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_tables.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_tables.cpp.i"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eduardo/Desktop/BYOND/MYG/third_party/imgui/imgui_tables.cpp > CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_tables.cpp.i

src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_tables.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_tables.cpp.s"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eduardo/Desktop/BYOND/MYG/third_party/imgui/imgui_tables.cpp -o CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_tables.cpp.s

src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_widgets.cpp.o: src/editor/CMakeFiles/Editor.dir/flags.make
src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_widgets.cpp.o: third_party/imgui/imgui_widgets.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eduardo/Desktop/BYOND/MYG/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Building CXX object src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_widgets.cpp.o"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_widgets.cpp.o -c /home/eduardo/Desktop/BYOND/MYG/third_party/imgui/imgui_widgets.cpp

src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_widgets.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_widgets.cpp.i"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eduardo/Desktop/BYOND/MYG/third_party/imgui/imgui_widgets.cpp > CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_widgets.cpp.i

src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_widgets.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_widgets.cpp.s"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eduardo/Desktop/BYOND/MYG/third_party/imgui/imgui_widgets.cpp -o CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_widgets.cpp.s

# Object files for target Editor
Editor_OBJECTS = \
"CMakeFiles/Editor.dir/editor.cpp.o" \
"CMakeFiles/Editor.dir/__/byond/DMI/DMI.cpp.o" \
"CMakeFiles/Editor.dir/__/byond/DMI/codecs/file.cpp.o" \
"CMakeFiles/Editor.dir/__/byond/DMI/codecs/png.cpp.o" \
"CMakeFiles/Editor.dir/__/byond/DMI/codecs/webp.cpp.o" \
"CMakeFiles/Editor.dir/__/byond/DMI/errors.cpp.o" \
"CMakeFiles/Editor.dir/source_navigation/source_navigation.cpp.o" \
"CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/getopt.c.o" \
"CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/glad_gl.c.o" \
"CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/glad_vulkan.c.o" \
"CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/tinycthread.c.o" \
"CMakeFiles/Editor.dir/__/__/third_party/imgui/TextEditor.cpp.o" \
"CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui.cpp.o" \
"CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_demo.cpp.o" \
"CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_draw.cpp.o" \
"CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_file_browser.cpp.o" \
"CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_impl_glfw.cpp.o" \
"CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_impl_opengl3.cpp.o" \
"CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_tables.cpp.o" \
"CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_widgets.cpp.o"

# External object files for target Editor
Editor_EXTERNAL_OBJECTS =

bin/Editor: src/editor/CMakeFiles/Editor.dir/editor.cpp.o
bin/Editor: src/editor/CMakeFiles/Editor.dir/__/byond/DMI/DMI.cpp.o
bin/Editor: src/editor/CMakeFiles/Editor.dir/__/byond/DMI/codecs/file.cpp.o
bin/Editor: src/editor/CMakeFiles/Editor.dir/__/byond/DMI/codecs/png.cpp.o
bin/Editor: src/editor/CMakeFiles/Editor.dir/__/byond/DMI/codecs/webp.cpp.o
bin/Editor: src/editor/CMakeFiles/Editor.dir/__/byond/DMI/errors.cpp.o
bin/Editor: src/editor/CMakeFiles/Editor.dir/source_navigation/source_navigation.cpp.o
bin/Editor: src/editor/CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/getopt.c.o
bin/Editor: src/editor/CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/glad_gl.c.o
bin/Editor: src/editor/CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/glad_vulkan.c.o
bin/Editor: src/editor/CMakeFiles/Editor.dir/__/__/third_party/glfw/deps/tinycthread.c.o
bin/Editor: src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/TextEditor.cpp.o
bin/Editor: src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui.cpp.o
bin/Editor: src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_demo.cpp.o
bin/Editor: src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_draw.cpp.o
bin/Editor: src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_file_browser.cpp.o
bin/Editor: src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_impl_glfw.cpp.o
bin/Editor: src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_impl_opengl3.cpp.o
bin/Editor: src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_tables.cpp.o
bin/Editor: src/editor/CMakeFiles/Editor.dir/__/__/third_party/imgui/imgui_widgets.cpp.o
bin/Editor: src/editor/CMakeFiles/Editor.dir/build.make
bin/Editor: /usr/lib/x86_64-linux-gnu/libz.so
bin/Editor: /usr/lib/x86_64-linux-gnu/libpng.so
bin/Editor: /usr/lib/x86_64-linux-gnu/libz.so
bin/Editor: src/byond/libbyond.so.1.0.0
bin/Editor: third_party/glfw/src/libglfw3.a
bin/Editor: /usr/lib/x86_64-linux-gnu/libpng.so
bin/Editor: /usr/lib/x86_64-linux-gnu/libz.so
bin/Editor: /usr/lib/x86_64-linux-gnu/librt.so
bin/Editor: /usr/lib/x86_64-linux-gnu/libm.so
bin/Editor: /usr/lib/x86_64-linux-gnu/libX11.so
bin/Editor: src/editor/CMakeFiles/Editor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/eduardo/Desktop/BYOND/MYG/CMakeFiles --progress-num=$(CMAKE_PROGRESS_21) "Linking CXX executable ../../bin/Editor"
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Editor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/editor/CMakeFiles/Editor.dir/build: bin/Editor

.PHONY : src/editor/CMakeFiles/Editor.dir/build

src/editor/CMakeFiles/Editor.dir/clean:
	cd /home/eduardo/Desktop/BYOND/MYG/src/editor && $(CMAKE_COMMAND) -P CMakeFiles/Editor.dir/cmake_clean.cmake
.PHONY : src/editor/CMakeFiles/Editor.dir/clean

src/editor/CMakeFiles/Editor.dir/depend:
	cd /home/eduardo/Desktop/BYOND/MYG && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/eduardo/Desktop/BYOND/MYG /home/eduardo/Desktop/BYOND/MYG/src/editor /home/eduardo/Desktop/BYOND/MYG /home/eduardo/Desktop/BYOND/MYG/src/editor /home/eduardo/Desktop/BYOND/MYG/src/editor/CMakeFiles/Editor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/editor/CMakeFiles/Editor.dir/depend

