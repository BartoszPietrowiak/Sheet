# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Bartek\Desktop\Arkusz

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Bartek\Desktop\Arkusz\build

# Include any dependencies generated for this target.
include CMakeFiles/Sheet.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Sheet.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Sheet.dir/flags.make

CMakeFiles/Sheet.dir/src/main.cpp.obj: CMakeFiles/Sheet.dir/flags.make
CMakeFiles/Sheet.dir/src/main.cpp.obj: CMakeFiles/Sheet.dir/includes_CXX.rsp
CMakeFiles/Sheet.dir/src/main.cpp.obj: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Bartek\Desktop\Arkusz\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Sheet.dir/src/main.cpp.obj"
	C:\MinGw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Sheet.dir\src\main.cpp.obj -c C:\Users\Bartek\Desktop\Arkusz\src\main.cpp

CMakeFiles/Sheet.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sheet.dir/src/main.cpp.i"
	C:\MinGw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Bartek\Desktop\Arkusz\src\main.cpp > CMakeFiles\Sheet.dir\src\main.cpp.i

CMakeFiles/Sheet.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sheet.dir/src/main.cpp.s"
	C:\MinGw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Bartek\Desktop\Arkusz\src\main.cpp -o CMakeFiles\Sheet.dir\src\main.cpp.s

CMakeFiles/Sheet.dir/src/Cell.cpp.obj: CMakeFiles/Sheet.dir/flags.make
CMakeFiles/Sheet.dir/src/Cell.cpp.obj: CMakeFiles/Sheet.dir/includes_CXX.rsp
CMakeFiles/Sheet.dir/src/Cell.cpp.obj: ../src/Cell.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Bartek\Desktop\Arkusz\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Sheet.dir/src/Cell.cpp.obj"
	C:\MinGw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Sheet.dir\src\Cell.cpp.obj -c C:\Users\Bartek\Desktop\Arkusz\src\Cell.cpp

CMakeFiles/Sheet.dir/src/Cell.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sheet.dir/src/Cell.cpp.i"
	C:\MinGw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Bartek\Desktop\Arkusz\src\Cell.cpp > CMakeFiles\Sheet.dir\src\Cell.cpp.i

CMakeFiles/Sheet.dir/src/Cell.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sheet.dir/src/Cell.cpp.s"
	C:\MinGw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Bartek\Desktop\Arkusz\src\Cell.cpp -o CMakeFiles\Sheet.dir\src\Cell.cpp.s

CMakeFiles/Sheet.dir/src/Sheet.cpp.obj: CMakeFiles/Sheet.dir/flags.make
CMakeFiles/Sheet.dir/src/Sheet.cpp.obj: CMakeFiles/Sheet.dir/includes_CXX.rsp
CMakeFiles/Sheet.dir/src/Sheet.cpp.obj: ../src/Sheet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Bartek\Desktop\Arkusz\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Sheet.dir/src/Sheet.cpp.obj"
	C:\MinGw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Sheet.dir\src\Sheet.cpp.obj -c C:\Users\Bartek\Desktop\Arkusz\src\Sheet.cpp

CMakeFiles/Sheet.dir/src/Sheet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sheet.dir/src/Sheet.cpp.i"
	C:\MinGw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Bartek\Desktop\Arkusz\src\Sheet.cpp > CMakeFiles\Sheet.dir\src\Sheet.cpp.i

CMakeFiles/Sheet.dir/src/Sheet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sheet.dir/src/Sheet.cpp.s"
	C:\MinGw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Bartek\Desktop\Arkusz\src\Sheet.cpp -o CMakeFiles\Sheet.dir\src\Sheet.cpp.s

CMakeFiles/Sheet.dir/src/Chart.cpp.obj: CMakeFiles/Sheet.dir/flags.make
CMakeFiles/Sheet.dir/src/Chart.cpp.obj: CMakeFiles/Sheet.dir/includes_CXX.rsp
CMakeFiles/Sheet.dir/src/Chart.cpp.obj: ../src/Chart.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Bartek\Desktop\Arkusz\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Sheet.dir/src/Chart.cpp.obj"
	C:\MinGw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Sheet.dir\src\Chart.cpp.obj -c C:\Users\Bartek\Desktop\Arkusz\src\Chart.cpp

CMakeFiles/Sheet.dir/src/Chart.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sheet.dir/src/Chart.cpp.i"
	C:\MinGw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Bartek\Desktop\Arkusz\src\Chart.cpp > CMakeFiles\Sheet.dir\src\Chart.cpp.i

CMakeFiles/Sheet.dir/src/Chart.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sheet.dir/src/Chart.cpp.s"
	C:\MinGw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Bartek\Desktop\Arkusz\src\Chart.cpp -o CMakeFiles\Sheet.dir\src\Chart.cpp.s

CMakeFiles/Sheet.dir/src/RangeException.cpp.obj: CMakeFiles/Sheet.dir/flags.make
CMakeFiles/Sheet.dir/src/RangeException.cpp.obj: CMakeFiles/Sheet.dir/includes_CXX.rsp
CMakeFiles/Sheet.dir/src/RangeException.cpp.obj: ../src/RangeException.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Bartek\Desktop\Arkusz\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Sheet.dir/src/RangeException.cpp.obj"
	C:\MinGw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Sheet.dir\src\RangeException.cpp.obj -c C:\Users\Bartek\Desktop\Arkusz\src\RangeException.cpp

CMakeFiles/Sheet.dir/src/RangeException.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sheet.dir/src/RangeException.cpp.i"
	C:\MinGw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Bartek\Desktop\Arkusz\src\RangeException.cpp > CMakeFiles\Sheet.dir\src\RangeException.cpp.i

CMakeFiles/Sheet.dir/src/RangeException.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sheet.dir/src/RangeException.cpp.s"
	C:\MinGw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Bartek\Desktop\Arkusz\src\RangeException.cpp -o CMakeFiles\Sheet.dir\src\RangeException.cpp.s

# Object files for target Sheet
Sheet_OBJECTS = \
"CMakeFiles/Sheet.dir/src/main.cpp.obj" \
"CMakeFiles/Sheet.dir/src/Cell.cpp.obj" \
"CMakeFiles/Sheet.dir/src/Sheet.cpp.obj" \
"CMakeFiles/Sheet.dir/src/Chart.cpp.obj" \
"CMakeFiles/Sheet.dir/src/RangeException.cpp.obj"

# External object files for target Sheet
Sheet_EXTERNAL_OBJECTS =

../Sheet.exe: CMakeFiles/Sheet.dir/src/main.cpp.obj
../Sheet.exe: CMakeFiles/Sheet.dir/src/Cell.cpp.obj
../Sheet.exe: CMakeFiles/Sheet.dir/src/Sheet.cpp.obj
../Sheet.exe: CMakeFiles/Sheet.dir/src/Chart.cpp.obj
../Sheet.exe: CMakeFiles/Sheet.dir/src/RangeException.cpp.obj
../Sheet.exe: CMakeFiles/Sheet.dir/build.make
../Sheet.exe: ../src/SFML/install/lib/libsfml-system-s-d.a
../Sheet.exe: ../src/SFML/install/lib/libsfml-window-s-d.a
../Sheet.exe: ../src/SFML/install/lib/libsfml-graphics-s-d.a
../Sheet.exe: ../src/SFML/install/lib/libsfml-network-s-d.a
../Sheet.exe: ../src/SFML/install/lib/libsfml-audio-s-d.a
../Sheet.exe: ../src/SFML/install/lib/libsfml-window-s-d.a
../Sheet.exe: ../src/SFML/install/lib/libfreetype.a
../Sheet.exe: ../src/SFML/install/lib/libsfml-system-s-d.a
../Sheet.exe: ../src/SFML/install/lib/libopenal32.a
../Sheet.exe: ../src/SFML/install/lib/libvorbisfile.a
../Sheet.exe: ../src/SFML/install/lib/libvorbisenc.a
../Sheet.exe: ../src/SFML/install/lib/libvorbis.a
../Sheet.exe: ../src/SFML/install/lib/libogg.a
../Sheet.exe: ../src/SFML/install/lib/libFLAC.a
../Sheet.exe: CMakeFiles/Sheet.dir/linklibs.rsp
../Sheet.exe: CMakeFiles/Sheet.dir/objects1.rsp
../Sheet.exe: CMakeFiles/Sheet.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Bartek\Desktop\Arkusz\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable ..\Sheet.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Sheet.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Sheet.dir/build: ../Sheet.exe

.PHONY : CMakeFiles/Sheet.dir/build

CMakeFiles/Sheet.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Sheet.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Sheet.dir/clean

CMakeFiles/Sheet.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Bartek\Desktop\Arkusz C:\Users\Bartek\Desktop\Arkusz C:\Users\Bartek\Desktop\Arkusz\build C:\Users\Bartek\Desktop\Arkusz\build C:\Users\Bartek\Desktop\Arkusz\build\CMakeFiles\Sheet.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Sheet.dir/depend

