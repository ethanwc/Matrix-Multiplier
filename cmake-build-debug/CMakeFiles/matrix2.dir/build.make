# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /home/ethanwc/IDEs/clion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/ethanwc/IDEs/clion/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ethanwc/Documents/380/Matrix-Multiplier222

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ethanwc/Documents/380/Matrix-Multiplier222/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/matrix2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/matrix2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/matrix2.dir/flags.make

CMakeFiles/matrix2.dir/pcmatrix.c.o: CMakeFiles/matrix2.dir/flags.make
CMakeFiles/matrix2.dir/pcmatrix.c.o: ../pcmatrix.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ethanwc/Documents/380/Matrix-Multiplier222/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/matrix2.dir/pcmatrix.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/matrix2.dir/pcmatrix.c.o   -c /home/ethanwc/Documents/380/Matrix-Multiplier222/pcmatrix.c

CMakeFiles/matrix2.dir/pcmatrix.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/matrix2.dir/pcmatrix.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ethanwc/Documents/380/Matrix-Multiplier222/pcmatrix.c > CMakeFiles/matrix2.dir/pcmatrix.c.i

CMakeFiles/matrix2.dir/pcmatrix.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/matrix2.dir/pcmatrix.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ethanwc/Documents/380/Matrix-Multiplier222/pcmatrix.c -o CMakeFiles/matrix2.dir/pcmatrix.c.s

CMakeFiles/matrix2.dir/matrix.c.o: CMakeFiles/matrix2.dir/flags.make
CMakeFiles/matrix2.dir/matrix.c.o: ../matrix.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ethanwc/Documents/380/Matrix-Multiplier222/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/matrix2.dir/matrix.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/matrix2.dir/matrix.c.o   -c /home/ethanwc/Documents/380/Matrix-Multiplier222/matrix.c

CMakeFiles/matrix2.dir/matrix.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/matrix2.dir/matrix.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ethanwc/Documents/380/Matrix-Multiplier222/matrix.c > CMakeFiles/matrix2.dir/matrix.c.i

CMakeFiles/matrix2.dir/matrix.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/matrix2.dir/matrix.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ethanwc/Documents/380/Matrix-Multiplier222/matrix.c -o CMakeFiles/matrix2.dir/matrix.c.s

CMakeFiles/matrix2.dir/counter.c.o: CMakeFiles/matrix2.dir/flags.make
CMakeFiles/matrix2.dir/counter.c.o: ../counter.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ethanwc/Documents/380/Matrix-Multiplier222/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/matrix2.dir/counter.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/matrix2.dir/counter.c.o   -c /home/ethanwc/Documents/380/Matrix-Multiplier222/counter.c

CMakeFiles/matrix2.dir/counter.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/matrix2.dir/counter.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ethanwc/Documents/380/Matrix-Multiplier222/counter.c > CMakeFiles/matrix2.dir/counter.c.i

CMakeFiles/matrix2.dir/counter.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/matrix2.dir/counter.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ethanwc/Documents/380/Matrix-Multiplier222/counter.c -o CMakeFiles/matrix2.dir/counter.c.s

CMakeFiles/matrix2.dir/prodcons.c.o: CMakeFiles/matrix2.dir/flags.make
CMakeFiles/matrix2.dir/prodcons.c.o: ../prodcons.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ethanwc/Documents/380/Matrix-Multiplier222/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/matrix2.dir/prodcons.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/matrix2.dir/prodcons.c.o   -c /home/ethanwc/Documents/380/Matrix-Multiplier222/prodcons.c

CMakeFiles/matrix2.dir/prodcons.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/matrix2.dir/prodcons.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ethanwc/Documents/380/Matrix-Multiplier222/prodcons.c > CMakeFiles/matrix2.dir/prodcons.c.i

CMakeFiles/matrix2.dir/prodcons.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/matrix2.dir/prodcons.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ethanwc/Documents/380/Matrix-Multiplier222/prodcons.c -o CMakeFiles/matrix2.dir/prodcons.c.s

# Object files for target matrix2
matrix2_OBJECTS = \
"CMakeFiles/matrix2.dir/pcmatrix.c.o" \
"CMakeFiles/matrix2.dir/matrix.c.o" \
"CMakeFiles/matrix2.dir/counter.c.o" \
"CMakeFiles/matrix2.dir/prodcons.c.o"

# External object files for target matrix2
matrix2_EXTERNAL_OBJECTS =

matrix2: CMakeFiles/matrix2.dir/pcmatrix.c.o
matrix2: CMakeFiles/matrix2.dir/matrix.c.o
matrix2: CMakeFiles/matrix2.dir/counter.c.o
matrix2: CMakeFiles/matrix2.dir/prodcons.c.o
matrix2: CMakeFiles/matrix2.dir/build.make
matrix2: CMakeFiles/matrix2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ethanwc/Documents/380/Matrix-Multiplier222/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable matrix2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/matrix2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/matrix2.dir/build: matrix2

.PHONY : CMakeFiles/matrix2.dir/build

CMakeFiles/matrix2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/matrix2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/matrix2.dir/clean

CMakeFiles/matrix2.dir/depend:
	cd /home/ethanwc/Documents/380/Matrix-Multiplier222/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ethanwc/Documents/380/Matrix-Multiplier222 /home/ethanwc/Documents/380/Matrix-Multiplier222 /home/ethanwc/Documents/380/Matrix-Multiplier222/cmake-build-debug /home/ethanwc/Documents/380/Matrix-Multiplier222/cmake-build-debug /home/ethanwc/Documents/380/Matrix-Multiplier222/cmake-build-debug/CMakeFiles/matrix2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/matrix2.dir/depend

