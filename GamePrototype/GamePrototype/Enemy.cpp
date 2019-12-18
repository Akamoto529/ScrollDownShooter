#include "Enemy.h"

Enemy::Enemy(const sf::Vector2f pos)
	: Entity(pos, 40.f, enemy2_ID)
{
	gun = new Rifle(sf::Vector2f(0, 1), bullet_ID, hostile);
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
		float distX = Path[nextCheckpoint].x - this->getPosition().x;
		float distY = Path[nextCheckpoint].y - this->getPosition().y;
		float length = sqrt(distX*distX + distY*distY);
		sf::Vector2f movement(distX, distY);
		movement = movement / length * speed * (dt.asMicroseconds() / 1000000.f);
		if ((abs(movement.x) <= abs(distX)) && (abs(movement.y) <= abs(distY)))
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