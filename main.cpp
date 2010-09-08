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
	
	
	Player player1("character.png");
	

	SDL_Rect singleTile;
	
	singleTile.x = 0;
	singleTile.y = 0;
	singleTile.h = 100;
	singleTile.w = 100;
	
	SDL_Event event;
	
	
	
	int xvel = 0, yvel = 0;
	
	
	SDL_Surface *overlay = &map();
	
	Timer fps;
	int walkFrames = 2;
	
    preBackground = IMG_Load("backimage.png");

	background = SDL_DisplayFormat(preBackground);
	SDL_FreeSurface(preBackground);

	while(!quit){
		
		fps.start();
		
		
		while (SDL_PollEvent(&event))
		{
			// if (event.type==SDL_QUIT){
			// 	Running=false;
			// }
			if (event.type == SDL_KEYDOWN)
			{
				switch(event.key.keysym.sym){
					case SDLK_LEFT:
						xvel = -movementspeed;
						break;
					case SDLK_RIGHT:
						xvel = movementspeed;
						break;
					case SDLK_UP:
						yvel = -movementspeed;
						break;
					case SDLK_DOWN:
						yvel = movementspeed;
						break;
					case SDLK_ESCAPE:
						quit=true;
						break;
					default:
					// do nothing
						break;
				}
			}
			if (event.type == SDL_KEYUP)
			{
				switch(event.key.keysym.sym){
					case SDLK_LEFT:
						xvel = 0;
						break;
					case SDLK_RIGHT:
						xvel = 0;
						break;
					case SDLK_UP:
						yvel = 0;
						break;
					case SDLK_DOWN:
						yvel = 0;
						break;
					case SDLK_ESCAPE:
						quit=true;
						break;
					default:
					// Do nothing
						break;
				}
			}
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}
		}
		walkFrames=animate(xvel, yvel, movementspeed, walkFrames, walkFrameInterval, player1);
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
