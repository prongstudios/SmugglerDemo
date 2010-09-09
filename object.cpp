#include <iostream>
using namespace std;

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
	cout << SDL_SetAlpha(surface,SDL_SRCALPHA, 0);
	
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