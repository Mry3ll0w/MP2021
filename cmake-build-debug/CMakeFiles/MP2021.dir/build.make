# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Proyectos\MP2021

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Proyectos\MP2021\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MP2021.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MP2021.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MP2021.dir/flags.make

CMakeFiles/MP2021.dir/main.c.obj: CMakeFiles/MP2021.dir/flags.make
CMakeFiles/MP2021.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Proyectos\MP2021\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/MP2021.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\MP2021.dir\main.c.obj   -c D:\Proyectos\MP2021\main.c

CMakeFiles/MP2021.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MP2021.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Proyectos\MP2021\main.c > CMakeFiles\MP2021.dir\main.c.i

CMakeFiles/MP2021.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MP2021.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Proyectos\MP2021\main.c -o CMakeFiles\MP2021.dir\main.c.s

CMakeFiles/MP2021.dir/lib/core.c.obj: CMakeFiles/MP2021.dir/flags.make
CMakeFiles/MP2021.dir/lib/core.c.obj: ../lib/core.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Proyectos\MP2021\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/MP2021.dir/lib/core.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\MP2021.dir\lib\core.c.obj   -c D:\Proyectos\MP2021\lib\core.c

CMakeFiles/MP2021.dir/lib/core.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MP2021.dir/lib/core.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Proyectos\MP2021\lib\core.c > CMakeFiles\MP2021.dir\lib\core.c.i

CMakeFiles/MP2021.dir/lib/core.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MP2021.dir/lib/core.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Proyectos\MP2021\lib\core.c -o CMakeFiles\MP2021.dir\lib\core.c.s

# Object files for target MP2021
MP2021_OBJECTS = \
"CMakeFiles/MP2021.dir/main.c.obj" \
"CMakeFiles/MP2021.dir/lib/core.c.obj"

# External object files for target MP2021
MP2021_EXTERNAL_OBJECTS =

MP2021.exe: CMakeFiles/MP2021.dir/main.c.obj
MP2021.exe: CMakeFiles/MP2021.dir/lib/core.c.obj
MP2021.exe: CMakeFiles/MP2021.dir/build.make
MP2021.exe: CMakeFiles/MP2021.dir/linklibs.rsp
MP2021.exe: CMakeFiles/MP2021.dir/objects1.rsp
MP2021.exe: CMakeFiles/MP2021.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Proyectos\MP2021\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable MP2021.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\MP2021.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MP2021.dir/build: MP2021.exe

.PHONY : CMakeFiles/MP2021.dir/build

CMakeFiles/MP2021.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\MP2021.dir\cmake_clean.cmake
.PHONY : CMakeFiles/MP2021.dir/clean

CMakeFiles/MP2021.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Proyectos\MP2021 D:\Proyectos\MP2021 D:\Proyectos\MP2021\cmake-build-debug D:\Proyectos\MP2021\cmake-build-debug D:\Proyectos\MP2021\cmake-build-debug\CMakeFiles\MP2021.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MP2021.dir/depend

