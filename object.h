#include <string>

class Object
{
private:
	SDL_Rect coords;
	SDL_Surface *objectIMG;
	
public:
	Object();
	int x(int newX);
	int y(int newY);
	int boxsize(int newBox);
	SDL_Surface IMG();
};

Object::Object()
{
	coords.x=0;
	coords.y=0;
	coords.w=0;
	coords.h=0;
	
}



int Object::x(int newX)
{
	coords.x=newX;
}

int Object::y(int newY)
{
	coords.y=newY;
}

int Object::boxsize(int newBox)
{
	coords.w=newBox;
	coords.h=newBox;
}

SDL_Surface Object::IMG()
{
	return *objectIMG;
}