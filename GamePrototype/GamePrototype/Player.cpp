#include "Player.h"
#include "config.h"
#include "Rifle.h"

Player::Player()
	: Entity(sf::Vector2f(PLAYER_POS_X,PLAYER_POS_Y), 400.f, "Player")
{
	this->HP = 5;
	this->gun = new Rifle(sf::Vector2f(0, -1), "Bullet", friendly);
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
		this->move(speed * dt.asMicroseconds() / 1000000 * dir / SQRT_2);
	else
		this->move(speed * dt.asMicroseconds() / 1000000 * dir);
}

std::list<Projectile*> Player::shoot() const
{
	return gun->shoot(this->getPosition());
}

void Player::TakeDamage(const int dmg)
{
	this->HP -= dmg;
	if (this->HP < 0)
		this->HP = 0;
}
int Player::getHP() {
	return this->HP;
}
const int Player::getFullHP() {
	return this->fullHP;
}