# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/yanghuichen/clion_workspace/tlpi-demo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/yanghuichen/clion_workspace/tlpi-demo/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/linux_programming.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/linux_programming.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/linux_programming.dir/flags.make

CMakeFiles/linux_programming.dir/main.c.o: CMakeFiles/linux_programming.dir/flags.make
CMakeFiles/linux_programming.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yanghuichen/clion_workspace/tlpi-demo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/linux_programming.dir/main.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/linux_programming.dir/main.c.o   -c /Users/yanghuichen/clion_workspace/tlpi-demo/main.c

CMakeFiles/linux_programming.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/linux_programming.dir/main.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/yanghuichen/clion_workspace/tlpi-demo/main.c > CMakeFiles/linux_programming.dir/main.c.i

CMakeFiles/linux_programming.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/linux_programming.dir/main.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/yanghuichen/clion_workspace/tlpi-demo/main.c -o CMakeFiles/linux_programming.dir/main.c.s

CMakeFiles/linux_programming.dir/lib/error_functions.c.o: CMakeFiles/linux_programming.dir/flags.make
CMakeFiles/linux_programming.dir/lib/error_functions.c.o: ../lib/error_functions.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yanghuichen/clion_workspace/tlpi-demo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/linux_programming.dir/lib/error_functions.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/linux_programming.dir/lib/error_functions.c.o   -c /Users/yanghuichen/clion_workspace/tlpi-demo/lib/error_functions.c

CMakeFiles/linux_programming.dir/lib/error_functions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/linux_programming.dir/lib/error_functions.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/yanghuichen/clion_workspace/tlpi-demo/lib/error_functions.c > CMakeFiles/linux_programming.dir/lib/error_functions.c.i

CMakeFiles/linux_programming.dir/lib/error_functions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/linux_programming.dir/lib/error_functions.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/yanghuichen/clion_workspace/tlpi-demo/lib/error_functions.c -o CMakeFiles/linux_programming.dir/lib/error_functions.c.s

CMakeFiles/linux_programming.dir/lib/get_num.c.o: CMakeFiles/linux_programming.dir/flags.make
CMakeFiles/linux_programming.dir/lib/get_num.c.o: ../lib/get_num.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yanghuichen/clion_workspace/tlpi-demo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/linux_programming.dir/lib/get_num.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/linux_programming.dir/lib/get_num.c.o   -c /Users/yanghuichen/clion_workspace/tlpi-demo/lib/get_num.c

CMakeFiles/linux_programming.dir/lib/get_num.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/linux_programming.dir/lib/get_num.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/yanghuichen/clion_workspace/tlpi-demo/lib/get_num.c > CMakeFiles/linux_programming.dir/lib/get_num.c.i

CMakeFiles/linux_programming.dir/lib/get_num.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/linux_programming.dir/lib/get_num.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/yanghuichen/clion_workspace/tlpi-demo/lib/get_num.c -o CMakeFiles/linux_programming.dir/lib/get_num.c.s

CMakeFiles/linux_programming.dir/example/va_list.c.o: CMakeFiles/linux_programming.dir/flags.make
CMakeFiles/linux_programming.dir/example/va_list.c.o: ../example/va_list.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yanghuichen/clion_workspace/tlpi-demo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/linux_programming.dir/example/va_list.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/linux_programming.dir/example/va_list.c.o   -c /Users/yanghuichen/clion_workspace/tlpi-demo/example/va_list.c

CMakeFiles/linux_programming.dir/example/va_list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/linux_programming.dir/example/va_list.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/yanghuichen/clion_workspace/tlpi-demo/example/va_list.c > CMakeFiles/linux_programming.dir/example/va_list.c.i

CMakeFiles/linux_programming.dir/example/va_list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/linux_programming.dir/example/va_list.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/yanghuichen/clion_workspace/tlpi-demo/example/va_list.c -o CMakeFiles/linux_programming.dir/example/va_list.c.s

# Object files for target linux_programming
linux_programming_OBJECTS = \
"CMakeFiles/linux_programming.dir/main.c.o" \
"CMakeFiles/linux_programming.dir/lib/error_functions.c.o" \
"CMakeFiles/linux_programming.dir/lib/get_num.c.o" \
"CMakeFiles/linux_programming.dir/example/va_list.c.o"

# External object files for target linux_programming
linux_programming_EXTERNAL_OBJECTS =

linux_programming: CMakeFiles/linux_programming.dir/main.c.o
linux_programming: CMakeFiles/linux_programming.dir/lib/error_functions.c.o
linux_programming: CMakeFiles/linux_programming.dir/lib/get_num.c.o
linux_programming: CMakeFiles/linux_programming.dir/example/va_list.c.o
linux_programming: CMakeFiles/linux_programming.dir/build.make
linux_programming: CMakeFiles/linux_programming.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/yanghuichen/clion_workspace/tlpi-demo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable linux_programming"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/linux_programming.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/linux_programming.dir/build: linux_programming

.PHONY : CMakeFiles/linux_programming.dir/build

CMakeFiles/linux_programming.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/linux_programming.dir/cmake_clean.cmake
.PHONY : CMakeFiles/linux_programming.dir/clean

CMakeFiles/linux_programming.dir/depend:
	cd /Users/yanghuichen/clion_workspace/tlpi-demo/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/yanghuichen/clion_workspace/tlpi-demo /Users/yanghuichen/clion_workspace/tlpi-demo /Users/yanghuichen/clion_workspace/tlpi-demo/cmake-build-debug /Users/yanghuichen/clion_workspace/tlpi-demo/cmake-build-debug /Users/yanghuichen/clion_workspace/tlpi-demo/cmake-build-debug/CMakeFiles/linux_programming.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/linux_programming.dir/depend

