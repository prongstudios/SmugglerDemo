bool input(Player *player, int movementspeed)
{
	SDL_Event event;
	
	bool quit = false;
	while (SDL_PollEvent(&event))
	{
		// if (event.type==SDL_QUIT){
		// 	Running=false;
		// }
		if (event.type == SDL_KEYDOWN)
		{
			switch(event.key.keysym.sym){
				case SDLK_LEFT:
					player->xvel(-movementspeed);
					break;
				case SDLK_RIGHT:
					player->xvel(movementspeed);
					break;
				case SDLK_UP:
					player->yvel(-movementspeed);
					break;
				case SDLK_DOWN:
					player->yvel(movementspeed);
					break;
				case SDLK_ESCAPE:
					quit=true;
					break;
				default:
				// do nothing
					break;
			}
		}
		if (event.type == SDL_KEYUP)
		{
			switch(event.key.keysym.sym){
				case SDLK_LEFT:
					player->xvel(0);
					break;
				case SDLK_RIGHT:
					player->xvel(0);
					break;
				case SDLK_UP:
					player->yvel(0);
					break;
				case SDLK_DOWN:
					player->yvel(0);
					break;
				case SDLK_ESCAPE:
					quit=true;
					break;
				default:
				// Do nothing
					break;
			}
		}
		if (event.type == SDL_QUIT)
		{
			quit = true;
		}
	}
	return quit; 
}