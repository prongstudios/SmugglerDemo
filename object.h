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

Object::Object()
{
	coords.x=0;
	coords.y=0;
	coords.w=0;
	coords.h=0;
	
}



void Object::x(int newX)
{
	coords.x=newX;
}

void Object::y(int newY)
{
	coords.y=newY;
}

void Object::load(std::string filename)
{
	SDL_Surface *oldface;
	oldface = IMG_Load(filename.c_str());
	surface = SDL_DisplayFormatAlpha(oldface);
	SDL_FreeSurface(oldface);
}

void Object::boxsize(int newBox)
{
	coords.w=newBox;
	coords.h=newBox;
}




SDL_Surface Object::image()
{
	return *surface;
}

SDL_Rect Object::rect()
{
	return coords;
}