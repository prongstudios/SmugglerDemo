#include <string>

SDL_Surface load_image(string filename)
{
	SDL_Surface *preOpt;
	SDL_Surface *Optimized;
	preOpt = IMG_Load(filename.c_str());
	Optimized = SDL_DisplayFormat(preOpt);
	SDL_FreeSurface(preOpt);
	return *Optimized;
}