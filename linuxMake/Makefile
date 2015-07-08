CC = g++

INCLUDES =  -I src/headers -I includes

DYNLIBS = linuxDynamic/libGLEW.so

LIBPATHS = 

STATLIBS = -lglfw3 -pthread -lGLEW -lGLU -lGL -lrt -lXrandr -lXxf86vm -lXi -lXinerama -lX11 -lXcursor

CFLAGS = -c 

APPFLAGS = -std=gnu++11

Entity.cpp = src/code/Entities/Entity.cpp

Loader.cpp = src/code/Loading/Loader.cpp

MainGameLoop.cpp = src/code/MainGame/MainGameLoop.cpp

Matricies.cpp = src/code/Math/Matricies.cpp

ModelParser.cpp = src/code/ParsingMech/ModelParser.cpp

Renderer.cpp = src/code/RenderMech/Renderer.cpp

AbstractShader.cpp = src/code/ShaderMech/AbstractShader.cpp

EntityShader.cpp = src/code/ShaderMech/EntityShader.cpp

RM = rm

ALL: OpenGL_Game

OpenGL_Game: Entities Loading MainGame Math ParsingMech RenderMech ShaderMech
	$(CC) *.o $(DYNLIBS) $(LIBPATHS) $(STATLIBS) $(APPFLAGS) -o OpenGL_Game

Entities: Entity.o 

Entity.o: $(Entity.cpp)
	$(CC) $(CFLAGS) $(INCLUDES) $(Entity.cpp) $(APPFLAGS)

Loading: Loader.o

Loader.o: $(Loader.cpp)
	$(CC) $(CFLAGS) $(INCLUDES) $(Loader.cpp) $(APPFLAGS)

MainGame: MainGameLoop.o

MainGameLoop.o: $(MainGameLoop.cpp)
	$(CC) $(CFLAGS) $(INCLUDES) $(MainGameLoop.cpp) $(APPFLAGS)

Math: Matricies.o

Matricies.o: $(Matricies.cpp)
	$(CC) $(CFLAGS) $(INCLUDES) $(Matricies.cpp) $(APPFLAGS)

ParsingMech: ModelParser.o

ModelParser.o: $(ModelParser.cpp)
	$(CC) $(CFLAGS) $(INCLUDES) $(ModelParser.cpp) $(APPFLAGS)

RenderMech: Renderer.o

Renderer.o: $(Renderer.cpp)
	$(CC) $(CFLAGS) $(INCLUDES) $(Renderer.cpp) $(APPFLAGS)

ShaderMech: AbstractShader.o EntityShader.o

AbstractShader.o: $(AbstractShader.cpp)
	$(CC) $(CFLAGS) $(INCLUDES) $(AbstractShader.cpp) $(APPFLAGS)

EntityShader.o: $(EntityShader.cpp)
	$(CC) $(CFLAGS) $(INCLUDES) $(EntityShader.cpp) $(APPFLAGS)
	
clean: 
	$(RM) *o OpenGL_Game

