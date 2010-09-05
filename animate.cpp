int animate(int xvel, int yvel, int movementspeed, int walkFrames, int walkFrameInterval, Player& object)
{
	
	
	object.coordX(xvel);
	object.coordY(yvel);
	

	if (walkFrames < walkFrameInterval)
	{
		object.frameY(200);
	}
	
	if ((walkFrames < walkFrameInterval*2) && (walkFrames > walkFrameInterval))
	{
		object.frameY(400);
	}
	
	if (yvel == movementspeed)
	{
		object.frameX(0);
	}
	if (yvel == -movementspeed)
	{
		object.frameX(200);
	}
	if (xvel == movementspeed)
	{
		object.frameX(400);
	}
	if (xvel == -movementspeed)
	{
		object.frameX(600);
	}
	if (walkFrames == (walkFrameInterval*2))
	{
		walkFrames = 0;
	}
	if ((xvel==0) && (yvel == 0))
	{
		object.frameY(0);
	}
	
	walkFrames +=1;
	return walkFrames;

}