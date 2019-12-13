#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include "config.h"
#include "Hitbox.h"

// Загружает и хранит в себе текстуры и схемы хитбоксов (Singleton).
// список объектов - см. config.h.
class Loader
{
	static Loader* instance;
	Loader();
	Loader(const Loader&);
	//Loader& operator=(Loader&);
	std::vector<sf::Texture> EnemyTx;
	std::vector<sf::Texture> ProjTx;
	std::vector<sf::Texture> PlayerTx;
	std::vector<sf::Texture> textures;
	std::vector<Hitbox> hitboxes;
public:
	static Loader* get()
	{
		if (!instance)
			instance = new Loader();
		return instance;
	}
	Hitbox& HB(const int ID);
	sf::Texture& TX(const int ID);
};