#pragma once
#include"Enemy.h"
#include<vector>
#include <list>
class Wave
{
public:
	float Time;
	std::list<Enemy*> Enemies;
};
