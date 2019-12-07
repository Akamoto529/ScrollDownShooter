#include "Loader.h"

Loader* Loader::instance = 0;

Loader::Loader()
{
	textures.resize(ID_count);
	textures[bullet_ID].loadFromFile("Assets/Projectiles/bullet.png");
	textures[enemy1_ID].loadFromFile("Assets/Enemies/1.png");
	textures[enemy2_ID].loadFromFile("Assets/Enemies/2.png");
	textures[pl_ID].loadFromFile("Assets/pl.png");

	hitboxes.resize(ID_count);

	hitboxes[enemy1_ID] = Hitbox({
	sf::Vector2f(0,-140),
	sf::Vector2f(-146,12),
	sf::Vector2f(-56,119),
	sf::Vector2f(56,119),
	sf::Vector2f(146,12)
		});

	hitboxes[enemy2_ID] = Hitbox({
		sf::Vector2f(24,0),
		sf::Vector2f(-16, 16),
		sf::Vector2f(16, -16),
		sf::Vector2f(16, 16)
		});

	hitboxes[pl_ID] = Hitbox({
		sf::Vector2f(0,-140),
		sf::Vector2f(11,56),
		sf::Vector2f(24,74),
		sf::Vector2f(37,56)
		});

	hitboxes[bullet_ID] = Hitbox({
		sf::Vector2f(0,-9),
		sf::Vector2f(-7,7),
		sf::Vector2f(7,7)
		});
}

Hitbox& Loader::HB(const int ID)
{
	return hitboxes[ID];
}

sf::Texture& Loader::TX(const int ID)
{
	return textures[ID];
}