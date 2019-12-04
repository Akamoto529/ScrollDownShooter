#pragma once
#include "SFML/Graphics.hpp"

// Суперкласс для физических игровых объектов
class Entity : public sf::Drawable
{
protected:
	sf::Sprite sp;
	sf::RectangleShape hitbox;
	float speed;
	// Оценка для обработки выхода за экран и коллизий.
	float radius;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	Entity(sf::Texture &tx, float speed, sf::Vector2f pos, float hitboxRatio);
	//~Entity();
	float getRadius() const;
	sf::Vector2f getPosition() const;
	sf::Vector2f* getVertices() const;
	void move(sf::Vector2f offset);
	void setPosition(sf::Vector2f position);
	void setTexture(sf::Texture &tx, sf::Vector2f pos, float hitboxRatio);
};
