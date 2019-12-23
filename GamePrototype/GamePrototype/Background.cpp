#include "Background.h"

float Background::speed = 50.f;

Background::Background(const std::string Name)
{
	this->frozen = false;
	this->velocity = sf::Vector2f(0, speed);
	this->sp.setTexture(Loader::get()->TX(Name));
	// Если для текстуры repeated == true, она будет повторяться в спрайте два раза.
	this->sp.setTextureRect(sf::IntRect(
		sf::Vector2i(0, 0), sf::Vector2i(WINDOW_X, 2 * (int)this->sp.getTextureRect().height)));
	// Место склейки.
	this->sp.setOrigin(0, this->sp.getTextureRect().height / 2);
	this->sp.setPosition(0, -this->sp.getOrigin().y + WINDOW_Y);
}

void Background::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->sp, states);
}

void Background::freeze()
{
	this->frozen = true;
}

float Background::getSpeed()
{
	return Background::speed;
}

void Background::step(const sf::Time dt)
{
	if (!frozen)
	{
		this->sp.move(dt.asSeconds() * this->velocity);
		// Сдвиг назад на склейке.
		if (this->sp.getPosition().y >= WINDOW_Y)
			this->sp.move(0, -this->sp.getOrigin().y);
	}
}

void Background::unfreeze()
{
	this->frozen = false;
}