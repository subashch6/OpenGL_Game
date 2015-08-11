CC = g++

INCLUDES =  -I ../src/headers -I ../includes

DYNLIBS = ../windowsDynamic/glew32.dll ../WindowsDynamic/glfw3.dll

LIBPATHS = -L ../windowsLibs

STATLIBS = -lopengl32

CFLAGS = -c 

APPFLAGS = -std=gnu++11

RM = rm

VPATH = ../src/code/Entities:../src/code/Loading:../src/code/MainGame:../src/code/Math:../src/code/ParsingMech:../src/code/RenderMech:../src/code/ShaderMech:../src/code/Camera:../src/code/Models

DIRECTORIES = $(wildcard ../src/code/*/*.cpp)

FILES = $(notdir $(DIRECTORIES))

OFILES = $(patsubst %.cpp,%.o,$(FILES))

DEBUGFLAGS = -g

ALL: OpenGL_Game
	
OpenGL_Game: $(OFILES)
	$(CC) $(OFILES) $(DYNLIBS) $(LIBPATHS) $(STATLIBS) $(APPFLAGS) $(DEBUGFLAGS) -o OpenGL_Game.exe

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) $(DEBUGFLAGS) $< $(APPFLAGS) -o $@
	
clean: 
	$(RM) $(OFILES) OpenGL_Game.exe
