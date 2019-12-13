#include "Entity.h"

Entity::Entity(const sf::Vector2f pos, const float speed, const int entityID)
{
	this->speed = speed;
	this->sp.setTexture(Loader::get()->TX(entityID));
	this->sp.setOrigin(this->sp.getTexture()->getSize().x / 2, this->sp.getTexture()->getSize().y / 2);
	this->sp.setPosition(pos);
	this->hitbox = Loader::get()->HB(entityID);
	this->hitbox.setOrigin(this->sp.getOrigin());
	this->hitbox.setPosition(pos);
}
void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->sp, states);
}

sf::FloatRect Entity::getGlobalBounds() const{
	return this->sp.getGlobalBounds();
}

Hitbox Entity::getHitbox() const
{
	return this->hitbox;
}

sf::Vector2f Entity::getPosition() const
{
	return this->sp.getPosition();
}

void Entity::move(const sf::Vector2f offset)
{
	this->sp.move(offset);
	this->hitbox.move(offset);
}

void Entity::setPosition(const sf::Vector2f position)
{
	this->sp.setPosition(position);
	this->hitbox.setPosition(position);
}
