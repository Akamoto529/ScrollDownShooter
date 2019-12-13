#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "UI.h"
#include "Animation.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 800), "SFML works!");
	Player pl;
	Enemy en(window.getSize().x/2,100.f);
	pl.sp.setPosition(window.getSize().x / 2,window.getSize().y-230.f);

	Animation animation(pl.tx,sf::Vector2u(3,1),0.01f);
	float deltaTime = 0.f;
	sf::Clock clock;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asMicroseconds()/1000000.f;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		pl.Shoot();
		pl.sp.move(pl.speed * pl.getDir());
		animation.Update(0, deltaTime);
		window.clear();
		for (int i = pl.gun.proj.size()-1; i >=0; i--) {
			pl.gun.proj[i].sp.move(pl.gun.proj[i].speed*pl.gun.proj[i].dir);
			if (pl.gun.proj[i].sp.getPosition().y < 0.f) pl.gun.proj.erase(pl.gun.proj.begin() + i--);
			else	window.draw(pl.gun.proj[i].sp);
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