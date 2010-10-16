#include "collision.h"


bool collision(SDL_Surface* surfacea, int ax, int ay, int asize, SDL_Surface* surfaceb, int bx, int by, int bsize)
{
	//  if the righmost point of surface a is further left than the leftmost point of surfaceb, or the rightmost point of surface b is further left than the leftmost point of surface a, there is no collision. 
	
	int aRight = ax+asize;
	int bRight = bx+bsize;
	
	if ((ax > bRight) || (bx > aRight))
	{
		return false;
	}	
	
	
	// if the highest point of surfacea is lower than the lowest point of surfaceb, or the highest point of surfaceb is lower than the lowest point of surfacea, there is no collision.
	
	int aBottom = ay+asize;
	int bBottom = by+bsize;
	
	if ((ay > bBottom) || (by > aBottom))
	{
		return false;
	}
		
	
	//   if none of those is true, then there is a collision, and our function returns true
	
	
	return true;
}


int bound_max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	return b;
}

int bound_min(int a, int b)
{
	if (a < b)
	{
		return a;
	}
	return b;
}

int get_distance(Player* p1, Player* p2)
{
	int xdist = p1->coordX() - p2->coordX();
	int ydist = p1->coordY() - p2->coordY();
	
	if (xdist < 0)
	{
		xdist = xdist * -1;
	}
	if (ydist < 0)
	{
		ydist = ydist * -1;
	}
	
	cout << xdist << " "<< ydist << " ";
	int dist = bound_max(xdist, ydist);
	return dist;
}