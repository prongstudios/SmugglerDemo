COMPILER = g++
build: main.cpp
	${COMPILER} main.cpp `sdl-config --libs --cflags` -lSDL_image -lSDL_ttf -o Smuggler
clean: 
	rm -f Smuggler
latest:
	tar -c --exclude '.git' /Users/will/ProgrammingFun/CPP/SDL/SmuggleDemo | gzip > /Users/will/ProgrammingFun/CPP/SDL/latest.tar.gz
