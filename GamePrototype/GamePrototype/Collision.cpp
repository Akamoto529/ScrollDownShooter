#include "Collision.h"
#include <iostream>

bool Collision::CollisionTest(const Entity* ent1, const Entity* ent2)
{
	if (ent1 == nullptr || ent2 == nullptr)
		return false;
	return RectangleTest(ent1, ent2) && PolygonTest(ent1, ent2);
}

bool Collision::RectangleTest(const Entity* ent1, const Entity* ent2)
{
	return ent1->getHitboxBounds().intersects(ent2->getHitboxBounds());
}

bool Collision::PolygonTest(const Entity* ent1, const Entity* ent2)
{
	std::list<sf::Vector2f> ver1 = ent1->getHitbox().getVerticesAbs();
	std::list<sf::Vector2f> ver2 = ent2->getHitbox().getVerticesAbs();

	sf::Vector2f previous;
	float area;

	for (sf::Vector2f vertice : ver1)
	{
		previous = ver2.back();
		area = 0.f;
		for (sf::Vector2f current : ver2)
		{
			area += Hitbox::TriangleArea(previous, current, vertice);
			previous = current;
		}

		if (area <= ent2->getHitbox().getArea())
			return true;
	}

	for (sf::Vector2f vertice : ver2)
	{
		previous = ver1.back();
		area = 0.f;
		for (sf::Vector2f current : ver1)
		{
			area += Hitbox::TriangleArea(previous, current, vertice);
			previous = current;
		}

		if (area <= ent1->getHitbox().getArea())
			return true;
	}

	return false;
}