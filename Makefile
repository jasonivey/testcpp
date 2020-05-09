# vim: awa:sts=0:ts=4:sw=4:noet:cin:fdm=manual:tw=120:ft=make
.PHONY : print preprocessor all clean

#------------------------------------------------------------------------------
# Parameter: release=yes|No (i.e. No is the default if parameter is omitted
# Example "make release=yes"  	// Make the app with release mode optimizations
# Example "make"			  	// Make the app with debug mode optimizations
# Example "make release=no"   	// Make the app with debug mode optimizations
# Example "make release=true" 	// Make the app with release mode optimizations
# Example "make release=1"		// Make the app with release mode optimizations
# Example "make release=false"	// Make the app with debug mode optimizations
#------------------------------------------------------------------------------
export DEBUG_MODE=1
ifneq ($(strip $(release)),)
	release_type = $(shell echo $(release) | tr A-Z a-z)
	ifeq ($(release_type), 1)
		export DEBUG_MODE=0
	else ifeq ($(release_type), true)
		export DEBUG_MODE=0
	else ifeq ($(release_type), on)
		export DEBUG_MODE=0
	else ifeq ($(shell echo $(release_type) | cut -c1-1), y)
		export DEBUG_MODE=0
	endif
endif

#------------------------------------------------------------------------------
# Parameter: boost=yes|No (i.e. No is the default if parameter is omitted
# Example "make boost=yes"		// Make the app with boost linker path specified
# Example "make"				// Make the app with boost linker ommitted
# Example "make boost=1"		// Make the app with boost linker path specified
# Example "make boost=off"		// Make the app with boost linker ommitted
# Example "make boost=true"		// Make the app with boost linker path specified
#------------------------------------------------------------------------------
export BOOST_ENABLED=0
ifneq ($(strip $(boost)),)
	boost_type = $(shell echo $(boost) | tr A-Z a-z)
	ifeq ($(boost_type), 1)
		export BOOST_ENABLED=1
	else ifeq ($(boost_type), on)
		export BOOST_ENABLED=1
	else ifeq ($(shell echo $(boost_type) | cut -c1-1), y)
		export BOOST_ENABLED=1
	endif
endif

#------------------------------------------------------------------------------
# Parameter: std=<C/C++ standard> (i.e. defines what standard should be used
#   values:  no|none|-ansi|-std=c90|-std=iso9899:1990|-std=iso9899:199409|-std=c99|
#			-std=iso9899:1999|-std=c11|-std=iso9899:2011|-std=c17|-std=iso9899:2017|
#			-std=c2x|-ansi|-std=c++98|-std=gnu++98|-std=c++03|-std=c++11|-std=gnu++11|
#			-std=c++14|-std=gnu++14|-std=c++17|-std=gnu++17
#   if omitted -std defaults to -std=gnu++14
#
# Example "make std=c++11		// Make the app with C++11 support
# Example "make std=c++17		// Make the app with C++17 support
# Example "make"				// Make the app with the default GNU C++ 14 support
# Example "make std=default"	// Make the app with the default GNU C++ 14 support
# Example "make std=1"			// Make the app with the default GNU C++ 14 support
# Example "make std=0"			// Make the app without specifying a '-std='
# Example "make std=true"		// Make the app with the default GNU C++ 14 support
# Example "make std=false"		// Make the app without specifying a '-std='
# Example "make std=yes"		// Make the app with the default GNU C++ 14 support
# Example "make std=no"			// Make the app without specifying a '-std='
# Example "make std=none"		// Make the app without specifying a '-std='
#------------------------------------------------------------------------------
DEFAULT_CXX_STD=-std=gnu++14
export CXX_STD=$(DEFAULT_CXX_STD)
ifneq ($(strip $(std)),)
	std_type=$(shell echo $(std) | tr -d '[:space:]' | tr A-Z a-z)

	ifeq ($(shell echo $(std_type) | cut -c1-1), d)
		# std=d[efault]
		export CXX_STD=$(DEFAULT_CXX_STD)
	else ifeq ($(std_type), 1)
		# std=1
		export CXX_STD=$(DEFAULT_CXX_STD)
	else ifeq ($(std_type), 0)
		# std=0
		export CXX_STD=
	else ifeq ($(shell echo $(std_type) | cut -c1-1), t)
		# std=t[rue]
		export CXX_STD=$(DEFAULT_CXX_STD)
	else ifeq ($(shell echo $(std_type) | cut -c1-1), f)
		# std=f[alse]
		export CXX_STD=
	else ifeq ($(shell echo $(std_type) | cut -c1-1), y)
		# std=[Y]ES
		export CXX_STD=$(DEFAULT_CXX_STD)
	else ifeq ($(shell echo $(std_type) | cut -c1-1), n)
		# std=[n]o
		export CXX_STD=
	else
		export CXX_STD=-std=$(std_type)
	endif
endif

APP_DIR					=$(shell pwd)
OS						:=$(shell uname)
SOURCE					=main.cpp
PROGRAM_NAME			=test
PROGRAM_PATH			=$(APP_DIR)/$(PROGRAM_NAME)

INCLUDE_DIRS			=-I$(APP_DIR)

ifeq ($(BOOST_ENABLED), 1)
	ifeq ($(OS), Darwin)
		INCLUDE_DIRS	+= -isystem/usr/local/opt/boost/include/
		LIBRARY_DIRS	= -L/usr/local/opt/boost/lib/
	else
		INCLUDE_DIRS	+= -isystem/usr/include/
		LIBRARY_DIRS	= -L/lib/x86_64-linux-gnu/
	endif
endif


# Common
ifeq ($(DEBUG_MODE), 1)
	COMMON_FLAGS		= -DDEBUG -g -ggdb3 -O0 -fno-omit-frame-pointer
else
	COMMON_FLAGS 		= -O3 -msse4.2 -mtune=intel -m64 -ffast-math -fassociative-math
endif

SANITIZER_OPTIONS 		=-fsanitize=memory
CXXFLAGS				+= $(CXX_STD) -arch x86_64
#LIBRARIES				 ="-lpthreads"
#STATIC_LIBS			 ="<path>/libname.a"

ifeq ($(OS),Darwin)
	CC					=/usr/local/opt/llvm/bin/clang
	CXX					=/usr/local/opt/llvm/bin/clang++
	CXXFLAGS			+= -nostdinc++ -stdlib=libc++
	INCLUDE_DIRS		+= -I/usr/local/opt/llvm/include -isystem/usr/local/opt/llvm/include/c++/v1
	#LIBRARY_DIRS		+= "-L/usr/local/opt/llvm/lib -Wl,-rpath,/usr/local/opt/llvm/lib" -L/usr/local/opt/llvm/lib
	LIBRARY_DIRS		+= -L/usr/local/opt/llvm/lib
	LIBRARIES			+= -lc++abi
else
	CC					=gcc-4.8
	CXX					=g++-4.8
	#CXXFLAGS			+=
	#INCLUDE_DIRS		+=
	#LIBRARY_DIRS		+=
	#LIBRARIES			+=
endif

WARNING_FLAGS 			= -Weverything -Wall -Werror -Wold-style-cast -Wno-c++98-compat
FLAGS					= $(CXXFLAGS) $(COMMON_FLAGS) $(WARNING_FLAGS)

#------------------------------------------------------------------------------
print-%  : ; @echo $* = $($*)

all: $(PROGRAM_NAME)

preprocessor: main.cpp
	$(CXX) -E -C -P $(SOURCE) $(INCLUDE_DIRS) > main.i

$(PROGRAM_NAME): main.cpp
	$(CXX) $(FLAGS) $(LIBRARY_DIRS) $(SOURCE) $(LIBRARIES) $(INCLUDE_DIRS) $(STATIC_LIBS) -o $(PROGRAM_PATH)

clean:
	rm -f $(APP_DIR)/*.o $(PROGRAM_PATH)

