CC = g++

INCLUDES =  -I src/headers -I includes

DYNLIBS = linuxDynamic/libGLEW.so

LIBPATHS = 

STATLIBS = -lglfw3 -pthread -lGLEW -lGLU -lGL -lrt -lXrandr -lXxf86vm -lXi -lXinerama -lX11 -lXcursor

CFLAGS = -c 

APPFLAGS = -std=gnu++11

RM = rm
<<<<<<< HEAD
=======

ALL: OpenGL_Game

OpenGL_Game: Entities Loading MainGame Math ParsingMech RenderMech ShaderMech
	$(CC) *.o $(DYNLIBS) $(LIBPATHS) $(STATLIBS) $(APPFLAGS) -o OpenGL_Game

Entities: Entity.o 
>>>>>>> 10b85a9795a91326766ca78cfda01680b8e09703

VPATH = src/code/Entities:src/code/Loading:src/code/MainGame:src/code/Math:src/code/ParsingMech:src/code/RenderMech:src/code/ShaderMech

DIRECTORIES = $(wildcard src/code/*/*.cpp)

FILES = $(notdir $(DIRECTORIES))

OFILES = $(patsubst %.cpp,%.o,$(FILES))

ALL: OpenGL_Game
	
OpenGL_Game: $(OFILES)
	$(CC) $(OFILES) $(DYNLIBS) $(LIBPATHS) $(STATLIBS) $(APPFLAGS) -o OpenGL_Game.exe

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) $< $(APPFLAGS) -o $@
	
clean: 
<<<<<<< HEAD
	$(RM) $(OFILES) OpenGL_Game.exe
=======
	$(RM) *o OpenGL_Game
>>>>>>> 10b85a9795a91326766ca78cfda01680b8e09703
