#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "timing.h"
#include "object.h"
#include "object.cpp"
#include "player.h"
#include "player.cpp"
#include "animate.cpp"
#include "mapmaker.cpp"
#include "handleinput.cpp"

#include <string>


// Game constraints
const int FPS = 60;
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 1024;
const int SCREEN_BPP = 32;
const int movementspeed = 2;
const int walkFrameInterval = 10;

int main(int argc, char *argv[])
{
	SDL_Surface *screen;
	SDL_Init(SDL_INIT_EVERYTHING);
    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_HWSURFACE);
	SDL_WM_SetCaption("Smuggler Demo", "Smuggler Demo");
	bool quit = false;
	// Rendering surfaces

	SDL_Surface *preBackground;
	
	SDL_Surface *background;
	
	
	Player player1("ana.png");
	

	SDL_Rect singleTile;
	
	singleTile.x = 0;
	singleTile.y = 0;
	singleTile.h = 100;
	singleTile.w = 100;
	
	
	
	
	int xvel = 0, yvel = 0;
	
	
	SDL_Surface *overlay = &map();
	SDL_SetColorKey(overlay, SDL_SRCCOLORKEY,0);
	Timer fps;
	int walkFrames = 2;
	
    preBackground = IMG_Load("backimage.png");

	background = SDL_DisplayFormat(preBackground);
	SDL_FreeSurface(preBackground);

	while(!quit){
		
		fps.start();
		quit = input(player1, movementspeed);
		walkFrames=animate(player1.getxvel(), player1.getyvel(), movementspeed, walkFrames, walkFrameInterval, player1);
		SDL_BlitSurface(background, NULL, screen, NULL);
		
		SDL_BlitSurface(&player1.image(), &player1.frame(), screen, &player1.location());
		SDL_BlitSurface(overlay, NULL, screen, NULL);
		SDL_Flip(screen);

		printf("Frames per second: %d\n", 1000/fps.get_ticks());
	if(fps.get_ticks() < 1000 / FPS)
	{
		SDL_Delay ((1000/FPS) - fps.get_ticks());
	}
	
	}
	SDL_FreeSurface(background);
    SDL_Quit();

}
