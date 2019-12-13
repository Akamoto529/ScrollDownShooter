#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "config.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_X,WINDOW_Y), "test v2");
	Scene scene;
	sf::Clock dt;
	sf::Clock frame;
	while (window.isOpen())
	{
		deltaTime = clock.restart().asMicroseconds()/1000000.f;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (dt.getElapsedTime() >= sf::milliseconds(1))
		{
			scene.update(dt.getElapsedTime());
			//std::cout << dt.getElapsedTime().asMicroseconds() << std::endl;
			dt.restart();
		}
		if (frame.getElapsedTime() >= sf::milliseconds(MSEC_PER_FRAME))
		{
			frame.restart();
			window.clear();
			window.draw(scene);
			window.display();
			//std::cout << frame.getElapsedTime().asMilliseconds() << std::endl;
		}
		window.draw(en.sp);
		window.draw(pl.sp);
		UI ui;
		for (int i = 0; i < 3; i++)
		{
			window.draw(ui.mas[i]);
		}
		window.display();
	}
	return 0;
}