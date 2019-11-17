#pragma once
#include "Entity.h"

// ���������� ��� ���� ����������� ��������.
class Projectile : public Entity
{
	// ������ �������� �������.
	sf::Vector2f velocity;
protected:
	// ������ ��������.
	float speed;
public:
	Projectile(sf::Vector2f position = sf::Vector2f(0, 0),
		sf::Vector2f direction = sf::Vector2f(0, 0));
	sf::Vector2f getVelocity();
	void setVelocity(sf::Vector2f direction);
    // ����� ����������� �������.
    void step();
};

// ������� ����.
class Bullet : public Projectile
{
	sf::CircleShape bullet;
	sf::Color color;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	Bullet(sf::Vector2f position = sf::Vector2f(0, 0), sf::Vector2f direction = sf::Vector2f(0, 0));
	float getRadius() override;

};
