#include "SDL.h"
#include <string>

class Player
{
private:
	
	SDL_Rect coords;
	SDL_Rect frames;
	std::string filename;
	SDL_Surface *sprite;
	int xvel;
	int yvel;
	SDL_Rect speech_loc;
	
public:
	
	Player(std::string filename);
	
	void setxvel(int newxvel);
	void setyvel(int newyvel);
	int getxvel();
	int getyvel();
	
	void coordX(int X);
	void coordY(int Y);
	void box_size(int boxSize);
	void frameX(int frameX);
	void frameY(int frameY);
	SDL_Rect location();
	SDL_Rect speech_bubble();
	SDL_Rect frame();
	SDL_Surface image();
	
};
