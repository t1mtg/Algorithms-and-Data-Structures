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
CMAKE_SOURCE_DIR = C:\Users\BaHo\CLionProjects\algorithms\lab4\garland

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\BaHo\CLionProjects\algorithms\lab4\garland\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/garland.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/garland.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/garland.dir/flags.make

CMakeFiles/garland.dir/main.cpp.obj: CMakeFiles/garland.dir/flags.make
CMakeFiles/garland.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\BaHo\CLionProjects\algorithms\lab4\garland\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/garland.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\garland.dir\main.cpp.obj -c C:\Users\BaHo\CLionProjects\algorithms\lab4\garland\main.cpp

CMakeFiles/garland.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/garland.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\BaHo\CLionProjects\algorithms\lab4\garland\main.cpp > CMakeFiles\garland.dir\main.cpp.i

CMakeFiles/garland.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/garland.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\BaHo\CLionProjects\algorithms\lab4\garland\main.cpp -o CMakeFiles\garland.dir\main.cpp.s

# Object files for target garland
garland_OBJECTS = \
"CMakeFiles/garland.dir/main.cpp.obj"

# External object files for target garland
garland_EXTERNAL_OBJECTS =

garland.exe: CMakeFiles/garland.dir/main.cpp.obj
garland.exe: CMakeFiles/garland.dir/build.make
garland.exe: CMakeFiles/garland.dir/linklibs.rsp
garland.exe: CMakeFiles/garland.dir/objects1.rsp
garland.exe: CMakeFiles/garland.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\BaHo\CLionProjects\algorithms\lab4\garland\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable garland.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\garland.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/garland.dir/build: garland.exe

.PHONY : CMakeFiles/garland.dir/build

CMakeFiles/garland.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\garland.dir\cmake_clean.cmake
.PHONY : CMakeFiles/garland.dir/clean

CMakeFiles/garland.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\BaHo\CLionProjects\algorithms\lab4\garland C:\Users\BaHo\CLionProjects\algorithms\lab4\garland C:\Users\BaHo\CLionProjects\algorithms\lab4\garland\cmake-build-debug C:\Users\BaHo\CLionProjects\algorithms\lab4\garland\cmake-build-debug C:\Users\BaHo\CLionProjects\algorithms\lab4\garland\cmake-build-debug\CMakeFiles\garland.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/garland.dir/depend

