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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\BaHo\CLionProjects\algorithms\lab13\prefix

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\BaHo\CLionProjects\algorithms\lab13\prefix\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/prefix.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/prefix.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/prefix.dir/flags.make

CMakeFiles/prefix.dir/main.cpp.obj: CMakeFiles/prefix.dir/flags.make
CMakeFiles/prefix.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\BaHo\CLionProjects\algorithms\lab13\prefix\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/prefix.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\prefix.dir\main.cpp.obj -c C:\Users\BaHo\CLionProjects\algorithms\lab13\prefix\main.cpp

CMakeFiles/prefix.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/prefix.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\BaHo\CLionProjects\algorithms\lab13\prefix\main.cpp > CMakeFiles\prefix.dir\main.cpp.i

CMakeFiles/prefix.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/prefix.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\BaHo\CLionProjects\algorithms\lab13\prefix\main.cpp -o CMakeFiles\prefix.dir\main.cpp.s

# Object files for target prefix
prefix_OBJECTS = \
"CMakeFiles/prefix.dir/main.cpp.obj"

# External object files for target prefix
prefix_EXTERNAL_OBJECTS =

prefix.exe: CMakeFiles/prefix.dir/main.cpp.obj
prefix.exe: CMakeFiles/prefix.dir/build.make
prefix.exe: CMakeFiles/prefix.dir/linklibs.rsp
prefix.exe: CMakeFiles/prefix.dir/objects1.rsp
prefix.exe: CMakeFiles/prefix.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\BaHo\CLionProjects\algorithms\lab13\prefix\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable prefix.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\prefix.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/prefix.dir/build: prefix.exe

.PHONY : CMakeFiles/prefix.dir/build

CMakeFiles/prefix.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\prefix.dir\cmake_clean.cmake
.PHONY : CMakeFiles/prefix.dir/clean

CMakeFiles/prefix.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\BaHo\CLionProjects\algorithms\lab13\prefix C:\Users\BaHo\CLionProjects\algorithms\lab13\prefix C:\Users\BaHo\CLionProjects\algorithms\lab13\prefix\cmake-build-debug C:\Users\BaHo\CLionProjects\algorithms\lab13\prefix\cmake-build-debug C:\Users\BaHo\CLionProjects\algorithms\lab13\prefix\cmake-build-debug\CMakeFiles\prefix.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/prefix.dir/depend

