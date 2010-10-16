#include "includes.h"



// Game constraints
const int FPS = 60;
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 1024;
const int SCREEN_BPP = 32;
const int movementspeed = 2;
const int walkFrameInterval = 10;

int main(int argc, char *argv[])
{
	// Erectin' a display
	SDL_Surface *screen;
	SDL_Init(SDL_INIT_EVERYTHING);
    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_HWSURFACE);
	
	
	
	SDL_WM_SetCaption("Smuggler Demo", "Smuggler Demo");
	bool quit = false;
	
	
	// Setting up text
	TTF_Font* Font=NULL;
	TTF_Init();
	SDL_Surface* TextSurface = NULL;
	
	
	Font=TTF_OpenFont("DejaVuSansMono.ttf",16);
	SDL_Color color;
	color.r=255;
	color.g=255;
	color.b=255;
	int FontSize = 10;
	bool growing = true;
	
	// Rendering surfaces

	
	// Set background surface to display optimized
	SDL_Surface *background;
	SDL_Surface *oldface;
	oldface = IMG_Load("backimage.png");
	background = SDL_DisplayFormat(oldface);
	SDL_FreeSurface(oldface);
	
	// Set player's image to 
	Player player1("ana.png");
	Player player2("character.png");
	player2.coordX(500);
	player2.coordY(500);
	
	// Load overlay surface and set transparency color to 0
	SDL_Surface *overlay = &map();
	SDL_SetColorKey(overlay, SDL_SRCCOLORKEY,0);
	
	
	// Instantiate timer object
	Timer fps;
	
	int walkFrames = 2;
	
	while(!quit){
		// Start the timer for frame rate limiting
		fps.start();
		
		// The input handling function returns a bool. While quit == false, the game will continue to run
		quit = input(&player1, movementspeed);
		
		// This function animates through the cycle, using an iterating number that triggers the different frames
		// TODO: The walkframes integer should be tucked into the object it is manipulating, in this case, player.
		walkFrames=animate(player1.xvel(), player1.yvel(), movementspeed, walkFrames, walkFrameInterval, &player1);
		
		// Renders the background on the bottom
		SDL_BlitSurface(background, NULL, screen, NULL);
		
		// Puts the player underneath the overlay, which is basically the map
		SDL_BlitSurface(&player1.image(), &player1.frame(), screen, &player1.location());

		// Checks for collisions
		if (collision(&player1.image(), player1.coordX(), player1.coordY(), 100, &player2.image(), player2.coordX(), player2.coordY(), 100))
		{
			cout << "COLLIDE!\n";
			player2.xvel(0);
			player2.yvel(0);
		}
		else
		{
			cout << "NO COLLIDE!\n";
			player2.ai(player1);
		}


		// Puts the NPC underneath the overlay

		walkFrames=animate(player2.xvel(), player2.yvel(), movementspeed/2, walkFrames, walkFrameInterval, &player2);
		SDL_BlitSurface(&player2.image(), &player2.frame(), screen, &player2.location());
		
		

		
		
		// Renders the map
		SDL_BlitSurface(overlay, NULL, screen, NULL);
		
		// Renders the text
		if (growing == true)
		{
			FontSize ++;
		}
		else
		{
			FontSize --;
		}
						
		if (FontSize == 25)
		{
			growing = false;
		}
		if (FontSize == 1)
		{
			growing = true;
		}
				
		Font=TTF_OpenFont("DejaVuSansMono.ttf",FontSize);
		TextSurface=TTF_RenderText_Solid(Font,"I love poop!!",color);
		SDL_BlitSurface(TextSurface, NULL, screen, &player2.speech_bubble());
		TTF_CloseFont(Font);
		SDL_FreeSurface(TextSurface);
		
		
		// Renders it all to the display
		SDL_Flip(screen);


		
		// For performance measuring purposes, this line spits out the max framerate possible if this rate of animation is sustained.
		// printf("Max Frames per second: %d\n", 1000/fps.get_ticks());
	
	// Hard locks the frame rate to 60 frames per second or less
	if(fps.get_ticks() < 1000 / FPS)
	{
		SDL_Delay ((1000/FPS) - fps.get_ticks());
	}
	
	}
    SDL_Quit();

}
