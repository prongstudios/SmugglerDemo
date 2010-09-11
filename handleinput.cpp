bool input(Player &player, int movementspeed)
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
					player.setxvel(-movementspeed);
					break;
				case SDLK_RIGHT:
					player.setxvel(movementspeed);
					break;
				case SDLK_UP:
					player.setyvel(-movementspeed);
					break;
				case SDLK_DOWN:
					player.setyvel(movementspeed);
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
					player.setxvel(0);
					break;
				case SDLK_RIGHT:
					player.setxvel(0);
					break;
				case SDLK_UP:
					player.setyvel(0);
					break;
				case SDLK_DOWN:
					player.setyvel(0);
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