all: exec

clean:
	rm -rf *.o

fclean: clean
	rm -rf exec

.PHONY: all clean

re: clean all

CXX = g++

CPPFLAGS =

CXXFLAGS = -std=c++11 -Wall -Werror -Wextra -g

LIBS = -I glfw/include/ -I glew/include -L glfw/lib -L glew/lib -lglfw -lGLEW \
	-framework OpenGL

LDFLAGS =

exec: tut01.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LIBS)
