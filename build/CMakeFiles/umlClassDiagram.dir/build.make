# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.27.0/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.27.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jgonz/projects/uml-class-diagram

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jgonz/projects/uml-class-diagram/build

# Include any dependencies generated for this target.
include CMakeFiles/umlClassDiagram.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/umlClassDiagram.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/umlClassDiagram.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/umlClassDiagram.dir/flags.make

CMakeFiles/umlClassDiagram.dir/src/main.cpp.o: CMakeFiles/umlClassDiagram.dir/flags.make
CMakeFiles/umlClassDiagram.dir/src/main.cpp.o: /Users/jgonz/projects/uml-class-diagram/src/main.cpp
CMakeFiles/umlClassDiagram.dir/src/main.cpp.o: CMakeFiles/umlClassDiagram.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jgonz/projects/uml-class-diagram/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/umlClassDiagram.dir/src/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/umlClassDiagram.dir/src/main.cpp.o -MF CMakeFiles/umlClassDiagram.dir/src/main.cpp.o.d -o CMakeFiles/umlClassDiagram.dir/src/main.cpp.o -c /Users/jgonz/projects/uml-class-diagram/src/main.cpp

CMakeFiles/umlClassDiagram.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/umlClassDiagram.dir/src/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jgonz/projects/uml-class-diagram/src/main.cpp > CMakeFiles/umlClassDiagram.dir/src/main.cpp.i

CMakeFiles/umlClassDiagram.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/umlClassDiagram.dir/src/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jgonz/projects/uml-class-diagram/src/main.cpp -o CMakeFiles/umlClassDiagram.dir/src/main.cpp.s

CMakeFiles/umlClassDiagram.dir/include/lexer.cpp.o: CMakeFiles/umlClassDiagram.dir/flags.make
CMakeFiles/umlClassDiagram.dir/include/lexer.cpp.o: /Users/jgonz/projects/uml-class-diagram/include/lexer.cpp
CMakeFiles/umlClassDiagram.dir/include/lexer.cpp.o: CMakeFiles/umlClassDiagram.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jgonz/projects/uml-class-diagram/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/umlClassDiagram.dir/include/lexer.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/umlClassDiagram.dir/include/lexer.cpp.o -MF CMakeFiles/umlClassDiagram.dir/include/lexer.cpp.o.d -o CMakeFiles/umlClassDiagram.dir/include/lexer.cpp.o -c /Users/jgonz/projects/uml-class-diagram/include/lexer.cpp

CMakeFiles/umlClassDiagram.dir/include/lexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/umlClassDiagram.dir/include/lexer.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jgonz/projects/uml-class-diagram/include/lexer.cpp > CMakeFiles/umlClassDiagram.dir/include/lexer.cpp.i

CMakeFiles/umlClassDiagram.dir/include/lexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/umlClassDiagram.dir/include/lexer.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jgonz/projects/uml-class-diagram/include/lexer.cpp -o CMakeFiles/umlClassDiagram.dir/include/lexer.cpp.s

CMakeFiles/umlClassDiagram.dir/include/token.cpp.o: CMakeFiles/umlClassDiagram.dir/flags.make
CMakeFiles/umlClassDiagram.dir/include/token.cpp.o: /Users/jgonz/projects/uml-class-diagram/include/token.cpp
CMakeFiles/umlClassDiagram.dir/include/token.cpp.o: CMakeFiles/umlClassDiagram.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jgonz/projects/uml-class-diagram/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/umlClassDiagram.dir/include/token.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/umlClassDiagram.dir/include/token.cpp.o -MF CMakeFiles/umlClassDiagram.dir/include/token.cpp.o.d -o CMakeFiles/umlClassDiagram.dir/include/token.cpp.o -c /Users/jgonz/projects/uml-class-diagram/include/token.cpp

CMakeFiles/umlClassDiagram.dir/include/token.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/umlClassDiagram.dir/include/token.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jgonz/projects/uml-class-diagram/include/token.cpp > CMakeFiles/umlClassDiagram.dir/include/token.cpp.i

CMakeFiles/umlClassDiagram.dir/include/token.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/umlClassDiagram.dir/include/token.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jgonz/projects/uml-class-diagram/include/token.cpp -o CMakeFiles/umlClassDiagram.dir/include/token.cpp.s

# Object files for target umlClassDiagram
umlClassDiagram_OBJECTS = \
"CMakeFiles/umlClassDiagram.dir/src/main.cpp.o" \
"CMakeFiles/umlClassDiagram.dir/include/lexer.cpp.o" \
"CMakeFiles/umlClassDiagram.dir/include/token.cpp.o"

# External object files for target umlClassDiagram
umlClassDiagram_EXTERNAL_OBJECTS =

/Users/jgonz/projects/uml-class-diagram/bin/umlClassDiagram: CMakeFiles/umlClassDiagram.dir/src/main.cpp.o
/Users/jgonz/projects/uml-class-diagram/bin/umlClassDiagram: CMakeFiles/umlClassDiagram.dir/include/lexer.cpp.o
/Users/jgonz/projects/uml-class-diagram/bin/umlClassDiagram: CMakeFiles/umlClassDiagram.dir/include/token.cpp.o
/Users/jgonz/projects/uml-class-diagram/bin/umlClassDiagram: CMakeFiles/umlClassDiagram.dir/build.make
/Users/jgonz/projects/uml-class-diagram/bin/umlClassDiagram: CMakeFiles/umlClassDiagram.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/jgonz/projects/uml-class-diagram/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable /Users/jgonz/projects/uml-class-diagram/bin/umlClassDiagram"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/umlClassDiagram.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/umlClassDiagram.dir/build: /Users/jgonz/projects/uml-class-diagram/bin/umlClassDiagram
.PHONY : CMakeFiles/umlClassDiagram.dir/build

CMakeFiles/umlClassDiagram.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/umlClassDiagram.dir/cmake_clean.cmake
.PHONY : CMakeFiles/umlClassDiagram.dir/clean

CMakeFiles/umlClassDiagram.dir/depend:
	cd /Users/jgonz/projects/uml-class-diagram/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jgonz/projects/uml-class-diagram /Users/jgonz/projects/uml-class-diagram /Users/jgonz/projects/uml-class-diagram/build /Users/jgonz/projects/uml-class-diagram/build /Users/jgonz/projects/uml-class-diagram/build/CMakeFiles/umlClassDiagram.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/umlClassDiagram.dir/depend

