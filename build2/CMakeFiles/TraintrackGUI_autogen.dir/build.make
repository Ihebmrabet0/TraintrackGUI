# CMAKE generated file: DO NOT EDIT!
# Generated by "MSYS Makefiles" Generator, CMake Version 3.25

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /C/Developer/msys64/mingw64/bin/cmake.exe

# The command to remove a file.
RM = /C/Developer/msys64/mingw64/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/C/Users/Knaus/Documents/C++ Projects/Zug Gui/TraintrackGUI"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/C/Users/Knaus/Documents/C++ Projects/Zug Gui/TraintrackGUI/build2"

# Utility rule file for TraintrackGUI_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/TraintrackGUI_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TraintrackGUI_autogen.dir/progress.make

CMakeFiles/TraintrackGUI_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="/C/Users/Knaus/Documents/C++ Projects/Zug Gui/TraintrackGUI/build2/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target TraintrackGUI"
	/C/Developer/msys64/mingw64/bin/cmake.exe -E cmake_autogen "C:/Users/Knaus/Documents/C++ Projects/Zug Gui/TraintrackGUI/build2/CMakeFiles/TraintrackGUI_autogen.dir/AutogenInfo.json" ""

TraintrackGUI_autogen: CMakeFiles/TraintrackGUI_autogen
TraintrackGUI_autogen: CMakeFiles/TraintrackGUI_autogen.dir/build.make
.PHONY : TraintrackGUI_autogen

# Rule to build all files generated by this target.
CMakeFiles/TraintrackGUI_autogen.dir/build: TraintrackGUI_autogen
.PHONY : CMakeFiles/TraintrackGUI_autogen.dir/build

CMakeFiles/TraintrackGUI_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TraintrackGUI_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TraintrackGUI_autogen.dir/clean

CMakeFiles/TraintrackGUI_autogen.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MSYS Makefiles" "/C/Users/Knaus/Documents/C++ Projects/Zug Gui/TraintrackGUI" "/C/Users/Knaus/Documents/C++ Projects/Zug Gui/TraintrackGUI" "/C/Users/Knaus/Documents/C++ Projects/Zug Gui/TraintrackGUI/build2" "/C/Users/Knaus/Documents/C++ Projects/Zug Gui/TraintrackGUI/build2" "/C/Users/Knaus/Documents/C++ Projects/Zug Gui/TraintrackGUI/build2/CMakeFiles/TraintrackGUI_autogen.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/TraintrackGUI_autogen.dir/depend

