#pragma once
#include "SFML/Graphics.hpp"

// ������ � ������������ ���������.
class Timer
{
private:
	sf::Clock clock;
	sf::Time runtime;
	bool paused;
public:
	Timer();
	sf::Time getElapsedTime();
	void pause();
	void reset();
	void start();
};

