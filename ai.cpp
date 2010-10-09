void Player::ai(Player& target)
{
	enum states {PURSUIT, IDLE};
	enum states state=PURSUIT;
	SDL_Rect target_coords=target.location();
	switch ( state )
	      {
	         case PURSUIT:
	         if (coords.x > target_coords.x)
				{
					xvel(-1);
				};
			if (coords.x < target_coords.x)
				{
					xvel(1);
				};
			if (coords.y > target_coords.y)
				{
					yvel(-1);
				};
			if (coords.y < target_coords.y)
				{
					yvel(1);
				};
			if (coords.x == target_coords.x)
				{
					xvel(0);
				};
			if (coords.y == target_coords.y)
				{
					yvel(0);
					};
	            break;
	
	         case IDLE:
	            //Also does nothing;
	            break;
	
	         default:
	            //DOES NOTHING;
				break;
	      }
	
}