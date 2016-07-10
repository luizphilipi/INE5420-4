LIBS = -lGL -lGLU -lglut
INCLUDES = -I./usr/include/GL -Iinclude/
CC = g++
CPPFLAGS = -DGTEST_HAS_PTHREAD=0 -std=c++11
CXXFLAGS = -g
EXECUTABLE = cg

SRCS = *.cpp

all:
	g++ $(CPPFLAGS) $(SRCS) -o $(EXECUTABLE) $(INCLUDES) $(LIBS)
	@echo 'Build complete!'

clean:
	rm -rf $(EXECUTABLE)
