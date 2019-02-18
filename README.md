cg-practice-cpp
===

<a href="http://opensource.org/licenses/MIT" target="_blank"><img src="http://img.shields.io/badge/license-MIT-brightgreen.png" alt="MIT license"></a> [![Build Status](https://travis-ci.org/asphaltbuffet/cg-practice-cpp.svg?branch=master)](https://travis-ci.org/asphaltbuffet/cg-practice-cpp)</a>[![Coverage Status](https://coveralls.io/repos/github/asphaltbuffet/cg-practice-cpp/badge.svg?branch=master)](https://coveralls.io/github/asphaltbuffet/cg-practice-cpp?branch=master)<a href="https://scan.coverity.com/projects/asphaltbuffet-cg-practice-cpp"><img alt="Coverity Scan Build Status" src="https://img.shields.io/coverity/scan/17709.svg"/></a>

`cg-practice-cpp` is a CMake-based C++ collection of problems from Codingame.com.

Features
------

  - General directory structure common to C++ projects
  - Unit testing framework ([Catch2](https://www.github.com/catchorg/Catch2 "Catch2 Github repository") or [GTest](https://github.com/google/googletest "Google Test Github repository"))
  - Install script (`make install`)
  - Uninstall script (`make uninstall`)
  - CPack script for packaging (`make package`)
  - Automatic API documentation ([Doxygen](http://www.doxygen.org "Doxygen homepage"))
  - Continuous Integration ([Travis CI](https://travis-ci.org/ "Travis CI homepage"))
  - Code coverage analysis ([Coveralls](https://coveralls.io "Coveralls.io homepage")) (`make coverage`)
  - Example of how to include external dependencies (using `ExternalProject` module)
  - Separate file to specify location of project files (`ProjectFiles.cmake`)

Requirements
------

To install this project, please ensure that you have installed the following (install guides are provided on the respective websites):

  - [Git](http://git-scm.com)
  - A C++ compiler, e.g., [GCC](https://gcc.gnu.org/), [clang](http://clang.llvm.org/), [MinGW](http://www.mingw.org/)
  - [CMake](http://www.cmake.org "CMake homepage")
  - [Doxygen](http://www.doxygen.org "Doxygen homepage") (optional)
  - [Gcov](https://gcc.gnu.org/onlinedocs/gcc/Gcov.html) (optional)
  - [LCOV](http://ltp.sourceforge.net/coverage/lcov.php) (optional)

The following dependencies are optional (see `Build options`):

  - [Catch2](https://www.github.com/catchorg/Catch2) (unit testing library necessary for `BUILD_TESTS` build option, with `TEST_FRAMEWORK=Catch2` (default))
  - [GTest](https://github.com/google/googletest) (alternate unit testing library necessary for `BUILD_TESTS` build option and `TEST_FRAMEWORK=GTest`)

These dependencies will be downloaded and configured automagically, if not already present locally (requires an internet connection).

Installation
------

Run the following commands to download, build, and install this project.

    git clone https://www.github.com/asphaltbuffet/cg-practice-cpp <project_name>
    cd <project_name>
    git submodule init && git submodule update
    mkdir build && cd build
    cmake -DPROJECT_NAME=cg-practice-cpp .. && cmake --build .

To install the header files and libraries, run the following from within the `build` directory:

    make install

Note that dependencies are installed by fetching them online, in case they cannot be detected on your local system. If the build process fails, check the error log given. Typically, building fails due to timeout. Simply run the `cmake --build .` command once more.

To uninstall all the files that were installed on your system, run the following from within the `build` directory:

    make uninstall

Note that this does not remove any dependencies that were automagically fetched and built.

Build options
-------------

You can pass the following, general command-line options when running CMake:

  - `-DPROJECT_SUMMARY`: set short string summary for your project
  - `-DPROJECT_VENDOR_NAME`: set short string name for vendor of your project
  - `-DPROJECT_VENDOR_CONTACT`: set short string email address for vendor of your project
  - `-DCMAKE_INSTALL_PREFIX[=$install_dir]`: set path prefix for install script (`make install`); if not set, defaults to usual locations
  - `-DBUILD_SHARED_LIBS=[ON|OFF (default)]`: build shared libraries instead of static
  - `-DBUILD_MAIN[=ON|OFF (default)]`: build the main-function
  - `-DBUILD_DOXYGEN_DOCS[=ON|OFF (default)]`: build the [Doxygen](http://www.doxygen.org "Doxygen homepage") documentation ([LaTeX](http://www.latex-project.org/) must be installed with `amsmath` package)
  - `-DBUILD_TESTS[=ON|OFF (default)]`: build tests (execute tests from build-directory using `ctest -V`)
  - `-DBUILD_DEPENDENCIES[=ON|OFF (default)]`: force local build of dependencies, instead of first searching system-wide using `find_package()`

The following commands are conditional and are only relevant if `BUILD_TESTS = ON`:

 - `-DBUILD_COVERAGE_ANALYSIS[=ON|OFF (default)]`: build code coverage using [Gcov](https://gcc.gnu.org/onlinedocs/gcc/Gcov.html) and [LCOV](http://ltp.sourceforge.net/coverage/lcov.php) (both must be installed; requires [GCC](https://gcc.gnu.org/) compiler; execute coverage analysis from build-directory using `make coverage`)
 - `-DTEST_FRAMEWORK=[=GTest|Catch2 (default)]`: set unit testting framework for your project

Pass these options either directly to the `cmake ..` command, e.g., to build the tests:

    cmake -DPROJECT_NAME=<project_name> -DBUILD_TESTS=on ..

N.B.: Toggling options to build tests using `ccmake` does not work correctly, as the necessarily libraries are not downloaded automagically!

Project structure
-------------

This project has been set up with a specific file/folder structure in mind. The following describes some important features of this setup:

  - `cmake/Modules` : Contains `CMake` modules
  - `docs`: Contains code documentation generated by [Doxygen](http://www.doxygen.org "Doxygen homepage")
  - `include`: Project header files (*.hpp)
  - `scripts`: Shell scripts used in [Travis CI](https://travis-ci.org/ "Travis CI homepage") build
  - `src`: Project source files (*.cpp), including `main.cpp`, which contains example main-function for project build
  - `test`: Project test source files (*.cpp) that are provided to the selecting unit testing framework
  - `.travis.yml`: Configuration file for [Travis CI](https://travis-ci.org/ "Travis CI homepage") build, including static analysis using [Coverity Scan](https://scan.coverity.com/ "Coverity Scan homepage") and code coverage using [Coveralls](https://coveralls.io "Coveralls.io homepage")
  - `CMakeLists.txt`: main `CMakelists.txt` file for project (should not need to be modified for basic build)
  - `Dependencies.cmake`: list of dependencies and automated build, triggered if dependency cannot be found locally
  - `Doxyfile.in`: [Doxygen](http://www.doxygen.org "Doxygen homepage") configuration file, adapted for generic use within project build (should not need to be modified)
  - `LICENSE.md`: license file for project (copyright statement needs to be edited)
  - `ProjectFiles.cmake`: list of project source files to build
  - `Uninstall.cmake.in`: uninstall configuration scrip, necessary for the `make uninstall` target

Disclaimer
------------

The copyright holders are not liable for any damage(s) incurred due to improper use of `cg-practice-cpp`.
