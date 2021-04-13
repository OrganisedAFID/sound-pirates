# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/pi/sound-pirates/Urho3D/splash

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/sound-pirates/Urho3D/release_build

# Include any dependencies generated for this target.
include test/CMakeFiles/FFT_TEST.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/FFT_TEST.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/FFT_TEST.dir/flags.make

test/CMakeFiles/FFT_TEST.dir/fft_test.cpp.o: test/CMakeFiles/FFT_TEST.dir/flags.make
test/CMakeFiles/FFT_TEST.dir/fft_test.cpp.o: /home/pi/sound-pirates/Urho3D/splash/test/fft_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/sound-pirates/Urho3D/release_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/FFT_TEST.dir/fft_test.cpp.o"
	cd /home/pi/sound-pirates/Urho3D/release_build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FFT_TEST.dir/fft_test.cpp.o -c /home/pi/sound-pirates/Urho3D/splash/test/fft_test.cpp

test/CMakeFiles/FFT_TEST.dir/fft_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FFT_TEST.dir/fft_test.cpp.i"
	cd /home/pi/sound-pirates/Urho3D/release_build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/sound-pirates/Urho3D/splash/test/fft_test.cpp > CMakeFiles/FFT_TEST.dir/fft_test.cpp.i

test/CMakeFiles/FFT_TEST.dir/fft_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FFT_TEST.dir/fft_test.cpp.s"
	cd /home/pi/sound-pirates/Urho3D/release_build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/sound-pirates/Urho3D/splash/test/fft_test.cpp -o CMakeFiles/FFT_TEST.dir/fft_test.cpp.s

test/CMakeFiles/FFT_TEST.dir/__/fft.cpp.o: test/CMakeFiles/FFT_TEST.dir/flags.make
test/CMakeFiles/FFT_TEST.dir/__/fft.cpp.o: /home/pi/sound-pirates/Urho3D/splash/fft.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/sound-pirates/Urho3D/release_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/CMakeFiles/FFT_TEST.dir/__/fft.cpp.o"
	cd /home/pi/sound-pirates/Urho3D/release_build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FFT_TEST.dir/__/fft.cpp.o -c /home/pi/sound-pirates/Urho3D/splash/fft.cpp

test/CMakeFiles/FFT_TEST.dir/__/fft.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FFT_TEST.dir/__/fft.cpp.i"
	cd /home/pi/sound-pirates/Urho3D/release_build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/sound-pirates/Urho3D/splash/fft.cpp > CMakeFiles/FFT_TEST.dir/__/fft.cpp.i

test/CMakeFiles/FFT_TEST.dir/__/fft.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FFT_TEST.dir/__/fft.cpp.s"
	cd /home/pi/sound-pirates/Urho3D/release_build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/sound-pirates/Urho3D/splash/fft.cpp -o CMakeFiles/FFT_TEST.dir/__/fft.cpp.s

# Object files for target FFT_TEST
FFT_TEST_OBJECTS = \
"CMakeFiles/FFT_TEST.dir/fft_test.cpp.o" \
"CMakeFiles/FFT_TEST.dir/__/fft.cpp.o"

# External object files for target FFT_TEST
FFT_TEST_EXTERNAL_OBJECTS =

test/FFT_TEST: test/CMakeFiles/FFT_TEST.dir/fft_test.cpp.o
test/FFT_TEST: test/CMakeFiles/FFT_TEST.dir/__/fft.cpp.o
test/FFT_TEST: test/CMakeFiles/FFT_TEST.dir/build.make
test/FFT_TEST: /usr/lib/arm-linux-gnueabihf/libboost_filesystem.so
test/FFT_TEST: /usr/lib/arm-linux-gnueabihf/libboost_system.so
test/FFT_TEST: /usr/lib/arm-linux-gnueabihf/libboost_unit_test_framework.so
test/FFT_TEST: test/CMakeFiles/FFT_TEST.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/sound-pirates/Urho3D/release_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable FFT_TEST"
	cd /home/pi/sound-pirates/Urho3D/release_build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FFT_TEST.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/FFT_TEST.dir/build: test/FFT_TEST

.PHONY : test/CMakeFiles/FFT_TEST.dir/build

test/CMakeFiles/FFT_TEST.dir/clean:
	cd /home/pi/sound-pirates/Urho3D/release_build/test && $(CMAKE_COMMAND) -P CMakeFiles/FFT_TEST.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/FFT_TEST.dir/clean

test/CMakeFiles/FFT_TEST.dir/depend:
	cd /home/pi/sound-pirates/Urho3D/release_build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/sound-pirates/Urho3D/splash /home/pi/sound-pirates/Urho3D/splash/test /home/pi/sound-pirates/Urho3D/release_build /home/pi/sound-pirates/Urho3D/release_build/test /home/pi/sound-pirates/Urho3D/release_build/test/CMakeFiles/FFT_TEST.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/FFT_TEST.dir/depend

