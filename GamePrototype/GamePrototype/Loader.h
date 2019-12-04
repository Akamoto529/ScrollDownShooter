#pragma once
#include "SFML/Graphics.hpp"

// Загружает и хранит в себе текстуры (Singleton).
class Loader
{
	static Loader* instance;
	Loader();
	Loader(const Loader&);
	Loader& operator=(Loader&);

	sf::Texture player;
	sf::Texture enemy;
	sf::Texture projectile;
public:
	static Loader* getInstance()
	{
		if (!instance)
			instance = new Loader();
		return instance;
	}

	sf::Texture& GetPlayer();
	sf::Texture& GetEnemy();
	sf::Texture& GetProjectile();
};