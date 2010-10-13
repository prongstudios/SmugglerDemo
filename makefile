COMPILER = g++
build: main.cpp
	${COMPILER} main.cpp `sdl-config --libs --cflags` -lSDL_image -lSDL_ttf -o Smuggler
debug: main.cpp
	${COMPILER} main.cpp `sdl-config --libs --cflags` -lSDL_image -lSDL_ttf -g -o Smuggler
clean: 
	rm -f Smuggler
latest:
	tar -c -C .. --exclude '.git' SmuggleDemo/ | gzip > /Users/will/ProgrammingFun/CPP/SDL/latest.tar.gz && scp /Users/will/ProgrammingFun/CPP/SDL/latest.tar.gz root@derbserv.org:/home/prongstu/public_html/smuggler/Edgelatest.tar.gz
bleeding:
	tar -c -C .. --exclude '.git' SmuggleDemo/ | gzip > /Users/will/ProgrammingFun/CPP/SDL/BleedingEdgelatest.tar.gz && scp /Users/will/ProgrammingFun/CPP/SDL/BleedingEdgelatest.tar.gz root@derbserv.org:/home/prongstu/public_html/smuggler/BleedingEdgelatest.tar.gz
windows:
	mingw32-c++ main.cpp -Xlinker -lmingw32 -lSDLmain -lSDL -lSDL_image -o Smuggler.exe
