#include "SDL.h"
#include <string>

class Player
{
private:
	
	SDL_Rect coords;
	SDL_Rect frames;
	std::string filename;
	SDL_Surface *sprite;
	
public:
	
	Player(std::string filename);
	void coordX(int X);
	void coordY(int Y);
	void box_size(int boxSize);
	void frameX(int frameX);
	void frameY(int frameY);
	SDL_Rect location();
	SDL_Rect frame();
	SDL_Surface image();
	
};