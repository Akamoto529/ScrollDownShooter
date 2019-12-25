#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "config.h"
#include "Timer.h"
#include "ScreenManager.h"

int main()
{
	srand((int)time(0));
	ScreenManager Sm;
	Timer frame;
	while (true)
	{
		Sm.update(sf::milliseconds(MSEC_PER_FRAME) - frame.getElapsedTime());
		if (frame.getElapsedTime() >= sf::milliseconds(MSEC_PER_FRAME))
		{
			frame.reset();
			Sm.Render();
		}
	}
	return 0;
}