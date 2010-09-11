Player::Player(std::string filename)
{
	SDL_Surface *oldface;
	oldface = IMG_Load(filename.c_str());
	sprite = SDL_DisplayFormatAlpha(oldface);
	SDL_FreeSurface(oldface);
	coords.x=500;
	coords.y=200;
	coords.w=100;
	coords.h=100;
	frames.x=0;
	frames.y=0;
	frames.w=100;
	frames.h=100;
}

void Player::coordX(int X)
{
	coords.x += X;
}

void Player::coordY(int Y)
{
	coords.y += Y;
}

void Player::box_size(int boxSize)
{
	coords.w = boxSize;
	coords.h = boxSize;
	frames.w = boxSize;
	frames.h = boxSize;
}

void Player::frameX(int frameX)
{
	frames.x = frameX;
}

void Player::frameY(int frameY)
{
	frames.y = frameY;
}


void Player::setxvel(int newxvel)
{
	xvel = newxvel;
}

void Player::setyvel(int newyvel)
{
	yvel = newyvel;
}

int Player::getxvel()
{
	return xvel;
}

int Player::getyvel()
{
	return yvel;
}



SDL_Rect Player::location()
{
	return coords;
}

SDL_Rect Player::frame()
{
	return frames;
}

SDL_Surface Player::image()
{
	return *sprite;
}