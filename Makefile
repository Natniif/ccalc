# Compiler
CC = g++
# Compiler flags
CFLAGS = -Wall -std=c++11
# GLFW library path
GLFW_INCLUDE_PATH = -I./libs/GLFW/include
GLFW_LIB_PATH = -L./libs/GLFW/lib-arm64
# Libraries to link
LIBS = -lglfw3

# Source files
SRCS = ccalc.cc maths.cc
# Object files
OBJS = $(SRCS:.cc=.o)
# Executable name
EXEC = ccalc

# Default target
all: $(EXEC)

# Linking object files
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(GLFW_LIB_PATH) -o $@ $^ $(LIBS)

# Compiling source files
%.o: %.cc
	$(CC) $(CFLAGS) $(GLFW_INCLUDE_PATH) -c -o $@ $<

# Cleaning up
clean:
	rm -f $(OBJS) $(EXEC)

