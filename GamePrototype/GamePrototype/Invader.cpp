#include "Invader.h"

Invader::Invader(sf::Vector2f pos)
	: Enemy(pos, 20.f, "Invader")
{
	this->HP = 100;
	this->startPos = pos;
}

void Invader::step(sf::Time dt)
{
	if (!frozen)
		this->move(sf::Vector2f(cos((this->getPosition().y - this->startPos.y) / 20) / 5, dt.asSeconds() * speed));

	if (overlay.getElapsedTime() >= sf::milliseconds(MSEC_PER_FRAME * 10))
	{
		this->overlay.reset();
		this->overlay.pause();
		this->setColor(sf::Color(255, 255, 255));
	}
}