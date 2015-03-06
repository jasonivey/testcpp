This is a C++ example project I use to test features and code within a small testable environment.  It includes a cmake 
build project and a Makefile build project.  I am currently forcing myself to use and learn the cmake environment so 
its more second nature to me again.

Since cmake should not be placing the build artifacts within the source tree create a sibling directory outside the 
source tree and execute the commands to build:

If using the following testcpp directory:

~/code/test/testcpp
mkdir ~/code/test/build
cd ~/code/test/build
CC=clang CXX=clang++ cmake ../testcpp
make

