#include "Collision.h"

//bool Collision::CollisionTest(const Entity& ent1, const Entity& ent2)
//{
//	return CircleTest(ent1, ent2) && PolygonTest(ent1, ent2);
//}
//
//bool Collision::CircleTest(const Entity& ent1, const Entity& ent2)
//{
//	float dx = ent1.getPosition().x - ent2.getPosition().x;
//	float dy = ent1.getPosition().y - ent2.getPosition().y;
//	float r1 = ent1.getRadius();
//	float r2 = ent2.getRadius();
//
//	return dx * dx + dy * dy >= r1 * r1 + r2 * r2;
//}
//
//static bool PolygonTest(const Entity& ent1, const Entity& ent2)
//{
//
//}