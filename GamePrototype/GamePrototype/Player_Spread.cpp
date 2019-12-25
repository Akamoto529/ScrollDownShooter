#include "Player_Spread.h"
Player_Spread::Player_Spread(const sf::Vector2f direction)
	: Gun(direction, sf::milliseconds(650))
{
}

std::list<Projectile*> Player_Spread::shoot(const sf::Vector2f position)
{
	if (!frozen && this->timer.getElapsedTime() >= this->reloadTime)
	{
		sf::Vector2f deg22 = sf::Vector2f(this->getDirection().x * cos(PI*67.5f / 180.f ) + this->getDirection().y * sin(PI * 67.5f / 180.f),
										 this->getDirection().x * sin(PI * 67.5f / 180.f) + this->getDirection().y * cos(PI * 67.5f / 180.f));
		sf::Vector2f deg45 = sf::Vector2f(this->getDirection().x * cos(PI / 4.f) + this->getDirection().y * sin(PI / 4.f),
			this->getDirection().x * sin(PI / 4.f) + this->getDirection().y * cos(PI / 4.f));
		this->timer.reset();
		return
		{
			ProjFactory::getProj(position, this->getDirection(), "Christmas_proj"),
			ProjFactory::getProj(position, sf::Vector2f(deg22.y,deg22.x), "Christmas_proj"),
			ProjFactory::getProj(position, sf::Vector2f(-deg22.y,deg22.x), "Christmas_proj"),
			ProjFactory::getProj(position, sf::Vector2f(deg45.y,deg45.x), "Christmas_proj"),
			ProjFactory::getProj(position, sf::Vector2f(-deg45.y,deg45.x), "Christmas_proj")
		};
	}
	else
		return {};
}