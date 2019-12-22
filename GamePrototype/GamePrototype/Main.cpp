#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "config.h"
#include "Timer.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_X,WINDOW_Y), "test v2");
	Scene scene;
	Timer dt;
	Timer frame;
	sf::Time lastUpdateDuration = sf::microseconds(0);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		{
			dt.pause();
			frame.pause();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
		{
			dt.start();
			frame.start();
		}

		if (sf::milliseconds(MSEC_PER_FRAME) - (frame.getElapsedTime() + dt.getElapsedTime()) < lastUpdateDuration)
		{
			lastUpdateDuration = dt.getElapsedTime();
			scene.update(dt.getElapsedTime());
			lastUpdateDuration = dt.getElapsedTime() - lastUpdateDuration;
			dt.reset();
		}
		if (frame.getElapsedTime() >= sf::milliseconds(MSEC_PER_FRAME))
		{
			frame.reset();
			window.clear();
			window.draw(scene);
			window.display();
		}
	}
	return 0;
}