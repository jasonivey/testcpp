.PHONY : preprocessor all clean

#------------------------------------------------------------------------------

APP_DIR             =$(shell pwd)
OS 					:=$(shell uname)
SOURCE              =main.cpp langcode-old.cpp langcode-new.cpp
PROGRAM_NAME        =test
PROGRAM_PATH        =$(APP_DIR)/$(PROGRAM_NAME)

INCLUDE_DIRS        =-I$(APP_DIR) 

# Common
#CXXFLAGS           +=-isystem$(BOOST_LIB)
#COMMON_FLAGS       =-DDEBUG -g -ggdb3 -O2 -fsanitize=memory -fno-omit-frame-pointer
#COMMON_FLAGS        =-DDEBUG -g -ggdb3 -O0 -std=c++14 -stdlib=libc++ -lcrypto -lssl

LIBRARIES           =

ifeq ($(OS),Darwin)
	CC              =clang
	CXX             =clang++
	COMMON_FLAGS    =-DDEBUG -g -ggdb3 -O0 -std=c++11 -stdlib=libc++ -Wall -Werror
	LIBRARY_DIR		=-L/usr/local/Cellar/boost/1.58.0/lib
	INCLUDE_DIRS    +=-I/usr/local/include
else
	#CC             =gcc-4.8
	#CXX            =g++-4.8
	#INCLUDE_DIRS    +=-isystem /usr/include/jsoncpp/
	CC              =clang-3.8
	CXX             =clang++-3.8
	#COMMON_FLAGS    =-DUSING_MAP -DTEST_NEW=1 -DDEBUG -xc++ -O3 -std=c++11 -Wall -Werror -Wno-unused-function
	#COMMON_FLAGS    =-DUSING_MAP_STR -DTEST_NEW=1 -DDEBUG -xc++ -O3 -std=c++11 -Wall -Werror -Wno-unused-function
	COMMON_FLAGS    =-DUSING_VECTOR -DTEST_NEW=1 -DDEBUG -xc++ -O3 -std=c++11 -Wall -Werror -Wno-unused-function
	#COMMON_FLAGS    =-DUSING_VECTOR_STR -DTEST_NEW=1 -DDEBUG -xc++ -O3 -std=c++11 -Wall -Werror -Wno-unused-function
	#COMMON_FLAGS    =-DUSING_DICT -DTEST_NEW=1 -DDEBUG -xc++ -O3 -std=c++11 -Wall -Werror -Wno-unused-function
	#COMMON_FLAGS    =-DUSING_DICT_STR -DTEST_NEW=1 -DDEBUG -xc++ -O3 -std=c++11 -Wall -Werror -Wno-unused-function
	
	# this is the one we use for gperf
	#COMMON_FLAGS    =-DTEST_OLD=1 -DMAX_ITERATIONS=10000 -DDEBUG -xc++ -O3 -std=c++11 -Wall -Werror -Wno-unused-function
	
	#COMMON_FLAGS    =-DTEST_NEW=1 -DMAX_ITERATIONS=1000000 -DNDEBUG -xc++ -O3 -std=c++11 -Wall -Werror -Wno-unused-function
	#COMMON_FLAGS    =-DTEST_OLD=1 -DMAX_ITERATIONS=1000000 -DNDEBUG -xc++ -O3 -std=c++11 -Wall -Werror -Wno-unused-function
	#COMMON_FLAGS    =-DUSING_DICT -DTEST_NEW=1 -DDEBUG -g -ggdb3 -O0 -std=c++11 -Wall -Werror -Wno-unused-function
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
