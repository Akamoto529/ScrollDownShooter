#include "Background.h"

Background::Background(const float speed, const std::string Name)
{
	this->velocity = sf::Vector2f(0, speed);
	this->sp.setTexture(Loader::get()->TX(Name));
	// ���� ��� �������� repeated == true, ��� ����� ����������� � ������� ��� ����.
	this->sp.setTextureRect(sf::IntRect(
		sf::Vector2i(0, 0), sf::Vector2i(WINDOW_X, 2 * (int)this->sp.getTextureRect().height)));
	// ����� �������.
	this->sp.setOrigin(0, this->sp.getTextureRect().height / 2);
	this->sp.setPosition(0, -this->sp.getOrigin().y + WINDOW_Y);
}

void Background::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->sp, states);
}

void Background::step(const sf::Time dt)
{
	this->sp.move(dt.asSeconds() * this->velocity);
	if (this->sp.getPosition().y >= WINDOW_Y)
		this->sp.move(0, -this->sp.getOrigin().y);
}