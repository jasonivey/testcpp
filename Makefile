.PHONY : preprocessor all clean

#------------------------------------------------------------------------------

APP_DIR             =$(shell pwd)
OS 					:=$(shell uname)
SOURCE              =main.cpp
PROGRAM_NAME        =test
PROGRAM_PATH        =$(APP_DIR)/$(PROGRAM_NAME)

INCLUDE_DIRS        =-I$(APP_DIR) 

# Common
#CXXFLAGS           +=-isystem$(BOOST_LIB)
#COMMON_FLAGS       =-DDEBUG -g -ggdb3 -O2 -fsanitize=memory -fno-omit-frame-pointer
#COMMON_FLAGS        =-DDEBUG -g -ggdb3 -O0 -std=c++14 -stdlib=libc++ -lcrypto -lssl

#LIBRARIES           =-lboost_filesystem -lboost_system

ifeq ($(OS),Darwin)
	CC              =/usr/bin/clang
	CXX             =/usr/bin/clang++
	COMMON_FLAGS    =-DDEBUG -g -ggdb3 -O0 -nostdinc++ -std=c++17 -stdlib=libc++ -lc++abi -Weverything -Wall -Werror -Wold-style-cast
	LIBRARY_DIR		=-L/usr/local/opt/llvm/lib
	INCLUDE_DIRS    +=-isystem /usr/local/opt/llvm/include/c++/v1 -isystem /usr/local/include
else
	#CC             =gcc-4.8
	#CXX            =g++-4.8
	CC              =clang-6.0
	CXX             =clang++-6.0
	COMMON_FLAGS    =-DDEBUG -g -ggdb3 -O0 -std=c++11 -Wall -Werror- -Wold-style-cast
endif

FLAGS               =$(CXXFLAGS) $(COMMON_FLAGS)

#------------------------------------------------------------------------------

all: $(PROGRAM_NAME)

preprocessor: main.cpp
	$(CXX) -E -C -P $(SOURCE) $(INCLUDE_DIRS) > main.i

$(PROGRAM_NAME): main.cpp
	$(CXX) $(FLAGS) $(LIBRARY_DIR) $(SOURCE) $(LIBRARIES) $(INCLUDE_DIRS) $(STATIC_LIBS) -o $(PROGRAM_PATH)

clean:
	rm -f $(APP_DIR)/*.o $(PROGRAM_PATH)
