#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "timing.h"
#include "object.h"


// Game constraints
const int FPS = 60;
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 1024;
const int SCREEN_BPP = 32;
const int movementspeed = 2;
const int walkFrameInterval = 10;




int main(int argc, char *argv[])
{
	bool quit = false;
	// Rendering surfaces

	SDL_Surface *preBackground;
	SDL_Surface *prePlayer;
	
	SDL_Surface *screen;
	SDL_Surface *background;
	SDL_Surface *player;
	
	// Object crate("crate.png");

	SDL_Event event;

	SDL_Rect player_coords;
    player_coords.x=500;
	player_coords.y=200;
	player_coords.w=100;
	player_coords.h=100;
	
	SDL_Rect player_frame;
	player_frame.x = 0;
	player_frame.y = 0;
	player_frame.w = 200;
	player_frame.h = 200;
	
	int walkFrames =40;
	
	
	int xvel = 0, yvel = 0;
	
	
	Timer fps;
	
    SDL_Init(SDL_INIT_EVERYTHING);
    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
    preBackground = IMG_Load("backimage.png");
	prePlayer = IMG_Load("character.png");
	background = SDL_DisplayFormat(preBackground);
	player = SDL_DisplayFormatAlpha(prePlayer);
	SDL_FreeSurface(preBackground);
	SDL_FreeSurface(prePlayer);

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
						break;
				}
			}
		}
		player_coords.x+=xvel;
		player_coords.y+=yvel;
		
		walkFrames +=1;
		if (walkFrames < walkFrameInterval)
		{
			player_frame.y = 200;
		}
		if ((walkFrames < walkFrameInterval*2) && (walkFrames > walkFrameInterval))
		{
			player_frame.y = 400;
		}
		if (walkFrames > (walkFrameInterval*2)-1)
		{
			walkFrames = 0;
		}
		if ((xvel==0) && (yvel == 0))
		{
			player_frame.y = 0;
		}
		
		// printf("Frames per second: %d\n", 1000/fps.get_ticks());
		SDL_BlitSurface(background, NULL, screen, NULL);
		SDL_BlitSurface(player, &player_frame, screen, &player_coords);
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