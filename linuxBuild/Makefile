CC = g++

INCLUDES =  -I src/headers -I includes

DYNLIBS = linuxDynamic/libGLEW.so

LIBPATHS = 

STATLIBS = -lglfw3 -pthread -lGLEW -lGLU -lGL -lrt -lXrandr -lXxf86vm -lXi -lXinerama -lX11 -lXcursor

CFLAGS = -c 

APPFLAGS = -std=gnu++11

RM = rm

VPATH = src/code/Entities:src/code/Loading:src/code/MainGame:src/code/Math:src/code/ParsingMech:src/code/RenderMech:src/code/ShaderMech

DIRECTORIES = $(wildcard src/code/*/*.cpp)

FILES = $(notdir $(DIRECTORIES))

OFILES = $(patsubst %.cpp,%.o,$(FILES))

ALL: OpenGL_Game
	
OpenGL_Game: $(OFILES)
	$(CC) $(OFILES) $(DYNLIBS) $(LIBPATHS) $(STATLIBS) $(APPFLAGS) -o OpenGL_Game

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) $< $(APPFLAGS) -o $@
	
clean: 
	$(RM) $(OFILES) OpenGL_Game
