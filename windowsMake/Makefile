CC = g++

INCLUDES = -I src\headers\ -I includes\ 

DYNLIBS = windowsDynamic\glew32.dll WindowsDynamic\glfw3.dll

LIBPATHS = -L windowsLibs\

STATLIBS = -lopengl32

CFLAGS = -c 

APPFLAGS = -std=gnu++11 -o OpenGL_Game.exe


ALL: OpenGL_Game

OpenGL_Game: Entities Loading MainGame Math ParsingMech RenderMech
	$(CC) Entities Loading MainGame Math ParsingMech RenderMech $(DYNLIBS) $(INCLUDES) $(LIBPATHS) $(STATLIBS) $(APPFLAGS)

Entities: Entity.o 

Entity.o: Entity.cpp
	$(CC) $(CFLAGS) Entity.cpp

Loading: Loader.o

Loader.o: Loader.cpp
	$(CC) $(CFLAGS) Loader.cpp

MainGame: MainGame.o

MainGame.o: MainGame.cpp
	$(CC) $(CFLAGS) MainGame.cpp

Math: Matricies.o

Matricies.o: Matricies.cpp
	$(CC) $(CFLAGS) Matricies.cpp

ParsingMech: ModelParser.o

ModelParser.o: ModelParser.cpp
	$(CC) $(CFLAGS) ModelParser.cpp

RenderMech: Renderer.o

Renderer.o: Renderer.cpp
	$(CC) $(CFLAGS) Renderer.cpp

Clean: rm  *.o OpenGL_Game