#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include "config.h"
#include "Hitbox.h"
//#include <map>

// Загружает и хранит в себе текстуры и схемы хитбоксов (Singleton).
// список объектов - см. config.h.
class Loader
{
	static Loader* instance;
	Loader();
	std::map<std::string, sf::Texture> Textures;
	std::map<std::string, Hitbox> Hitboxes;
	//Hitbox loadHB(std::string Name);
public:
	static Loader* get()
	{
		if (!instance)
			instance = new Loader();
		return instance;
	}
	Hitbox& HB(const std::string Name);
	sf::Texture& TX(const std::string Name);
};