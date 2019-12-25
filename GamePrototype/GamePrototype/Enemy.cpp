#include "Enemy.h"

Enemy::Enemy(const sf::Vector2f pos, float speed, std::string Name)
	: Entity(pos, speed, Name)
{
	this->nextPoint = 0;
	this->HP = 0;
	this->overlay.pause();
	this->gun = nullptr;
};

void Enemy::addPoint(const sf::Vector2f pos)
{
	this->Path.push_back(pos);
}

std::list<Projectile*> Enemy::shoot() const
{
	if (gun != nullptr)
		return gun->shoot(this->getPosition());
	else
		return {};
}

void Enemy::freeze()
{
	this->Entity::freeze();
	if (this->gun != nullptr)
		this->gun->freeze();
}

void Enemy::step(sf::Time dt)
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

	if (overlay.getElapsedTime() >= sf::milliseconds(MSEC_PER_FRAME * 10))
	{
		this->overlay.reset();
		this->overlay.pause();
		this->setColor(sf::Color(255, 255, 255));
	}
}

bool Enemy::takeDamage(const int dmg)
{
	this->setColor(sf::Color(255, 0, 0));
	this->overlay.reset();
	this->HP -= dmg;

	if (this->HP <= 0)
		// Удаление происходит в сцене, не здесь.
		return 0;
	else
		return 1;
}

void Enemy::unfreeze()
{
	this->Entity::unfreeze();
	if (this->gun != nullptr)
		this->gun->unfreeze();
}