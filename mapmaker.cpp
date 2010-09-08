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
		{100, 3, 5, 5, 5, 5, 13, 100},
		{100, 100, 100, 100, 100, 100, 100, 100}				
	};
	int blockx = 0, blocky = 0;
	Object crate;
	crate.x(blockx);
	crate.y(blocky);
	crate.boxsize(100);
	crate.load("spritemap.png");
	

	mapSurface = IMG_Load("black.png");
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
			SDL_BlitSurface(&crate.image(), &tilePicker(tilez), mapSurface, &crate.rect());
			
			
			// SDL_BlitSurface(&crate.image(), NULL, mapSurface, NULL);
			
			blockx+=100;
			crate.x(blockx);
		};
		cout << "\n";
		blocky+=100;
		crate.y(blocky);
		blockx=0;
		crate.x(blockx);
	};
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