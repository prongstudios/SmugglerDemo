COMPILER = g++
build: main.cpp
	${COMPILER} main.cpp `sdl-config --libs --cflags` -lSDL_image -lSDL_ttf -o Smuggler
clean: 
	rm -f Smuggler
latest:
	tar -c -C .. --exclude '.git' SmuggleDemo/ | gzip > /Users/will/ProgrammingFun/CPP/SDL/latest.tar.gz && scp /Users/will/ProgrammingFun/CPP/SDL/latest.tar.gz root@derbserv.org:/home/prongstu/public_html/smuggler/latest.tar.gz
windows:
	mingw32-c++ main.cpp -Xlinker -lmingw32 -lSDLmain -lSDL -lSDL_image -o Smuggler.exe
