# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/galgoczi/simulation/ScintTutorial

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/galgoczi/simulation/ScintTutorial/build

# Include any dependencies generated for this target.
include CMakeFiles/ScintTutorial.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ScintTutorial.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ScintTutorial.dir/flags.make

CMakeFiles/ScintTutorial.dir/OpNovice.cc.o: CMakeFiles/ScintTutorial.dir/flags.make
CMakeFiles/ScintTutorial.dir/OpNovice.cc.o: ../OpNovice.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/galgoczi/simulation/ScintTutorial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ScintTutorial.dir/OpNovice.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ScintTutorial.dir/OpNovice.cc.o -c /home/galgoczi/simulation/ScintTutorial/OpNovice.cc

CMakeFiles/ScintTutorial.dir/OpNovice.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ScintTutorial.dir/OpNovice.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/galgoczi/simulation/ScintTutorial/OpNovice.cc > CMakeFiles/ScintTutorial.dir/OpNovice.cc.i

CMakeFiles/ScintTutorial.dir/OpNovice.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ScintTutorial.dir/OpNovice.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/galgoczi/simulation/ScintTutorial/OpNovice.cc -o CMakeFiles/ScintTutorial.dir/OpNovice.cc.s

CMakeFiles/ScintTutorial.dir/OpNovice.cc.o.requires:

.PHONY : CMakeFiles/ScintTutorial.dir/OpNovice.cc.o.requires

CMakeFiles/ScintTutorial.dir/OpNovice.cc.o.provides: CMakeFiles/ScintTutorial.dir/OpNovice.cc.o.requires
	$(MAKE) -f CMakeFiles/ScintTutorial.dir/build.make CMakeFiles/ScintTutorial.dir/OpNovice.cc.o.provides.build
.PHONY : CMakeFiles/ScintTutorial.dir/OpNovice.cc.o.provides

CMakeFiles/ScintTutorial.dir/OpNovice.cc.o.provides.build: CMakeFiles/ScintTutorial.dir/OpNovice.cc.o


CMakeFiles/ScintTutorial.dir/src/OpNoviceActionInitialization.cc.o: CMakeFiles/ScintTutorial.dir/flags.make
CMakeFiles/ScintTutorial.dir/src/OpNoviceActionInitialization.cc.o: ../src/OpNoviceActionInitialization.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/galgoczi/simulation/ScintTutorial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ScintTutorial.dir/src/OpNoviceActionInitialization.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ScintTutorial.dir/src/OpNoviceActionInitialization.cc.o -c /home/galgoczi/simulation/ScintTutorial/src/OpNoviceActionInitialization.cc

CMakeFiles/ScintTutorial.dir/src/OpNoviceActionInitialization.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ScintTutorial.dir/src/OpNoviceActionInitialization.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/galgoczi/simulation/ScintTutorial/src/OpNoviceActionInitialization.cc > CMakeFiles/ScintTutorial.dir/src/OpNoviceActionInitialization.cc.i

CMakeFiles/ScintTutorial.dir/src/OpNoviceActionInitialization.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ScintTutorial.dir/src/OpNoviceActionInitialization.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/galgoczi/simulation/ScintTutorial/src/OpNoviceActionInitialization.cc -o CMakeFiles/ScintTutorial.dir/src/OpNoviceActionInitialization.cc.s

CMakeFiles/ScintTutorial.dir/src/OpNoviceActionInitialization.cc.o.requires:

.PHONY : CMakeFiles/ScintTutorial.dir/src/OpNoviceActionInitialization.cc.o.requires

CMakeFiles/ScintTutorial.dir/src/OpNoviceActionInitialization.cc.o.provides: CMakeFiles/ScintTutorial.dir/src/OpNoviceActionInitialization.cc.o.requires
	$(MAKE) -f CMakeFiles/ScintTutorial.dir/build.make CMakeFiles/ScintTutorial.dir/src/OpNoviceActionInitialization.cc.o.provides.build
.PHONY : CMakeFiles/ScintTutorial.dir/src/OpNoviceActionInitialization.cc.o.provides

CMakeFiles/ScintTutorial.dir/src/OpNoviceActionInitialization.cc.o.provides.build: CMakeFiles/ScintTutorial.dir/src/OpNoviceActionInitialization.cc.o


CMakeFiles/ScintTutorial.dir/src/OpNoviceDetectorConstruction.cc.o: CMakeFiles/ScintTutorial.dir/flags.make
CMakeFiles/ScintTutorial.dir/src/OpNoviceDetectorConstruction.cc.o: ../src/OpNoviceDetectorConstruction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/galgoczi/simulation/ScintTutorial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ScintTutorial.dir/src/OpNoviceDetectorConstruction.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ScintTutorial.dir/src/OpNoviceDetectorConstruction.cc.o -c /home/galgoczi/simulation/ScintTutorial/src/OpNoviceDetectorConstruction.cc

CMakeFiles/ScintTutorial.dir/src/OpNoviceDetectorConstruction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ScintTutorial.dir/src/OpNoviceDetectorConstruction.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/galgoczi/simulation/ScintTutorial/src/OpNoviceDetectorConstruction.cc > CMakeFiles/ScintTutorial.dir/src/OpNoviceDetectorConstruction.cc.i

CMakeFiles/ScintTutorial.dir/src/OpNoviceDetectorConstruction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ScintTutorial.dir/src/OpNoviceDetectorConstruction.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/galgoczi/simulation/ScintTutorial/src/OpNoviceDetectorConstruction.cc -o CMakeFiles/ScintTutorial.dir/src/OpNoviceDetectorConstruction.cc.s

CMakeFiles/ScintTutorial.dir/src/OpNoviceDetectorConstruction.cc.o.requires:

.PHONY : CMakeFiles/ScintTutorial.dir/src/OpNoviceDetectorConstruction.cc.o.requires

CMakeFiles/ScintTutorial.dir/src/OpNoviceDetectorConstruction.cc.o.provides: CMakeFiles/ScintTutorial.dir/src/OpNoviceDetectorConstruction.cc.o.requires
	$(MAKE) -f CMakeFiles/ScintTutorial.dir/build.make CMakeFiles/ScintTutorial.dir/src/OpNoviceDetectorConstruction.cc.o.provides.build
.PHONY : CMakeFiles/ScintTutorial.dir/src/OpNoviceDetectorConstruction.cc.o.provides

CMakeFiles/ScintTutorial.dir/src/OpNoviceDetectorConstruction.cc.o.provides.build: CMakeFiles/ScintTutorial.dir/src/OpNoviceDetectorConstruction.cc.o


CMakeFiles/ScintTutorial.dir/src/OpNoviceSteppingAction.cc.o: CMakeFiles/ScintTutorial.dir/flags.make
CMakeFiles/ScintTutorial.dir/src/OpNoviceSteppingAction.cc.o: ../src/OpNoviceSteppingAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/galgoczi/simulation/ScintTutorial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ScintTutorial.dir/src/OpNoviceSteppingAction.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ScintTutorial.dir/src/OpNoviceSteppingAction.cc.o -c /home/galgoczi/simulation/ScintTutorial/src/OpNoviceSteppingAction.cc

CMakeFiles/ScintTutorial.dir/src/OpNoviceSteppingAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ScintTutorial.dir/src/OpNoviceSteppingAction.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/galgoczi/simulation/ScintTutorial/src/OpNoviceSteppingAction.cc > CMakeFiles/ScintTutorial.dir/src/OpNoviceSteppingAction.cc.i

CMakeFiles/ScintTutorial.dir/src/OpNoviceSteppingAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ScintTutorial.dir/src/OpNoviceSteppingAction.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/galgoczi/simulation/ScintTutorial/src/OpNoviceSteppingAction.cc -o CMakeFiles/ScintTutorial.dir/src/OpNoviceSteppingAction.cc.s

CMakeFiles/ScintTutorial.dir/src/OpNoviceSteppingAction.cc.o.requires:

.PHONY : CMakeFiles/ScintTutorial.dir/src/OpNoviceSteppingAction.cc.o.requires

CMakeFiles/ScintTutorial.dir/src/OpNoviceSteppingAction.cc.o.provides: CMakeFiles/ScintTutorial.dir/src/OpNoviceSteppingAction.cc.o.requires
	$(MAKE) -f CMakeFiles/ScintTutorial.dir/build.make CMakeFiles/ScintTutorial.dir/src/OpNoviceSteppingAction.cc.o.provides.build
.PHONY : CMakeFiles/ScintTutorial.dir/src/OpNoviceSteppingAction.cc.o.provides

CMakeFiles/ScintTutorial.dir/src/OpNoviceSteppingAction.cc.o.provides.build: CMakeFiles/ScintTutorial.dir/src/OpNoviceSteppingAction.cc.o


CMakeFiles/ScintTutorial.dir/src/OpNovicePhysicsListMessenger.cc.o: CMakeFiles/ScintTutorial.dir/flags.make
CMakeFiles/ScintTutorial.dir/src/OpNovicePhysicsListMessenger.cc.o: ../src/OpNovicePhysicsListMessenger.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/galgoczi/simulation/ScintTutorial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ScintTutorial.dir/src/OpNovicePhysicsListMessenger.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ScintTutorial.dir/src/OpNovicePhysicsListMessenger.cc.o -c /home/galgoczi/simulation/ScintTutorial/src/OpNovicePhysicsListMessenger.cc

CMakeFiles/ScintTutorial.dir/src/OpNovicePhysicsListMessenger.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ScintTutorial.dir/src/OpNovicePhysicsListMessenger.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/galgoczi/simulation/ScintTutorial/src/OpNovicePhysicsListMessenger.cc > CMakeFiles/ScintTutorial.dir/src/OpNovicePhysicsListMessenger.cc.i

CMakeFiles/ScintTutorial.dir/src/OpNovicePhysicsListMessenger.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ScintTutorial.dir/src/OpNovicePhysicsListMessenger.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/galgoczi/simulation/ScintTutorial/src/OpNovicePhysicsListMessenger.cc -o CMakeFiles/ScintTutorial.dir/src/OpNovicePhysicsListMessenger.cc.s

CMakeFiles/ScintTutorial.dir/src/OpNovicePhysicsListMessenger.cc.o.requires:

.PHONY : CMakeFiles/ScintTutorial.dir/src/OpNovicePhysicsListMessenger.cc.o.requires

CMakeFiles/ScintTutorial.dir/src/OpNovicePhysicsListMessenger.cc.o.provides: CMakeFiles/ScintTutorial.dir/src/OpNovicePhysicsListMessenger.cc.o.requires
	$(MAKE) -f CMakeFiles/ScintTutorial.dir/build.make CMakeFiles/ScintTutorial.dir/src/OpNovicePhysicsListMessenger.cc.o.provides.build
.PHONY : CMakeFiles/ScintTutorial.dir/src/OpNovicePhysicsListMessenger.cc.o.provides

CMakeFiles/ScintTutorial.dir/src/OpNovicePhysicsListMessenger.cc.o.provides.build: CMakeFiles/ScintTutorial.dir/src/OpNovicePhysicsListMessenger.cc.o


CMakeFiles/ScintTutorial.dir/src/OpNovicePrimaryGeneratorAction.cc.o: CMakeFiles/ScintTutorial.dir/flags.make
CMakeFiles/ScintTutorial.dir/src/OpNovicePrimaryGeneratorAction.cc.o: ../src/OpNovicePrimaryGeneratorAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/galgoczi/simulation/ScintTutorial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ScintTutorial.dir/src/OpNovicePrimaryGeneratorAction.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ScintTutorial.dir/src/OpNovicePrimaryGeneratorAction.cc.o -c /home/galgoczi/simulation/ScintTutorial/src/OpNovicePrimaryGeneratorAction.cc

CMakeFiles/ScintTutorial.dir/src/OpNovicePrimaryGeneratorAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ScintTutorial.dir/src/OpNovicePrimaryGeneratorAction.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/galgoczi/simulation/ScintTutorial/src/OpNovicePrimaryGeneratorAction.cc > CMakeFiles/ScintTutorial.dir/src/OpNovicePrimaryGeneratorAction.cc.i

CMakeFiles/ScintTutorial.dir/src/OpNovicePrimaryGeneratorAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ScintTutorial.dir/src/OpNovicePrimaryGeneratorAction.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/galgoczi/simulation/ScintTutorial/src/OpNovicePrimaryGeneratorAction.cc -o CMakeFiles/ScintTutorial.dir/src/OpNovicePrimaryGeneratorAction.cc.s

CMakeFiles/ScintTutorial.dir/src/OpNovicePrimaryGeneratorAction.cc.o.requires:

.PHONY : CMakeFiles/ScintTutorial.dir/src/OpNovicePrimaryGeneratorAction.cc.o.requires

CMakeFiles/ScintTutorial.dir/src/OpNovicePrimaryGeneratorAction.cc.o.provides: CMakeFiles/ScintTutorial.dir/src/OpNovicePrimaryGeneratorAction.cc.o.requires
	$(MAKE) -f CMakeFiles/ScintTutorial.dir/build.make CMakeFiles/ScintTutorial.dir/src/OpNovicePrimaryGeneratorAction.cc.o.provides.build
.PHONY : CMakeFiles/ScintTutorial.dir/src/OpNovicePrimaryGeneratorAction.cc.o.provides

CMakeFiles/ScintTutorial.dir/src/OpNovicePrimaryGeneratorAction.cc.o.provides.build: CMakeFiles/ScintTutorial.dir/src/OpNovicePrimaryGeneratorAction.cc.o


CMakeFiles/ScintTutorial.dir/src/OpNoviceRunAction.cc.o: CMakeFiles/ScintTutorial.dir/flags.make
CMakeFiles/ScintTutorial.dir/src/OpNoviceRunAction.cc.o: ../src/OpNoviceRunAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/galgoczi/simulation/ScintTutorial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/ScintTutorial.dir/src/OpNoviceRunAction.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ScintTutorial.dir/src/OpNoviceRunAction.cc.o -c /home/galgoczi/simulation/ScintTutorial/src/OpNoviceRunAction.cc

CMakeFiles/ScintTutorial.dir/src/OpNoviceRunAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ScintTutorial.dir/src/OpNoviceRunAction.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/galgoczi/simulation/ScintTutorial/src/OpNoviceRunAction.cc > CMakeFiles/ScintTutorial.dir/src/OpNoviceRunAction.cc.i

CMakeFiles/ScintTutorial.dir/src/OpNoviceRunAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ScintTutorial.dir/src/OpNoviceRunAction.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/galgoczi/simulation/ScintTutorial/src/OpNoviceRunAction.cc -o CMakeFiles/ScintTutorial.dir/src/OpNoviceRunAction.cc.s

CMakeFiles/ScintTutorial.dir/src/OpNoviceRunAction.cc.o.requires:

.PHONY : CMakeFiles/ScintTutorial.dir/src/OpNoviceRunAction.cc.o.requires

CMakeFiles/ScintTutorial.dir/src/OpNoviceRunAction.cc.o.provides: CMakeFiles/ScintTutorial.dir/src/OpNoviceRunAction.cc.o.requires
	$(MAKE) -f CMakeFiles/ScintTutorial.dir/build.make CMakeFiles/ScintTutorial.dir/src/OpNoviceRunAction.cc.o.provides.build
.PHONY : CMakeFiles/ScintTutorial.dir/src/OpNoviceRunAction.cc.o.provides

CMakeFiles/ScintTutorial.dir/src/OpNoviceRunAction.cc.o.provides.build: CMakeFiles/ScintTutorial.dir/src/OpNoviceRunAction.cc.o


CMakeFiles/ScintTutorial.dir/src/OpNoviceSteppingVerbose.cc.o: CMakeFiles/ScintTutorial.dir/flags.make
CMakeFiles/ScintTutorial.dir/src/OpNoviceSteppingVerbose.cc.o: ../src/OpNoviceSteppingVerbose.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/galgoczi/simulation/ScintTutorial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/ScintTutorial.dir/src/OpNoviceSteppingVerbose.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ScintTutorial.dir/src/OpNoviceSteppingVerbose.cc.o -c /home/galgoczi/simulation/ScintTutorial/src/OpNoviceSteppingVerbose.cc

CMakeFiles/ScintTutorial.dir/src/OpNoviceSteppingVerbose.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ScintTutorial.dir/src/OpNoviceSteppingVerbose.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/galgoczi/simulation/ScintTutorial/src/OpNoviceSteppingVerbose.cc > CMakeFiles/ScintTutorial.dir/src/OpNoviceSteppingVerbose.cc.i

CMakeFiles/ScintTutorial.dir/src/OpNoviceSteppingVerbose.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ScintTutorial.dir/src/OpNoviceSteppingVerbose.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/galgoczi/simulation/ScintTutorial/src/OpNoviceSteppingVerbose.cc -o CMakeFiles/ScintTutorial.dir/src/OpNoviceSteppingVerbose.cc.s

CMakeFiles/ScintTutorial.dir/src/OpNoviceSteppingVerbose.cc.o.requires:

.PHONY : CMakeFiles/ScintTutorial.dir/src/OpNoviceSteppingVerbose.cc.o.requires

CMakeFiles/ScintTutorial.dir/src/OpNoviceSteppingVerbose.cc.o.provides: CMakeFiles/ScintTutorial.dir/src/OpNoviceSteppingVerbose.cc.o.requires
	$(MAKE) -f CMakeFiles/ScintTutorial.dir/build.make CMakeFiles/ScintTutorial.dir/src/OpNoviceSteppingVerbose.cc.o.provides.build
.PHONY : CMakeFiles/ScintTutorial.dir/src/OpNoviceSteppingVerbose.cc.o.provides

CMakeFiles/ScintTutorial.dir/src/OpNoviceSteppingVerbose.cc.o.provides.build: CMakeFiles/ScintTutorial.dir/src/OpNoviceSteppingVerbose.cc.o


CMakeFiles/ScintTutorial.dir/src/OpNovicePhysicsList.cc.o: CMakeFiles/ScintTutorial.dir/flags.make
CMakeFiles/ScintTutorial.dir/src/OpNovicePhysicsList.cc.o: ../src/OpNovicePhysicsList.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/galgoczi/simulation/ScintTutorial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/ScintTutorial.dir/src/OpNovicePhysicsList.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ScintTutorial.dir/src/OpNovicePhysicsList.cc.o -c /home/galgoczi/simulation/ScintTutorial/src/OpNovicePhysicsList.cc

CMakeFiles/ScintTutorial.dir/src/OpNovicePhysicsList.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ScintTutorial.dir/src/OpNovicePhysicsList.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/galgoczi/simulation/ScintTutorial/src/OpNovicePhysicsList.cc > CMakeFiles/ScintTutorial.dir/src/OpNovicePhysicsList.cc.i

CMakeFiles/ScintTutorial.dir/src/OpNovicePhysicsList.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ScintTutorial.dir/src/OpNovicePhysicsList.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/galgoczi/simulation/ScintTutorial/src/OpNovicePhysicsList.cc -o CMakeFiles/ScintTutorial.dir/src/OpNovicePhysicsList.cc.s

CMakeFiles/ScintTutorial.dir/src/OpNovicePhysicsList.cc.o.requires:

.PHONY : CMakeFiles/ScintTutorial.dir/src/OpNovicePhysicsList.cc.o.requires

CMakeFiles/ScintTutorial.dir/src/OpNovicePhysicsList.cc.o.provides: CMakeFiles/ScintTutorial.dir/src/OpNovicePhysicsList.cc.o.requires
	$(MAKE) -f CMakeFiles/ScintTutorial.dir/build.make CMakeFiles/ScintTutorial.dir/src/OpNovicePhysicsList.cc.o.provides.build
.PHONY : CMakeFiles/ScintTutorial.dir/src/OpNovicePhysicsList.cc.o.provides

CMakeFiles/ScintTutorial.dir/src/OpNovicePhysicsList.cc.o.provides.build: CMakeFiles/ScintTutorial.dir/src/OpNovicePhysicsList.cc.o


CMakeFiles/ScintTutorial.dir/src/OpNoviceStackingAction.cc.o: CMakeFiles/ScintTutorial.dir/flags.make
CMakeFiles/ScintTutorial.dir/src/OpNoviceStackingAction.cc.o: ../src/OpNoviceStackingAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/galgoczi/simulation/ScintTutorial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/ScintTutorial.dir/src/OpNoviceStackingAction.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ScintTutorial.dir/src/OpNoviceStackingAction.cc.o -c /home/galgoczi/simulation/ScintTutorial/src/OpNoviceStackingAction.cc

CMakeFiles/ScintTutorial.dir/src/OpNoviceStackingAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ScintTutorial.dir/src/OpNoviceStackingAction.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/galgoczi/simulation/ScintTutorial/src/OpNoviceStackingAction.cc > CMakeFiles/ScintTutorial.dir/src/OpNoviceStackingAction.cc.i

CMakeFiles/ScintTutorial.dir/src/OpNoviceStackingAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ScintTutorial.dir/src/OpNoviceStackingAction.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/galgoczi/simulation/ScintTutorial/src/OpNoviceStackingAction.cc -o CMakeFiles/ScintTutorial.dir/src/OpNoviceStackingAction.cc.s

CMakeFiles/ScintTutorial.dir/src/OpNoviceStackingAction.cc.o.requires:

.PHONY : CMakeFiles/ScintTutorial.dir/src/OpNoviceStackingAction.cc.o.requires

CMakeFiles/ScintTutorial.dir/src/OpNoviceStackingAction.cc.o.provides: CMakeFiles/ScintTutorial.dir/src/OpNoviceStackingAction.cc.o.requires
	$(MAKE) -f CMakeFiles/ScintTutorial.dir/build.make CMakeFiles/ScintTutorial.dir/src/OpNoviceStackingAction.cc.o.provides.build
.PHONY : CMakeFiles/ScintTutorial.dir/src/OpNoviceStackingAction.cc.o.provides

CMakeFiles/ScintTutorial.dir/src/OpNoviceStackingAction.cc.o.provides.build: CMakeFiles/ScintTutorial.dir/src/OpNoviceStackingAction.cc.o


CMakeFiles/ScintTutorial.dir/src/OpNovicePrimaryGeneratorMessenger.cc.o: CMakeFiles/ScintTutorial.dir/flags.make
CMakeFiles/ScintTutorial.dir/src/OpNovicePrimaryGeneratorMessenger.cc.o: ../src/OpNovicePrimaryGeneratorMessenger.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/galgoczi/simulation/ScintTutorial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/ScintTutorial.dir/src/OpNovicePrimaryGeneratorMessenger.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ScintTutorial.dir/src/OpNovicePrimaryGeneratorMessenger.cc.o -c /home/galgoczi/simulation/ScintTutorial/src/OpNovicePrimaryGeneratorMessenger.cc

CMakeFiles/ScintTutorial.dir/src/OpNovicePrimaryGeneratorMessenger.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ScintTutorial.dir/src/OpNovicePrimaryGeneratorMessenger.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/galgoczi/simulation/ScintTutorial/src/OpNovicePrimaryGeneratorMessenger.cc > CMakeFiles/ScintTutorial.dir/src/OpNovicePrimaryGeneratorMessenger.cc.i

CMakeFiles/ScintTutorial.dir/src/OpNovicePrimaryGeneratorMessenger.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ScintTutorial.dir/src/OpNovicePrimaryGeneratorMessenger.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/galgoczi/simulation/ScintTutorial/src/OpNovicePrimaryGeneratorMessenger.cc -o CMakeFiles/ScintTutorial.dir/src/OpNovicePrimaryGeneratorMessenger.cc.s

CMakeFiles/ScintTutorial.dir/src/OpNovicePrimaryGeneratorMessenger.cc.o.requires:

.PHONY : CMakeFiles/ScintTutorial.dir/src/OpNovicePrimaryGeneratorMessenger.cc.o.requires

CMakeFiles/ScintTutorial.dir/src/OpNovicePrimaryGeneratorMessenger.cc.o.provides: CMakeFiles/ScintTutorial.dir/src/OpNovicePrimaryGeneratorMessenger.cc.o.requires
	$(MAKE) -f CMakeFiles/ScintTutorial.dir/build.make CMakeFiles/ScintTutorial.dir/src/OpNovicePrimaryGeneratorMessenger.cc.o.provides.build
.PHONY : CMakeFiles/ScintTutorial.dir/src/OpNovicePrimaryGeneratorMessenger.cc.o.provides

CMakeFiles/ScintTutorial.dir/src/OpNovicePrimaryGeneratorMessenger.cc.o.provides.build: CMakeFiles/ScintTutorial.dir/src/OpNovicePrimaryGeneratorMessenger.cc.o


# Object files for target ScintTutorial
ScintTutorial_OBJECTS = \
"CMakeFiles/ScintTutorial.dir/OpNovice.cc.o" \
"CMakeFiles/ScintTutorial.dir/src/OpNoviceActionInitialization.cc.o" \
"CMakeFiles/ScintTutorial.dir/src/OpNoviceDetectorConstruction.cc.o" \
"CMakeFiles/ScintTutorial.dir/src/OpNoviceSteppingAction.cc.o" \
"CMakeFiles/ScintTutorial.dir/src/OpNovicePhysicsListMessenger.cc.o" \
"CMakeFiles/ScintTutorial.dir/src/OpNovicePrimaryGeneratorAction.cc.o" \
"CMakeFiles/ScintTutorial.dir/src/OpNoviceRunAction.cc.o" \
"CMakeFiles/ScintTutorial.dir/src/OpNoviceSteppingVerbose.cc.o" \
"CMakeFiles/ScintTutorial.dir/src/OpNovicePhysicsList.cc.o" \
"CMakeFiles/ScintTutorial.dir/src/OpNoviceStackingAction.cc.o" \
"CMakeFiles/ScintTutorial.dir/src/OpNovicePrimaryGeneratorMessenger.cc.o"

# External object files for target ScintTutorial
ScintTutorial_EXTERNAL_OBJECTS =

ScintTutorial: CMakeFiles/ScintTutorial.dir/OpNovice.cc.o
ScintTutorial: CMakeFiles/ScintTutorial.dir/src/OpNoviceActionInitialization.cc.o
ScintTutorial: CMakeFiles/ScintTutorial.dir/src/OpNoviceDetectorConstruction.cc.o
ScintTutorial: CMakeFiles/ScintTutorial.dir/src/OpNoviceSteppingAction.cc.o
ScintTutorial: CMakeFiles/ScintTutorial.dir/src/OpNovicePhysicsListMessenger.cc.o
ScintTutorial: CMakeFiles/ScintTutorial.dir/src/OpNovicePrimaryGeneratorAction.cc.o
ScintTutorial: CMakeFiles/ScintTutorial.dir/src/OpNoviceRunAction.cc.o
ScintTutorial: CMakeFiles/ScintTutorial.dir/src/OpNoviceSteppingVerbose.cc.o
ScintTutorial: CMakeFiles/ScintTutorial.dir/src/OpNovicePhysicsList.cc.o
ScintTutorial: CMakeFiles/ScintTutorial.dir/src/OpNoviceStackingAction.cc.o
ScintTutorial: CMakeFiles/ScintTutorial.dir/src/OpNovicePrimaryGeneratorMessenger.cc.o
ScintTutorial: CMakeFiles/ScintTutorial.dir/build.make
ScintTutorial: /home/galgoczi/ess/geant/lib/libG4Tree.so
ScintTutorial: /home/galgoczi/ess/geant/lib/libG4GMocren.so
ScintTutorial: /home/galgoczi/ess/geant/lib/libG4visHepRep.so
ScintTutorial: /home/galgoczi/ess/geant/lib/libG4RayTracer.so
ScintTutorial: /home/galgoczi/ess/geant/lib/libG4VRML.so
ScintTutorial: /home/galgoczi/ess/geant/lib/libG4OpenGL.so
ScintTutorial: /home/galgoczi/ess/geant/lib/libG4gl2ps.so
ScintTutorial: /home/galgoczi/ess/geant/lib/libG4interfaces.so
ScintTutorial: /home/galgoczi/ess/geant/lib/libG4persistency.so
ScintTutorial: /home/galgoczi/ess/geant/lib/libG4analysis.so
ScintTutorial: /home/galgoczi/ess/geant/lib/libG4error_propagation.so
ScintTutorial: /home/galgoczi/ess/geant/lib/libG4readout.so
ScintTutorial: /home/galgoczi/ess/geant/lib/libG4physicslists.so
ScintTutorial: /home/galgoczi/ess/geant/lib/libG4parmodels.so
ScintTutorial: /home/galgoczi/ess/geant/lib/libG4FR.so
ScintTutorial: /home/galgoczi/ess/geant/lib/libG4vis_management.so
ScintTutorial: /home/galgoczi/ess/geant/lib/libG4modeling.so
ScintTutorial: /usr/lib/x86_64-linux-gnu/libXm.so
ScintTutorial: /usr/lib/x86_64-linux-gnu/libSM.so
ScintTutorial: /usr/lib/x86_64-linux-gnu/libICE.so
ScintTutorial: /usr/lib/x86_64-linux-gnu/libX11.so
ScintTutorial: /usr/lib/x86_64-linux-gnu/libXext.so
ScintTutorial: /usr/lib/x86_64-linux-gnu/libXmu.so
ScintTutorial: /usr/lib/x86_64-linux-gnu/libGLU.so
ScintTutorial: /usr/lib/x86_64-linux-gnu/libGL.so
ScintTutorial: /usr/lib/x86_64-linux-gnu/libQtOpenGL.so
ScintTutorial: /usr/lib/x86_64-linux-gnu/libQtGui.so
ScintTutorial: /usr/lib/x86_64-linux-gnu/libQtCore.so
ScintTutorial: /usr/lib/x86_64-linux-gnu/libxerces-c.so
ScintTutorial: /home/galgoczi/ess/geant/lib/libG4run.so
ScintTutorial: /home/galgoczi/ess/geant/lib/libG4event.so
ScintTutorial: /home/galgoczi/ess/geant/lib/libG4tracking.so
ScintTutorial: /home/galgoczi/ess/geant/lib/libG4processes.so
ScintTutorial: /home/galgoczi/ess/geant/lib/libG4zlib.so
ScintTutorial: /usr/lib/x86_64-linux-gnu/libexpat.so
ScintTutorial: /home/galgoczi/ess/geant/lib/libG4digits_hits.so
ScintTutorial: /home/galgoczi/ess/geant/lib/libG4track.so
ScintTutorial: /home/galgoczi/ess/geant/lib/libG4particles.so
ScintTutorial: /home/galgoczi/ess/geant/lib/libG4geometry.so
ScintTutorial: /home/galgoczi/ess/geant/lib/libG4materials.so
ScintTutorial: /home/galgoczi/ess/geant/lib/libG4graphics_reps.so
ScintTutorial: /home/galgoczi/ess/geant/lib/libG4intercoms.so
ScintTutorial: /home/galgoczi/ess/geant/lib/libG4global.so
ScintTutorial: /home/galgoczi/ess/geant/lib/libG4clhep.so
ScintTutorial: CMakeFiles/ScintTutorial.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/galgoczi/simulation/ScintTutorial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable ScintTutorial"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ScintTutorial.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ScintTutorial.dir/build: ScintTutorial

.PHONY : CMakeFiles/ScintTutorial.dir/build

CMakeFiles/ScintTutorial.dir/requires: CMakeFiles/ScintTutorial.dir/OpNovice.cc.o.requires
CMakeFiles/ScintTutorial.dir/requires: CMakeFiles/ScintTutorial.dir/src/OpNoviceActionInitialization.cc.o.requires
CMakeFiles/ScintTutorial.dir/requires: CMakeFiles/ScintTutorial.dir/src/OpNoviceDetectorConstruction.cc.o.requires
CMakeFiles/ScintTutorial.dir/requires: CMakeFiles/ScintTutorial.dir/src/OpNoviceSteppingAction.cc.o.requires
CMakeFiles/ScintTutorial.dir/requires: CMakeFiles/ScintTutorial.dir/src/OpNovicePhysicsListMessenger.cc.o.requires
CMakeFiles/ScintTutorial.dir/requires: CMakeFiles/ScintTutorial.dir/src/OpNovicePrimaryGeneratorAction.cc.o.requires
CMakeFiles/ScintTutorial.dir/requires: CMakeFiles/ScintTutorial.dir/src/OpNoviceRunAction.cc.o.requires
CMakeFiles/ScintTutorial.dir/requires: CMakeFiles/ScintTutorial.dir/src/OpNoviceSteppingVerbose.cc.o.requires
CMakeFiles/ScintTutorial.dir/requires: CMakeFiles/ScintTutorial.dir/src/OpNovicePhysicsList.cc.o.requires
CMakeFiles/ScintTutorial.dir/requires: CMakeFiles/ScintTutorial.dir/src/OpNoviceStackingAction.cc.o.requires
CMakeFiles/ScintTutorial.dir/requires: CMakeFiles/ScintTutorial.dir/src/OpNovicePrimaryGeneratorMessenger.cc.o.requires

.PHONY : CMakeFiles/ScintTutorial.dir/requires

CMakeFiles/ScintTutorial.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ScintTutorial.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ScintTutorial.dir/clean

CMakeFiles/ScintTutorial.dir/depend:
	cd /home/galgoczi/simulation/ScintTutorial/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/galgoczi/simulation/ScintTutorial /home/galgoczi/simulation/ScintTutorial /home/galgoczi/simulation/ScintTutorial/build /home/galgoczi/simulation/ScintTutorial/build /home/galgoczi/simulation/ScintTutorial/build/CMakeFiles/ScintTutorial.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ScintTutorial.dir/depend

