#include "SDL.h"
#include <string>
#include <SDL_image.h>
class Object
{
private:
	SDL_Rect coords;
	SDL_Surface *surface;
	std::string filename;
	
public:
	Object();
	void x(int newX);
	void y(int newY);
	void boxsize(int newBox);
	void load(std::string filename);
	SDL_Rect rect();
	SDL_Surface image();
};
