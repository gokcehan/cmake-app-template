CMake Application Template
==========================

This is a C++ application template with CMake.
It has a structure as such:

    .
    ├── bin
    ├── build
    ├── doc
    ├── lib
    ├── src
    │   ├── hello.cc
    │   ├── hello.h
    │   └── main.cc
    ├── test
    │   ├── hello.cc
    │   └── my_test.cc
    ├── CMakeLists.txt
    ├── configure
    ├── Doxyfile
    ├── Makefile
    └── README.txt

To get started simply run:

    ./configure
    make

Release and Debug Builds
------------------------

By default CMake uses neither optimization nor debug flags.
You can specify your build type using the standard `CMAKE_BUILD_TYPE` variable.
Set this variable to either `Debug` or `Release` to build accordingly:

    ./configure -DCMAKE_BUILD_TYPE=Debug
    make

Boost Test Library
------------------

In order to use boost tests turn on the `BOOST_TESTS` variable as such:

    ./configure -DBOOST_TESTS=ON
    make

You can then run the tests using:

    make test

Doxygen Documentation
---------------------

By default documentation generation is enabled when doxygen is installed on the system.
In order to generate documentation simply use the `doc` rule like so:

    make doc

Installation
------------

By default CMake tries to install at system directories which may require admin privileges.
You can specify a custom install prefix using `CMAKE_INSTALL_PREFIX` variable as such:

    ./configure -DCMAKE_INSTALL_PREFIX=../install
    make
    make install
