#include "Enemy.h"
#include "Rifle.h"
Enemy::Enemy(const sf::Vector2f pos)
	: Entity(pos, 40.f, "Enemy2")
{
	gun = new Rifle(sf::Vector2f(0, 1), "Bullet", hostile);
	health = 10;
	nextCheckpoint = 0;
}

void Enemy::addCheckpoint(const sf::Vector2f pos)
{
	this->Path.push_back(pos);
}

std::list<Projectile*> Enemy::shoot() const
{
	return gun->shoot(this->getPosition());
}

void Enemy::step(const sf::Time dt)
{
	if (nextCheckpoint < Path.size()) {
		float X = Path[nextCheckpoint].x - this->getPosition().x;
		float Y = Path[nextCheckpoint].y - this->getPosition().y;
		float length = sqrt(X*X + Y*Y);
		sf::Vector2f movement(X, Y);
		movement = movement / length * speed * (dt.asMicroseconds() / 1000000.f);
		if ((abs(movement.x) <= abs(X)) && (abs(movement.y) <= abs(Y)))
		{
			this->move(movement);
		}
		else
		{
			this->setPosition(Path[nextCheckpoint++]);
		}
	}
}

bool Enemy::TakeDamage(const int dmg)
{
	this->health -= dmg;
	if (this->health <= 0)
		// Удаление происходит в сцене, не здесь.
		return 0;
	return 1;
}