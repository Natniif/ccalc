CC = g++
# Compiler flags
CFLAGS = -Wall -std=c++11 
# Include directories
IDIR = -I./libs/GLFW/include -I/opt/homebrew/Cellar/freeglut/3.4.0/include
# Library directories
LDIR = -L./libs/GLFW/lib-arm64 -L/opt/homebrew/Cellar/freeglut/3.4.0/lib
# Libraries to link
LIBS = -lglfw3 -lglut -framework OpenGL -framework Cocoa -framework IOKit -framework CoreFoundation -framework CoreVideo

# Source files
SRCS = ccalc.cc maths.o

# Object files
OBJS = $(SRCS:.cc=.o)

# Executable
EXEC = ccalc

# Build rule
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(IDIR) $(LDIR) -o $@ $^ $(LIBS)

# Compile rule for cc files
%.o: %.cc
	$(CC) $(CFLAGS) $(IDIR) -c -o $@ $<

# Clean rule
clean:
	rm -f $(EXEC) $(OBJS)

