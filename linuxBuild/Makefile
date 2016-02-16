CC = g++

INCLUDES =  -I ../src/headers -I ../includes

DYNLIBS = ../linuxDynamic/libGLEW.so

LIBPATHS = 

STATLIBS = -pthread -lGLEW -lGLU -lGL -lrt -lXrandr -lXxf86vm -lXi -lXinerama -lX11 -lXcursor -lglfw

CFLAGS = -c 

APPFLAGS = -std=gnu++11  -fopenmp

RM = rm

VPATH = ../src/code/Entities:../src/code/MainGame:../src/code/Utilities:../src/code/ParsingMech:../src/code/RenderMech:../src/code/ShaderMech:../src/code/Models

DIRECTORIES = $(wildcard ../src/code/*/*.cpp)

FILES = $(notdir $(DIRECTORIES))

OFILES = $(patsubst %.cpp,%.o,$(FILES))

DEBUGFLAGS = -g

ALL: OpenGL_Game
	
OpenGL_Game: $(OFILES)
	$(CC) $(OFILES) $(DYNLIBS) $(LIBPATHS) $(STATLIBS) $(APPFLAGS) $(DEBUGFLAGS) -o OpenGL_Game

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) $(DEBUGFLAGS) $< $(APPFLAGS) -o $@
	
clean: 
	$(RM) $(OFILES) OpenGL_Game
