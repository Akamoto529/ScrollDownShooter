#include "Player.h"

Player::Player(sf::Texture& tx, float speed, sf::Vector2f pos, float hitboxRatio)
	: Entity(tx, speed, pos, hitboxRatio)
{
	this->health = 5;
	this->gun = new Rifle(sf::Vector2f(0,-1), Loader::getInstance()->GetProjectile());
}

void Player::move()
{
	const float SQRT_2 = 1.41421356f;
	sf::Vector2f dir = sf::Vector2f(0.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		dir.x -= 1.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		dir.x += 1.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		dir.y -= 1.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		dir.y += 1.f;
	}
	if (abs(dir.x) + abs(dir.y) == 2)
		this->Entity::move(speed * dir / SQRT_2);
	else
		this->Entity::move(speed * dir);
}

std::list<Projectile*> Player::Shoot()
{
	return gun->Shoot(this->getPosition());
}

void Player::TakeDamage(int dmg)
{
	this->health -= dmg;
}