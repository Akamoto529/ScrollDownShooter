#include "Player.h"
#include "config.h"
#include "Rifle.h"

Player::Player()
	: Entity(sf::Vector2f(PLAYER_POS_X,PLAYER_POS_Y), 400.f, "Player")
{
	this->HP = 5;
	this->gun = new Rifle(sf::Vector2f(0, -1), "Bullet", friendly);
}

const int Player::getFullHP()
{
	return this->fullHP;
}

int Player::getHP() const
{
	return this->HP;
}

void Player::freeze()
{
	this->frozen = true;
	this->gun->freeze();
}

std::list<Projectile*> Player::shoot() const
{
	return gun->shoot(this->getPosition());
}

void Player::step(const sf::Time dt)
{
	if (!frozen)
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
			this->move(speed * dt.asSeconds() * dir / SQRT_2);
		else
			this->move(speed * dt.asSeconds() * dir);
	}
}

bool Player::takeDamage(const int dmg)
{
	this->HP -= dmg;
	if (this->HP <= 0)
		// Удаление происходит в сцене, не здесь.
		return 0;
	return 1;
}

void Player::unfreeze()
{
	this->frozen = false;
	this->gun->unfreeze();
}