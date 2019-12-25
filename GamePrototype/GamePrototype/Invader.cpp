#include "Invader.h"

Invader::Invader(sf::Vector2f pos)
	: Enemy(pos, 20.f, "Invader")
{
	this->HP = 100;
	this->startPos = pos;
	this->SidegunLeft = new Purple_gun(sf::Vector2f(0, 1));
	this->SidegunRight = new Purple_gun(sf::Vector2f(0, 1));
	this->Shotgun = new Green_gun(sf::Vector2f(0, 1));
}

void Invader::step(sf::Time dt)
{
	if (!frozen)
		this->move(sf::Vector2f(cos((this->getPosition().y - this->startPos.y) / 20) / 5, dt.asSeconds() * speed));

	if (overlay.getElapsedTime() >= sf::milliseconds(MSEC_PER_FRAME * 10))
	{
		this->overlay.reset();
		this->overlay.pause();
		this->setColor(sf::Color(255, 255, 255));
	}
}
std::list<Projectile*> Invader::shoot() const
{
	std::list<Projectile*>	list1 = SidegunLeft->shoot(sf::Vector2f(getPosition().x - 200.f, getPosition().y+100.f)),
		list2 = SidegunRight->shoot(sf::Vector2f(getPosition().x + 200.f, getPosition().y+100.f)),
		list3 = Shotgun->shoot(sf::Vector2f(getPosition().x, getPosition().y+100.f)),
		res;
	for (Projectile* proj : list1) {
		res.push_back(proj);
	}
	for (Projectile* proj : list2) {
		res.push_back(proj);
	}
	for (Projectile* proj : list3) {
		res.push_back(proj);
	}
	return res;
	return {};
}