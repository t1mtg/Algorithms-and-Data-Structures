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
CMAKE_SOURCE_DIR = C:\Users\BaHo\CLionProjects\algorithms\lab4\brackets

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\BaHo\CLionProjects\algorithms\lab4\brackets\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/brackets.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/brackets.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/brackets.dir/flags.make

CMakeFiles/brackets.dir/main.cpp.obj: CMakeFiles/brackets.dir/flags.make
CMakeFiles/brackets.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\BaHo\CLionProjects\algorithms\lab4\brackets\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/brackets.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\brackets.dir\main.cpp.obj -c C:\Users\BaHo\CLionProjects\algorithms\lab4\brackets\main.cpp

CMakeFiles/brackets.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/brackets.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\BaHo\CLionProjects\algorithms\lab4\brackets\main.cpp > CMakeFiles\brackets.dir\main.cpp.i

CMakeFiles/brackets.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/brackets.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\BaHo\CLionProjects\algorithms\lab4\brackets\main.cpp -o CMakeFiles\brackets.dir\main.cpp.s

# Object files for target brackets
brackets_OBJECTS = \
"CMakeFiles/brackets.dir/main.cpp.obj"

# External object files for target brackets
brackets_EXTERNAL_OBJECTS =

brackets.exe: CMakeFiles/brackets.dir/main.cpp.obj
brackets.exe: CMakeFiles/brackets.dir/build.make
brackets.exe: CMakeFiles/brackets.dir/linklibs.rsp
brackets.exe: CMakeFiles/brackets.dir/objects1.rsp
brackets.exe: CMakeFiles/brackets.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\BaHo\CLionProjects\algorithms\lab4\brackets\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable brackets.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\brackets.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/brackets.dir/build: brackets.exe

.PHONY : CMakeFiles/brackets.dir/build

CMakeFiles/brackets.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\brackets.dir\cmake_clean.cmake
.PHONY : CMakeFiles/brackets.dir/clean

CMakeFiles/brackets.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\BaHo\CLionProjects\algorithms\lab4\brackets C:\Users\BaHo\CLionProjects\algorithms\lab4\brackets C:\Users\BaHo\CLionProjects\algorithms\lab4\brackets\cmake-build-debug C:\Users\BaHo\CLionProjects\algorithms\lab4\brackets\cmake-build-debug C:\Users\BaHo\CLionProjects\algorithms\lab4\brackets\cmake-build-debug\CMakeFiles\brackets.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/brackets.dir/depend
