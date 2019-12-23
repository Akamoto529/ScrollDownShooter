#include "Entity.h"

Entity::Entity(const sf::Vector2f pos, const float speed, const std::string entityName)
{
	this->frozen = false;
	this->speed = speed;
	this->Transformable::setPosition(pos);

	this->sp.setTexture(Loader::get()->TX(entityName));
	this->sp.setOrigin(this->sp.getTexture()->getSize().x / 2, this->sp.getTexture()->getSize().y / 2);
	this->sp.setPosition(pos);
	this->hitbox = Loader::get()->HB(entityName);
	this->hitbox.setOrigin(this->sp.getOrigin());
	this->hitbox.setPosition(pos);
}
void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->sp, states);
	target.draw(this->hitbox, states);
}

void Entity::freeze()
{
	this->frozen = true;
}

Hitbox Entity::getHitbox() const
{
	return this->hitbox;
}

sf::FloatRect Entity::getHitboxBounds() const
{
	return this->hitbox.getGlobalBounds();
}

sf::FloatRect Entity::getSpriteBounds() const{
	return this->sp.getGlobalBounds();
}

void Entity::move(const sf::Vector2f offset)
{
	this->Transformable::move(offset);
	this->sp.move(offset);
	this->hitbox.move(offset);
}

void Entity::rotate(const float angle)
{
	this->Transformable::rotate(angle);
	this->sp.rotate(angle);
	this->hitbox.rotate(angle);
}

void Entity::setPosition(const sf::Vector2f position)
{
	this->Transformable::setPosition(position);
	this->sp.setPosition(position);
	this->hitbox.setPosition(position);
}

void Entity::setRotation(const float angle)
{
	this->Transformable::setRotation(angle);
	this->sp.setRotation(angle);
	this->hitbox.setRotation(angle);
}

void Entity::setRotation(const sf::Vector2f direction)
{
	this->setRotation(atan2(direction.x, -direction.y) / PI * 180);
}

void Entity::unfreeze()
{
	this->frozen = false;
}