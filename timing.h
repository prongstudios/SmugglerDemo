class Timer
{
	private:
		int startTicks;
		int currentTicks;
		
	public:
		Timer();
		
		void start();
		int get_ticks();
};

Timer::Timer()
{
	startTicks=0;
}	

void Timer::start()
{
	startTicks = SDL_GetTicks();
}

int Timer::get_ticks()
{
	return SDL_GetTicks() - startTicks;
}