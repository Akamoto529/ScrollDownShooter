#pragma once
#include "Entity.h"

// Суперкласс для всех запускаемых снарядов.
class Projectile : public Entity
{
	// Вектор скорости снаряда (px/msec).
	sf::Vector2f velocity;
public:
	Projectile(sf::Vector2f direction, sf::Texture& tx, float speed, sf::Vector2f pos, float hitboxRatio = 1.f);
	sf::Vector2f getVelocity();
	void setVelocity(sf::Vector2f direction);
    // Малое перемещение снаряда.
    void step(sf::Time dt);
};

//// Круглая пуля. (старая версия)
//class Bullet : public Projectile
//{
//	sf::CircleShape bullet;
//	sf::Color color;
//	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
//public:
//	Bullet(sf::Vector2f position = sf::Vector2f(0, 0), sf::Vector2f direction = sf::Vector2f(0, 0));
//};
