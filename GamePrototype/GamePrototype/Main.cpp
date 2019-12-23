#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "config.h"
#include "Timer.h"
#include "ScreenManager.h"

int main()
{
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(WINDOW_X,WINDOW_Y), "test v2");
	ScreenManager Sm;
	Timer frame;
	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}

		Sm.Update();
		if (frame.getElapsedTime() >= sf::milliseconds(MSEC_PER_FRAME))
		{
			frame.reset();
			window->clear();
			Sm.Render(window);
			window->display();
		}
	}
	return 0;
}