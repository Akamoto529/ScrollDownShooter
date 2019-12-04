#include "Entity.h"

Entity::Entity(sf::Texture &tx, float speed, sf::Vector2f pos, float hitboxRatio)
{
	this->setTexture(tx, pos, hitboxRatio);
	this->speed = speed;
	this->radius = tx.getSize().x + tx.getSize().y;
}

//Entity::~Entity()
//{
//
//}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->sp, states);
}

float Entity::getRadius() const
{
	return radius;
}

sf::Vector2f Entity::getPosition() const
{
	return this->sp.getPosition();
}

void Entity::move(sf::Vector2f offset)
{
	this->sp.move(offset);
	this->hitbox.move(offset);
}

void Entity::setPosition(sf::Vector2f position)
{
	this->sp.setPosition(position);
	this->hitbox.setPosition(position);
}

void Entity::setTexture(sf::Texture& tx, sf::Vector2f pos, float hitboxRatio)
{
	this->sp.setTexture(tx);
	this->sp.setOrigin(tx.getSize().x / 2, tx.getSize().y / 2);
	this->sp.setPosition(pos);

	// Относительный размер хитбокса.
	this->hitbox.setSize(sf::Vector2f(tx.getSize().x * hitboxRatio, tx.getSize().y * hitboxRatio));
	this->hitbox.setOrigin(hitbox.getSize() / 2.f);
	this->hitbox.setPosition(pos);
}