﻿#include "Gun.h"
#include <iostream>


// Gun.


Gun::Gun(const sf::Vector2f direction, const std::string projName, const sf::Time reloadTime)
{
	this->direction = direction;
	this->reloadTime = reloadTime;
	this->projName = projName;
	timer.reset();
}

sf::Vector2f Gun::getDirection() const
{
	return this->direction;
}

void Gun::setDirection(const sf::Vector2f direction)
{
	this->direction = direction;
}
