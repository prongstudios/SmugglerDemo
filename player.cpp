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
	velx = 0;
	vely = 0;
	SDL_Rect speech_loc;
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


int Player::xvel(int newxvel)
{
	velx = newxvel;
}

int Player::yvel(int newyvel)
{
	vely = newyvel;
}

int Player::xvel()
{
	return velx;
}

int Player::yvel()
{
	return vely;
}



SDL_Rect Player::location()
{
	return coords;
}

SDL_Rect Player::speech_bubble()
{
	speech_loc.x = coords.x + 65;
	speech_loc.y = coords.y - 25;
	return speech_loc;
}

SDL_Rect Player::frame()
{
	return frames;
}

SDL_Surface Player::image()
{
	return *sprite;
}

