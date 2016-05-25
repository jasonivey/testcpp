.PHONY : preprocessor all clean

#------------------------------------------------------------------------------

APP_DIR             =$(shell pwd)

SOURCE              =main.cpp
PROGRAM_NAME        =test
PROGRAM_PATH        =$(APP_DIR)/$(PROGRAM_NAME)

#CC                 =gcc-4.8
#CXX                    =g++-4.8
CC                  =clang
CXX                 =clang++
INCLUDE_DIRS        =-I$(APP_DIR)

# Common
#CXXFLAGS           +=-isystem$(BOOST_LIB)
#COMMON_FLAGS       =-DDEBUG -g -ggdb3 -O2 -fsanitize=memory -fno-omit-frame-pointer
COMMON_FLAGS        =-DDEBUG -g -ggdb3 -O0 -std=c++14 -stdlib=libc++

FLAGS               =$(CXXFLAGS) $(COMMON_FLAGS)
LIBRARIES           =-lboost_filesystem -lboost_system
LIBRARY_DIR			=-L/usr/local/Cellar/boost/1.58.0/lib
INCLUDE_DIRS        +=-I/usr/local/include

#------------------------------------------------------------------------------

all: $(PROGRAM_NAME)

preprocessor: main.cpp
	$(CXX) -E -C -P $(SOURCE) $(INCLUDE_DIRS) > main.i

$(PROGRAM_NAME): main.cpp
	$(CXX) $(FLAGS) $(LIBRARY_DIR) $(SOURCE) $(LIBRARIES) $(INCLUDE_DIRS) $(STATIC_LIBS) -o $(PROGRAM_PATH)

clean:
	rm -f $(APP_DIR)/*.o $(PROGRAM_PATH)
