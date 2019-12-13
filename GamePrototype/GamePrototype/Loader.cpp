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

	hitboxes[enemy2_ID] = Hitbox({
		sf::Vector2f(25,0),
		sf::Vector2f(11,56),
		sf::Vector2f(24,74),
		sf::Vector2f(37,56)
		});

	hitboxes[pl_ID] = Hitbox({
		sf::Vector2f(32,0),
		sf::Vector2f(21,35),
		sf::Vector2f(32,45),
		sf::Vector2f(43,31)
		});

	hitboxes[bullet_ID] = Hitbox({
		sf::Vector2f(8,2),
		sf::Vector2f(0,20),
		sf::Vector2f(18,21)
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