#pragma once
#include"Enemy.h"
#include<vector>
#include <list>

class Wave
{
public:
	float time;
	std::list<Enemy*> Enemies;
};
