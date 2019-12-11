#pragma once
#include <SFML/Graphics.hpp>
#include "Wave.h"
class Level
{
public:
	sf::Texture EnemyTx[1];
	sf::Texture ProjectileTx[1];
	Wave *waves;
	void Load(int Number);
	std::string IntToStr(int a);
	Level();
};

