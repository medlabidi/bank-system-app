# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2024.1\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2024.1\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\WIN10X64EN\CLionProjects\bank-system-app

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\WIN10X64EN\CLionProjects\bank-system-app\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/bank_app.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/bank_app.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/bank_app.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bank_app.dir/flags.make

CMakeFiles/bank_app.dir/functions.c.obj: CMakeFiles/bank_app.dir/flags.make
CMakeFiles/bank_app.dir/functions.c.obj: CMakeFiles/bank_app.dir/includes_C.rsp
CMakeFiles/bank_app.dir/functions.c.obj: C:/Users/WIN10X64EN/CLionProjects/bank-system-app/functions.c
CMakeFiles/bank_app.dir/functions.c.obj: CMakeFiles/bank_app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\WIN10X64EN\CLionProjects\bank-system-app\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/bank_app.dir/functions.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/bank_app.dir/functions.c.obj -MF CMakeFiles\bank_app.dir\functions.c.obj.d -o CMakeFiles\bank_app.dir\functions.c.obj -c C:\Users\WIN10X64EN\CLionProjects\bank-system-app\functions.c

CMakeFiles/bank_app.dir/functions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/bank_app.dir/functions.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\WIN10X64EN\CLionProjects\bank-system-app\functions.c > CMakeFiles\bank_app.dir\functions.c.i

CMakeFiles/bank_app.dir/functions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/bank_app.dir/functions.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\WIN10X64EN\CLionProjects\bank-system-app\functions.c -o CMakeFiles\bank_app.dir\functions.c.s

# Object files for target bank_app
bank_app_OBJECTS = \
"CMakeFiles/bank_app.dir/functions.c.obj"

# External object files for target bank_app
bank_app_EXTERNAL_OBJECTS =

bank_app.exe: CMakeFiles/bank_app.dir/functions.c.obj
bank_app.exe: CMakeFiles/bank_app.dir/build.make
bank_app.exe: CMakeFiles/bank_app.dir/linkLibs.rsp
bank_app.exe: CMakeFiles/bank_app.dir/objects1.rsp
bank_app.exe: CMakeFiles/bank_app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\WIN10X64EN\CLionProjects\bank-system-app\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable bank_app.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\bank_app.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bank_app.dir/build: bank_app.exe
.PHONY : CMakeFiles/bank_app.dir/build

CMakeFiles/bank_app.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\bank_app.dir\cmake_clean.cmake
.PHONY : CMakeFiles/bank_app.dir/clean

CMakeFiles/bank_app.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\WIN10X64EN\CLionProjects\bank-system-app C:\Users\WIN10X64EN\CLionProjects\bank-system-app C:\Users\WIN10X64EN\CLionProjects\bank-system-app\cmake-build-debug C:\Users\WIN10X64EN\CLionProjects\bank-system-app\cmake-build-debug C:\Users\WIN10X64EN\CLionProjects\bank-system-app\cmake-build-debug\CMakeFiles\bank_app.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/bank_app.dir/depend

