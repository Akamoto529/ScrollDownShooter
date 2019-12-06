#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "UI.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 800), "SFML works!");
	Player pl;
	Enemy en(window.getSize().x/2,100.f);
	//UI hp(10.f, 20.f,3);
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
		for (int i = pl.gun.proj.size()-1; i >=0; i--) {
			pl.gun.proj[i].sp.move(pl.gun.proj[i].speed*pl.gun.proj[i].dir);
			if (pl.gun.proj[i].sp.getPosition().y < 0.f) pl.gun.proj.erase(pl.gun.proj.begin() + i--);
			else	window.draw(pl.gun.proj[i].sp);
		}
		window.draw(en.sp);
		window.draw(pl.sp);
		UI hp(10.f, 20.f,pl.GetHP());
		window.draw(hp.sp);
		window.display();
	}
	return 0;
}