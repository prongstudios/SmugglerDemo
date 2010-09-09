#include <iostream>
using namespace std;


SDL_Rect tilePicker(int tile);

SDL_Surface map()
{
	SDL_Surface *mapSurface;
	int mapArray[8][8] =
	{
		{100, 100, 100, 100, 100, 100, 100, 100},
		{100, 3, 5, 5, 5, 5, 13, 100},
		{100, 2, 100, 100, 100, 100, 2, 100},
		{100, 2, 100, 1, 100, 100, 2, 100},
		{100, 2, 100, 100, 1, 100, 2, 100},
		{100, 2, 100, 100, 100, 100, 2, 100},
		{100, 4, 5, 5, 5, 5, 14, 100},
		{100, 100, 100, 100, 100, 100, 100, 100}				
	};
	

	
	int blockx = 0, blocky = 0;
	Object crate;
	crate.x(blockx);
	crate.y(blocky);
	crate.boxsize(100);
	crate.load("spritemap.png");
	
	Uint8 r = 255, g = 255, b =255, a = SDL_ALPHA_TRANSPARENT;
	SDL_PixelFormat *fmt;
	Uint32 color = SDL_MapRGBA(fmt, r, g, b,a);
	// Uint32 color;
	mapSurface = SDL_CreateRGBSurface(SDL_SWSURFACE,800,800,32,0, 0, 0, 0);
	SDL_Rect fill;
	fill.x=0;
	fill.y=0;
	fill.w=799;
	fill.h=799;
	SDL_FillRect(mapSurface, &fill, color);

	// out << SDL_SetAlpha(mapSurface,SDL_SRCALPHA, 0);
	// mapSurface = IMG_Load("black.png");
	
	//SDL_BlitSurface(&crate.image(), NULL, mapSurface, NULL);
	// mapSurface = &crate.image();
	
	for (int x =0; x <8; x++)
	{
		
		// iterates through each row
		for (int y =0; y <8; y++)
		{
			// return mapArray[x][y]
			
			int tilez = mapArray[x][y];
			SDL_Rect wat = tilePicker(tilez);
			SDL_Rect wtf = crate.rect();
			cout << "Tile: " << mapArray[x][y] << " Source: (" << wat.x << "," << wat.y << ") Dest: (" << wtf.x << "," << wtf.y << ") ";
			SDL_BlitSurface(&crate.image(), &wat, mapSurface, &wtf);
			blockx+=100;
			crate.x(blockx);
		};
		cout << "\n";
		blocky+=100;
		crate.y(blocky);
		blockx=0;
		crate.x(blockx);
	};
	// SDL_Flip(mapSurface);
	// SDL_DisplayFormatAlpha(mapSurface);
	SDL_SetAlpha(mapSurface,0 ,128);
	return *mapSurface;

}

SDL_Rect tilePicker(int tile)
{
	SDL_Rect selection;
	selection.h=100;
	selection.w=100;
	
	switch(tile)
	{
		case 1:
			selection.x=0;
			selection.y=0;
			break;
		case 2:
			selection.x=0;
			selection.y=100;
			break;
		case 3:
			selection.x=0;
			selection.y=200;
			break;
		case 4:
			selection.x=0;
			selection.y=300;
			break;
		case 5:
			selection.x=0;
			selection.y=400;
		break;
		
		case 13:
			selection.x=100;
			selection.y=200;
		break;
		case 14:
			selection.x=100;
			selection.y=300;
		break;
		
		case 100:
			selection.x=900;
			selection.y=900;
		break;
		
		default:
		// returns blank tile
			selection.x=900;
			selection.y=900;
		break;
	}
	
	return selection;
}