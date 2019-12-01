#include <SFML/Graphics.hpp>
#include <iostream>
#include "Projectile.h"
#include "Scene.h"
#include "Gun.h"
#include "loader.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(600,800), "test v2");
	Scene scene(window.getSize());
	sf::Texture tx;
	tx.loadFromFile("Assets/Projectile.png");
	Rifle test(sf::Vector2f(0,-1));

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
		test.Shoot(&scene, sf::Vector2f(300, 400));
		scene.update();
		window.clear();
		window.draw(scene);
		window.display();
		timer1.restart();
	}

	return 0;
}