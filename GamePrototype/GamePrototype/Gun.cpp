#include "Gun.h"
#include "Projectile.h"
Gun::Gun() {
	this->speed = 0.1f;
	this->tx.loadFromFile("Assets/projectiles/2x/1.png");
	this->timer.restart();
	this->frate = 0.2f;
}
void Gun::Shoot(sf::Vector2f pos) {
	if (timer.getElapsedTime().asSeconds() > frate) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		{
			proj.push_back(Projectile(pos.x,pos.y,tx));
			timer.restart();
		}
	}
}