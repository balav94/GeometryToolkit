# GeometryToolkit

## Project Overview

The GeometryToolkit is a C++ project that provides utilities for geometric calculations. The project includes source files, example applications, and test cases to demonstrate and validate the functionality of the toolkit.

## Prerequisites

Before you begin, ensure you have the following installed on your system:

- **C++ Compiler** (e.g., `g++` or `clang++`)
- **CMake** (version 3.10 or higher)

### Installing CMake

#### macOS
brew install cmake


## Building the Project

Follow these steps to build the project:

### Clone the Repository (if not already done):
git clone https://github.com/balav94/GeometryToolkit.git
cd GeometryToolkit

### Create a Build Directory:
mkdir build && cd build

### Generate the Build Files using CMake:
cmake ..

### Compile the Project:
make

The compiled binaries will be placed in the build/tests and build/examples directories.

## Running the Executables

After the project has been built, you can run the compiled binaries directly from the build directory:

### Running Examples
./build/examples/DistanceCalculator

### Running Tests
./build/tests/TestGeometryUtils
./build/tests/TestDegeneracy

## Cleaning Up

To remove the build files and binaries, simply delete the build directory:
rm -rf build
