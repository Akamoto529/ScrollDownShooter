#include "Collision.h"
#include <iostream>

//bool Collision::CollisionTest(const Entity* ent1, const Entity* ent2)
//{
//	return CircleTest(ent1, ent2) && PolygonTest(ent1, ent2);
//}

bool Collision::RectangleTest(const Entity* ent1, const Entity* ent2)
{
	return ent1->getGlobalBounds().intersects(ent2->getGlobalBounds());
}

//static bool PolygonTest(const Entity& ent1, const Entity& ent2)
//{
//	sf::VertexArray hb1 = ent1.getPolygon
//	sf::VertexArray poly2 = ent2.getPolygon();
//
//	
//}