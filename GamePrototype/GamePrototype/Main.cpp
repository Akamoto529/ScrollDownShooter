#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Level.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 800), "SFML works!");
	Level lvl("123");
	lvl.LoadWave();
	//lvl.waves[0].enemies.erase(lvl.waves[0].enemies.begin());
	Player pl;
	pl.sp.setPosition(window.getSize().x / 2,window.getSize().y-30.f);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		pl.Shoot();
		pl.sp.move(pl.speed * pl.getDir());
		window.clear();
		for (int i = lvl.waves[0].enemies.size()-1; i >=0; i--)
		{
			window.draw(lvl.waves[0].enemies[i].sp);
		}
		for (int i = pl.gun.proj.size()-1; i >=0; i--) {
			pl.gun.proj[i].sp.move(pl.gun.proj[i].speed*pl.gun.proj[i].dir);
			if (pl.gun.proj[i].sp.getPosition().y < 0.f) pl.gun.proj.erase(pl.gun.proj.begin() + i--);
			else	window.draw(pl.gun.proj[i].sp);
		}
		window.draw(pl.sp);
		window.display();
	}
	return 0;
}