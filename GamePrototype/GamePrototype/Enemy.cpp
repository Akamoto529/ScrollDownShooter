#include "Enemy.h"
#include "Rifle.h"
#include "config.h"
Enemy::Enemy(const sf::Vector2f pos, std::string Name)
	: Entity(pos, 40.f, Name)
{
	this->nextPoint = 0;
};

void Enemy::addPoint(const sf::Vector2f pos)
{
	this->Path.push_back(pos);
}

std::list<Projectile*> Enemy::shoot() const
{
	return gun->shoot(this->getPosition());
}

void Enemy::step(const sf::Time dt)
{
	if (nextPoint < Path.size()) {
		float X = Path[nextPoint].x - this->getPosition().x;
		float Y = Path[nextPoint].y - this->getPosition().y;
		float length = sqrt(X*X + Y*Y);
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

bool Enemy::TakeDamage(const int dmg)
{
	this->HP -= dmg;
	if (this->HP <= 0)
		// Удаление происходит в сцене, не здесь.
		return 0;
	return 1;
}