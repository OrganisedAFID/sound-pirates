# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pi/sound-pirates/Urho3D/splash

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/sound-pirates/Urho3D/splash_build

# Include any dependencies generated for this target.
include CMakeFiles/Splash.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Splash.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Splash.dir/flags.make

CMakeFiles/Splash.dir/RtAudio.cpp.o: CMakeFiles/Splash.dir/flags.make
CMakeFiles/Splash.dir/RtAudio.cpp.o: /home/pi/sound-pirates/Urho3D/splash/RtAudio.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/sound-pirates/Urho3D/splash_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Splash.dir/RtAudio.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Splash.dir/RtAudio.cpp.o -c /home/pi/sound-pirates/Urho3D/splash/RtAudio.cpp

CMakeFiles/Splash.dir/RtAudio.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Splash.dir/RtAudio.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/sound-pirates/Urho3D/splash/RtAudio.cpp > CMakeFiles/Splash.dir/RtAudio.cpp.i

CMakeFiles/Splash.dir/RtAudio.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Splash.dir/RtAudio.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/sound-pirates/Urho3D/splash/RtAudio.cpp -o CMakeFiles/Splash.dir/RtAudio.cpp.s

CMakeFiles/Splash.dir/defineNote.cpp.o: CMakeFiles/Splash.dir/flags.make
CMakeFiles/Splash.dir/defineNote.cpp.o: /home/pi/sound-pirates/Urho3D/splash/defineNote.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/sound-pirates/Urho3D/splash_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Splash.dir/defineNote.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Splash.dir/defineNote.cpp.o -c /home/pi/sound-pirates/Urho3D/splash/defineNote.cpp

CMakeFiles/Splash.dir/defineNote.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Splash.dir/defineNote.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/sound-pirates/Urho3D/splash/defineNote.cpp > CMakeFiles/Splash.dir/defineNote.cpp.i

CMakeFiles/Splash.dir/defineNote.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Splash.dir/defineNote.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/sound-pirates/Urho3D/splash/defineNote.cpp -o CMakeFiles/Splash.dir/defineNote.cpp.s

CMakeFiles/Splash.dir/fft.cpp.o: CMakeFiles/Splash.dir/flags.make
CMakeFiles/Splash.dir/fft.cpp.o: /home/pi/sound-pirates/Urho3D/splash/fft.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/sound-pirates/Urho3D/splash_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Splash.dir/fft.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Splash.dir/fft.cpp.o -c /home/pi/sound-pirates/Urho3D/splash/fft.cpp

CMakeFiles/Splash.dir/fft.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Splash.dir/fft.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/sound-pirates/Urho3D/splash/fft.cpp > CMakeFiles/Splash.dir/fft.cpp.i

CMakeFiles/Splash.dir/fft.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Splash.dir/fft.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/sound-pirates/Urho3D/splash/fft.cpp -o CMakeFiles/Splash.dir/fft.cpp.s

CMakeFiles/Splash.dir/instructionsStatements.cpp.o: CMakeFiles/Splash.dir/flags.make
CMakeFiles/Splash.dir/instructionsStatements.cpp.o: /home/pi/sound-pirates/Urho3D/splash/instructionsStatements.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/sound-pirates/Urho3D/splash_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Splash.dir/instructionsStatements.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Splash.dir/instructionsStatements.cpp.o -c /home/pi/sound-pirates/Urho3D/splash/instructionsStatements.cpp

CMakeFiles/Splash.dir/instructionsStatements.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Splash.dir/instructionsStatements.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/sound-pirates/Urho3D/splash/instructionsStatements.cpp > CMakeFiles/Splash.dir/instructionsStatements.cpp.i

CMakeFiles/Splash.dir/instructionsStatements.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Splash.dir/instructionsStatements.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/sound-pirates/Urho3D/splash/instructionsStatements.cpp -o CMakeFiles/Splash.dir/instructionsStatements.cpp.s

CMakeFiles/Splash.dir/playNote.cpp.o: CMakeFiles/Splash.dir/flags.make
CMakeFiles/Splash.dir/playNote.cpp.o: /home/pi/sound-pirates/Urho3D/splash/playNote.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/sound-pirates/Urho3D/splash_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Splash.dir/playNote.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Splash.dir/playNote.cpp.o -c /home/pi/sound-pirates/Urho3D/splash/playNote.cpp

CMakeFiles/Splash.dir/playNote.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Splash.dir/playNote.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/sound-pirates/Urho3D/splash/playNote.cpp > CMakeFiles/Splash.dir/playNote.cpp.i

CMakeFiles/Splash.dir/playNote.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Splash.dir/playNote.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/sound-pirates/Urho3D/splash/playNote.cpp -o CMakeFiles/Splash.dir/playNote.cpp.s

CMakeFiles/Splash.dir/splash.cpp.o: CMakeFiles/Splash.dir/flags.make
CMakeFiles/Splash.dir/splash.cpp.o: /home/pi/sound-pirates/Urho3D/splash/splash.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/sound-pirates/Urho3D/splash_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Splash.dir/splash.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Splash.dir/splash.cpp.o -c /home/pi/sound-pirates/Urho3D/splash/splash.cpp

CMakeFiles/Splash.dir/splash.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Splash.dir/splash.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/sound-pirates/Urho3D/splash/splash.cpp > CMakeFiles/Splash.dir/splash.cpp.i

CMakeFiles/Splash.dir/splash.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Splash.dir/splash.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/sound-pirates/Urho3D/splash/splash.cpp -o CMakeFiles/Splash.dir/splash.cpp.s

# Object files for target Splash
Splash_OBJECTS = \
"CMakeFiles/Splash.dir/RtAudio.cpp.o" \
"CMakeFiles/Splash.dir/defineNote.cpp.o" \
"CMakeFiles/Splash.dir/fft.cpp.o" \
"CMakeFiles/Splash.dir/instructionsStatements.cpp.o" \
"CMakeFiles/Splash.dir/playNote.cpp.o" \
"CMakeFiles/Splash.dir/splash.cpp.o"

# External object files for target Splash
Splash_EXTERNAL_OBJECTS =

bin/Splash: CMakeFiles/Splash.dir/RtAudio.cpp.o
bin/Splash: CMakeFiles/Splash.dir/defineNote.cpp.o
bin/Splash: CMakeFiles/Splash.dir/fft.cpp.o
bin/Splash: CMakeFiles/Splash.dir/instructionsStatements.cpp.o
bin/Splash: CMakeFiles/Splash.dir/playNote.cpp.o
bin/Splash: CMakeFiles/Splash.dir/splash.cpp.o
bin/Splash: CMakeFiles/Splash.dir/build.make
bin/Splash: /opt/vc/lib/libbcm_host.so
bin/Splash: /usr/lib/arm-linux-gnueabihf/libEGL.so
bin/Splash: /usr/lib/arm-linux-gnueabihf/libGLESv2.so
bin/Splash: /home/pi/Uhro/Urho3D/lib/libUrho3D.a
bin/Splash: /usr/lib/arm-linux-gnueabihf/libsfml-system.so
bin/Splash: /usr/lib/arm-linux-gnueabihf/libsfml-window.so
bin/Splash: /usr/lib/arm-linux-gnueabihf/libsfml-graphics.so
bin/Splash: /usr/lib/arm-linux-gnueabihf/libsfml-network.so
bin/Splash: /usr/lib/arm-linux-gnueabihf/libsfml-audio.so
bin/Splash: CMakeFiles/Splash.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/sound-pirates/Urho3D/splash_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable bin/Splash"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Splash.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Splash.dir/build: bin/Splash

.PHONY : CMakeFiles/Splash.dir/build

CMakeFiles/Splash.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Splash.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Splash.dir/clean

CMakeFiles/Splash.dir/depend:
	cd /home/pi/sound-pirates/Urho3D/splash_build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/sound-pirates/Urho3D/splash /home/pi/sound-pirates/Urho3D/splash /home/pi/sound-pirates/Urho3D/splash_build /home/pi/sound-pirates/Urho3D/splash_build /home/pi/sound-pirates/Urho3D/splash_build/CMakeFiles/Splash.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Splash.dir/depend

