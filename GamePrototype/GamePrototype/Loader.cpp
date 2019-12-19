#include "Loader.h"
#include <fstream>
#include <list>
Loader* Loader::instance = 0;
Loader::Loader()
{
	std::ifstream fin("Assets/Textures/Textures_List.txt"),finHB;
	std::string str;
	while (!fin.eof()) {
		fin >> str;
		Textures[str].loadFromFile("Assets/Textures/" + str + ".png");
	}
	fin.close();
	fin.open("Assets/Hitboxes/HB_List.txt");
	while (!fin.eof()) {
		fin >> str;
		finHB.open("Assets/Hitboxes/" + str + ".txt");
		int x, y;
		std::list<sf::Vector2f> temp;
		while (!finHB.eof()) {
			finHB >> x >>y;
			temp.push_back(sf::Vector2f(x, y));
		}
		finHB.close();
		Hitboxes[str] = temp;
	}
	fin.close();
	//setRepeated потом тоже перепишу в файлы
	Textures["polytech"].setRepeated(true);
	Textures["space"].setRepeated(true);
	/*Hitboxes["Enemy2"] = Hitbox({
		sf::Vector2f(25,0),
		sf::Vector2f(11,56),
		sf::Vector2f(24,74),
		sf::Vector2f(37,56)
		});
	Hitboxes["Player"] = Hitbox({
		sf::Vector2f(32,0),
		sf::Vector2f(21,35),
		sf::Vector2f(32,45),
		sf::Vector2f(43,31)
		});
	Hitboxes["Bullet"] = Hitbox({
		sf::Vector2f(8,2),
		sf::Vector2f(0,20),
		sf::Vector2f(18,21)
		});*/
}

/*Hitbox Loader::loadHB(std::string Name) {
	return;
}*/
Hitbox& Loader::HB(const std::string Name)
{
	return Hitboxes[Name];
}

sf::Texture& Loader::TX(const std::string Name)
{
	return Textures[Name];
}