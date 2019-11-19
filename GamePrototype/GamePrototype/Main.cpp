#include <SFML/Graphics.hpp>
#include "Player.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 1000), "SFML works!");
	Projectile pr(500.f,400.f);
	Player pl;
	pl.sprite.setPosition(window.getSize().x / 2,window.getSize().y-30.f);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		pl.Shoot();
		pl.sprite.move(pl.Speed * pl.getDir());
		window.clear();
		for (int i = 0; i < pl.proj.size(); i++) {
			pl.proj[i].sprite.move(pl.proj[i].speed*pl.proj[i].dir);
			//if (pl.proj[i].sprite.getPosition().y < 100.f) pl.proj.erase(pl.proj.begin() + i);
			window.draw(pl.proj[i].sprite);
		}
		window.draw(pl.sprite);
		window.display();
	}
	return 0;
}