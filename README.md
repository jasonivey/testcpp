This is a C++ example project I use to test features and code within a small testable environment.  It includes a cmake 
build project and a Makefile build project.  I am currently forcing myself to use and learn the cmake environment so 
its more second nature to me again.

It should be noted that if you are using clang and boost on a Linux platform then be very wary.  The boost that is 
installed via apt-get is most likey (no always) compiled via G++ using the libstdc++.  This means when it has a source
file which defines a function that either takes/returns a std::string then it will be compiled using the libstdc++
definition of the std::string (those bits).  But when you compile the main.cpp and include the same boost header file
it will see the definition of the function with the std::string defined as the bits being as defined by libc++.
CORE DUMP!

Since cmake should not be placing the build artifacts within the source tree create a sibling directory outside the 
source tree and execute the commands to build:

If using the following testcpp directory:

~/code/test/testcpp
mkdir ~/code/test/build
cd ~/code/test/build
CC=clang CXX=clang++ cmake ../testcpp
make

