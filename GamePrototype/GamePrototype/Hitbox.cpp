#include "Hitbox.h"

// «аглушка дл€ конструктора Entity, нужно избавитьс€.
Hitbox::Hitbox()
{
	this->vertices = {};
	this->area = 0.f;
}

Hitbox::Hitbox(std::list<sf::Vector2f> vertices)
{
	this->vertices = {};
	this->vertices.push_back(vertices.front());
	vertices.pop_front();
	this->vertices.push_back(vertices.front());
	vertices.pop_front();

	this->area = 0.f;
	for (sf::Vector2f vertice : vertices)
	{
		area += TriangleArea(this->vertices.front(), this->vertices.back(), vertice);
		this->vertices.push_back(vertice);
	}
}

void Hitbox::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::VertexArray box(sf::TrianglesStrip);
	for (sf::Vector2f vertex : this->getVerticesAbs())
		box.append(sf::Vertex(vertex, sf::Color(128,0,0)));
	box.append(sf::Vertex(this->getVerticesAbs().front(), sf::Color(128, 0, 0)));
	target.draw(box);
}

float Hitbox::getArea() const
{
	return this->area;
}

std::list<sf::Vector2f> Hitbox::getVerticesAbs() const
{
	std::list<sf::Vector2f> absolute;
	for (sf::Vector2f vertice : this->vertices)
		absolute.push_back(this->getPosition() - this->getOrigin() + vertice);
	return absolute;
}

 float Hitbox::TriangleArea(const sf::Vector2f a, const sf::Vector2f b, const sf::Vector2f c)
{
	return 0.5f * abs(a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y));
}