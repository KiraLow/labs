# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /home/vlad/clion-2016.3.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/vlad/clion-2016.3.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vlad/Prg/semesrovye/img/imgGauss/ansi

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vlad/Prg/semesrovye/img/imgGauss/ansi/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/imageload_template.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/imageload_template.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/imageload_template.dir/flags.make

CMakeFiles/imageload_template.dir/main.c.o: CMakeFiles/imageload_template.dir/flags.make
CMakeFiles/imageload_template.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vlad/Prg/semesrovye/img/imgGauss/ansi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/imageload_template.dir/main.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/imageload_template.dir/main.c.o   -c /home/vlad/Prg/semesrovye/img/imgGauss/ansi/main.c

CMakeFiles/imageload_template.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/imageload_template.dir/main.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vlad/Prg/semesrovye/img/imgGauss/ansi/main.c > CMakeFiles/imageload_template.dir/main.c.i

CMakeFiles/imageload_template.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/imageload_template.dir/main.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vlad/Prg/semesrovye/img/imgGauss/ansi/main.c -o CMakeFiles/imageload_template.dir/main.c.s

CMakeFiles/imageload_template.dir/main.c.o.requires:

.PHONY : CMakeFiles/imageload_template.dir/main.c.o.requires

CMakeFiles/imageload_template.dir/main.c.o.provides: CMakeFiles/imageload_template.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/imageload_template.dir/build.make CMakeFiles/imageload_template.dir/main.c.o.provides.build
.PHONY : CMakeFiles/imageload_template.dir/main.c.o.provides

CMakeFiles/imageload_template.dir/main.c.o.provides.build: CMakeFiles/imageload_template.dir/main.c.o


CMakeFiles/imageload_template.dir/qdbmp.c.o: CMakeFiles/imageload_template.dir/flags.make
CMakeFiles/imageload_template.dir/qdbmp.c.o: ../qdbmp.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vlad/Prg/semesrovye/img/imgGauss/ansi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/imageload_template.dir/qdbmp.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/imageload_template.dir/qdbmp.c.o   -c /home/vlad/Prg/semesrovye/img/imgGauss/ansi/qdbmp.c

CMakeFiles/imageload_template.dir/qdbmp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/imageload_template.dir/qdbmp.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vlad/Prg/semesrovye/img/imgGauss/ansi/qdbmp.c > CMakeFiles/imageload_template.dir/qdbmp.c.i

CMakeFiles/imageload_template.dir/qdbmp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/imageload_template.dir/qdbmp.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vlad/Prg/semesrovye/img/imgGauss/ansi/qdbmp.c -o CMakeFiles/imageload_template.dir/qdbmp.c.s

CMakeFiles/imageload_template.dir/qdbmp.c.o.requires:

.PHONY : CMakeFiles/imageload_template.dir/qdbmp.c.o.requires

CMakeFiles/imageload_template.dir/qdbmp.c.o.provides: CMakeFiles/imageload_template.dir/qdbmp.c.o.requires
	$(MAKE) -f CMakeFiles/imageload_template.dir/build.make CMakeFiles/imageload_template.dir/qdbmp.c.o.provides.build
.PHONY : CMakeFiles/imageload_template.dir/qdbmp.c.o.provides

CMakeFiles/imageload_template.dir/qdbmp.c.o.provides.build: CMakeFiles/imageload_template.dir/qdbmp.c.o


# Object files for target imageload_template
imageload_template_OBJECTS = \
"CMakeFiles/imageload_template.dir/main.c.o" \
"CMakeFiles/imageload_template.dir/qdbmp.c.o"

# External object files for target imageload_template
imageload_template_EXTERNAL_OBJECTS =

imageload_template: CMakeFiles/imageload_template.dir/main.c.o
imageload_template: CMakeFiles/imageload_template.dir/qdbmp.c.o
imageload_template: CMakeFiles/imageload_template.dir/build.make
imageload_template: CMakeFiles/imageload_template.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vlad/Prg/semesrovye/img/imgGauss/ansi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable imageload_template"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/imageload_template.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/imageload_template.dir/build: imageload_template

.PHONY : CMakeFiles/imageload_template.dir/build

CMakeFiles/imageload_template.dir/requires: CMakeFiles/imageload_template.dir/main.c.o.requires
CMakeFiles/imageload_template.dir/requires: CMakeFiles/imageload_template.dir/qdbmp.c.o.requires

.PHONY : CMakeFiles/imageload_template.dir/requires

CMakeFiles/imageload_template.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/imageload_template.dir/cmake_clean.cmake
.PHONY : CMakeFiles/imageload_template.dir/clean

CMakeFiles/imageload_template.dir/depend:
	cd /home/vlad/Prg/semesrovye/img/imgGauss/ansi/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vlad/Prg/semesrovye/img/imgGauss/ansi /home/vlad/Prg/semesrovye/img/imgGauss/ansi /home/vlad/Prg/semesrovye/img/imgGauss/ansi/cmake-build-debug /home/vlad/Prg/semesrovye/img/imgGauss/ansi/cmake-build-debug /home/vlad/Prg/semesrovye/img/imgGauss/ansi/cmake-build-debug/CMakeFiles/imageload_template.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/imageload_template.dir/depend

