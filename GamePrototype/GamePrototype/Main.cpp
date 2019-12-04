#include <SFML/Graphics.hpp>
#include <iostream>
#include "Projectile.h"
#include "Scene.h"
#include "Gun.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800,900), "test v2");
	Scene scene(window.getSize());

	const int FRAME_TIME = 16;

	sf::Clock timer1;

	while (window.isOpen())
	{
		if (timer1.getElapsedTime() < sf::milliseconds(FRAME_TIME))
		{
			continue;
		}
		//std::cout << timer1.getElapsedTime().asMicroseconds() << std::endl;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		scene.update();
		window.clear();
		window.draw(scene);
		window.display();
		timer1.restart();
	}

	return 0;
}