#pragma once
#include "Entity.h"

class Collision
{
public:
	// Использует RectangleTest и PolygonTest.
	static bool CollisionTest(const Entity* ent1, const Entity* ent2);
	static bool PolygonTest(const Entity* ent1, const Entity* ent2);
	static bool RectangleTest(const Entity* ent1, const Entity* ent2);
};

