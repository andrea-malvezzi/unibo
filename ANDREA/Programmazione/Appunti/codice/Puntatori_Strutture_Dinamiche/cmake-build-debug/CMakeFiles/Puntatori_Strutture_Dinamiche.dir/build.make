# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2024.2.2\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2024.2.2\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\andre\OneDrive\Desktop\unibo\ANDREA\Programmazione\Appunti\codice\Puntatori_Strutture_Dinamiche

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\andre\OneDrive\Desktop\unibo\ANDREA\Programmazione\Appunti\codice\Puntatori_Strutture_Dinamiche\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Puntatori_Strutture_Dinamiche.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Puntatori_Strutture_Dinamiche.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Puntatori_Strutture_Dinamiche.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Puntatori_Strutture_Dinamiche.dir/flags.make

CMakeFiles/Puntatori_Strutture_Dinamiche.dir/main.cpp.obj: CMakeFiles/Puntatori_Strutture_Dinamiche.dir/flags.make
CMakeFiles/Puntatori_Strutture_Dinamiche.dir/main.cpp.obj: C:/Users/andre/OneDrive/Desktop/unibo/ANDREA/Programmazione/Appunti/codice/Puntatori_Strutture_Dinamiche/main.cpp
CMakeFiles/Puntatori_Strutture_Dinamiche.dir/main.cpp.obj: CMakeFiles/Puntatori_Strutture_Dinamiche.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\andre\OneDrive\Desktop\unibo\ANDREA\Programmazione\Appunti\codice\Puntatori_Strutture_Dinamiche\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Puntatori_Strutture_Dinamiche.dir/main.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Puntatori_Strutture_Dinamiche.dir/main.cpp.obj -MF CMakeFiles\Puntatori_Strutture_Dinamiche.dir\main.cpp.obj.d -o CMakeFiles\Puntatori_Strutture_Dinamiche.dir\main.cpp.obj -c C:\Users\andre\OneDrive\Desktop\unibo\ANDREA\Programmazione\Appunti\codice\Puntatori_Strutture_Dinamiche\main.cpp

CMakeFiles/Puntatori_Strutture_Dinamiche.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Puntatori_Strutture_Dinamiche.dir/main.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\andre\OneDrive\Desktop\unibo\ANDREA\Programmazione\Appunti\codice\Puntatori_Strutture_Dinamiche\main.cpp > CMakeFiles\Puntatori_Strutture_Dinamiche.dir\main.cpp.i

CMakeFiles/Puntatori_Strutture_Dinamiche.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Puntatori_Strutture_Dinamiche.dir/main.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\andre\OneDrive\Desktop\unibo\ANDREA\Programmazione\Appunti\codice\Puntatori_Strutture_Dinamiche\main.cpp -o CMakeFiles\Puntatori_Strutture_Dinamiche.dir\main.cpp.s

# Object files for target Puntatori_Strutture_Dinamiche
Puntatori_Strutture_Dinamiche_OBJECTS = \
"CMakeFiles/Puntatori_Strutture_Dinamiche.dir/main.cpp.obj"

# External object files for target Puntatori_Strutture_Dinamiche
Puntatori_Strutture_Dinamiche_EXTERNAL_OBJECTS =

Puntatori_Strutture_Dinamiche.exe: CMakeFiles/Puntatori_Strutture_Dinamiche.dir/main.cpp.obj
Puntatori_Strutture_Dinamiche.exe: CMakeFiles/Puntatori_Strutture_Dinamiche.dir/build.make
Puntatori_Strutture_Dinamiche.exe: CMakeFiles/Puntatori_Strutture_Dinamiche.dir/linkLibs.rsp
Puntatori_Strutture_Dinamiche.exe: CMakeFiles/Puntatori_Strutture_Dinamiche.dir/objects1.rsp
Puntatori_Strutture_Dinamiche.exe: CMakeFiles/Puntatori_Strutture_Dinamiche.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\andre\OneDrive\Desktop\unibo\ANDREA\Programmazione\Appunti\codice\Puntatori_Strutture_Dinamiche\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Puntatori_Strutture_Dinamiche.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Puntatori_Strutture_Dinamiche.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Puntatori_Strutture_Dinamiche.dir/build: Puntatori_Strutture_Dinamiche.exe
.PHONY : CMakeFiles/Puntatori_Strutture_Dinamiche.dir/build

CMakeFiles/Puntatori_Strutture_Dinamiche.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Puntatori_Strutture_Dinamiche.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Puntatori_Strutture_Dinamiche.dir/clean

CMakeFiles/Puntatori_Strutture_Dinamiche.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\andre\OneDrive\Desktop\unibo\ANDREA\Programmazione\Appunti\codice\Puntatori_Strutture_Dinamiche C:\Users\andre\OneDrive\Desktop\unibo\ANDREA\Programmazione\Appunti\codice\Puntatori_Strutture_Dinamiche C:\Users\andre\OneDrive\Desktop\unibo\ANDREA\Programmazione\Appunti\codice\Puntatori_Strutture_Dinamiche\cmake-build-debug C:\Users\andre\OneDrive\Desktop\unibo\ANDREA\Programmazione\Appunti\codice\Puntatori_Strutture_Dinamiche\cmake-build-debug C:\Users\andre\OneDrive\Desktop\unibo\ANDREA\Programmazione\Appunti\codice\Puntatori_Strutture_Dinamiche\cmake-build-debug\CMakeFiles\Puntatori_Strutture_Dinamiche.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Puntatori_Strutture_Dinamiche.dir/depend

