#include "Enemy1.h"
Enemy1::Enemy1(const sf::Vector2f pos)
	: Enemy(pos,"Enemy1")
{
	this->HP = 10;
	this->gun = new Rifle(sf::Vector2f(0, 1), "Bullet", hostile);
};
void Enemy1::step(const sf::Time dt)
{
	if (nextPoint < Path.size()) {
		float X = Path[nextPoint].x - this->getPosition().x;
		float Y = Path[nextPoint].y - this->getPosition().y;
		float length = sqrt(X * X + Y * Y);
		sf::Vector2f movement(X, Y);
		movement = movement / length * speed * (dt.asMicroseconds() / 1000000.f);
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