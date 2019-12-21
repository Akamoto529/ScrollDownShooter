#include "Loader.h"
#include <fstream>
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
}
Hitbox& Loader::HB(const std::string Name)
{
	return Hitboxes[Name];
}

sf::Texture& Loader::TX(const std::string Name)
{
	return Textures[Name];
}