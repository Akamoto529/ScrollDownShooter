#include "Enemy2.h"

Enemy2::Enemy2(const sf::Vector2f pos)
	: Enemy(pos, 100.f, "Enemy2")
{
	this->HP = 2;
	this->gun = new Rifle(sf::Vector2f(0, 1));
}

void Enemy2::step(const sf::Time dt)
{
	if (!frozen && nextPoint < Path.size()) {
		float X = Path[nextPoint].x - this->getPosition().x;
		float Y = Path[nextPoint].y - this->getPosition().y;
		float length = sqrt(X * X + Y * Y);
		sf::Vector2f movement(X, Y);
		movement = movement / length * speed * dt.asSeconds();
		if ((abs(movement.x) <= abs(X)) && (abs(movement.y) <= abs(Y)))
		{
			this->move(movement);
		}
		else
		{
			this->setPosition(Path[nextPoint++]);
		}
	}
}