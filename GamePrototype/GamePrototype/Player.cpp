#include "Player.h"
#include "config.h"

Player::Player(sf::Vector2f pos)
	: Entity(pos, 400.f, pl_ID)
{
	this->health = 5;
	this->gun = new Rifle(sf::Vector2f(0,-1), bullet_ID, this);
}

void Player::step(const sf::Time dt)
{
	sf::Vector2f dir = sf::Vector2f(0.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && this->getPosition().x > 0)
	{
		dir.x -= 1.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && this->getPosition().x < WINDOW_X)
	{
		dir.x += 1.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && this->getPosition().y > 0)
	{
		dir.y -= 1.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && this->getPosition().y < WINDOW_Y)
	{
		dir.y += 1.f;
	}
	if (abs(dir.x) + abs(dir.y) == 2)
		this->move(speed * dt.asMicroseconds()/1000000 * dir / SQRT_2);
	else
		this->move(speed * dt.asMicroseconds()/1000000 * dir);
}

std::list<Projectile*> Player::Shoot() const
{
	return gun->Shoot(this->getPosition());
}

void Player::TakeDamage(const int dmg)
{
	this->health -= dmg;
	if (this->health < 0)
		this->health = 0;
}