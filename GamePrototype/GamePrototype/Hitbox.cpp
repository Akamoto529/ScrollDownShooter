#include "Hitbox.h"

Hitbox::Hitbox()
{
	this->vertices = {};
	this->area = 0.f;
}

Hitbox::Hitbox(std::list<sf::Vector2f> vertices)
{
	this->vertices = {};
	this->vertices.push_back(vertices.front());
	// Для построения boundingBox.
	float minx = vertices.front().x;
	float miny = vertices.front().y;
	float maxx = vertices.front().x;
	float maxy = vertices.front().y;
	vertices.pop_front();

	this->area = 0.f;
	for (sf::Vector2f vertice : vertices)
	{
		area += TriangleArea(this->vertices.front(), this->vertices.back(), vertice);
		this->vertices.push_back(vertice);
		if (vertice.x < minx)
			minx = vertice.x;
		if (vertice.y < miny)
			miny = vertice.y;
		if (vertice.x > maxx)
			maxx = vertice.x;
		if (vertice.y > maxy)
			maxy = vertice.y;
	}
	this->boundingBox.left = minx;
	this->boundingBox.top = miny;
	this->boundingBox.width = maxx - minx;
	this->boundingBox.height = maxy - miny;
}

void Hitbox::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// Bounding Box.
	auto glob = this->getGlobalBounds();
	sf::VertexArray rect(sf::LineStrip,5);
	rect[0] = sf::Vector2f(glob.left, glob.top);
	rect[1] = sf::Vector2f(glob.left, glob.top+glob.height);
	rect[2] = sf::Vector2f(glob.left+glob.width, glob.top+glob.height);
	rect[3] = sf::Vector2f(glob.left+glob.width, glob.top);
	rect[4] = sf::Vector2f(glob.left, glob.top);
	target.draw(rect);

	// Polygon.
	sf::VertexArray box(sf::TrianglesStrip);
	for (sf::Vector2f vertex : this->getVerticesAbs())
		box.append(sf::Vertex(vertex, sf::Color::Green));
	box.append(sf::Vertex(this->getVerticesAbs().front(), sf::Color::Green));
	target.draw(box);
	//target.draw(this.globalbounds)
}

float Hitbox::getArea() const
{
	return this->area;
}

sf::FloatRect Hitbox::getGlobalBounds() const
{
	sf::FloatRect globalbox = this->boundingBox;
	globalbox.left += this->getPosition().x - this->getOrigin().x;
	globalbox.top += this->getPosition().y - this->getOrigin().y;
	return globalbox;
}

std::list<sf::Vector2f> Hitbox::getVerticesAbs() const
{
	std::list<sf::Vector2f> absolute;
	for (sf::Vector2f vertice : this->vertices)
		absolute.push_back(this->getPosition() - this->getOrigin() + vertice);
	return absolute;
}

void Hitbox::rotate(const float angle)
{
	this->Transformable::rotate(angle);
	sf::Vector2f vector;
	for (sf::Vector2f& vertice : this->vertices)
	{
		vector = (vertice - this->getOrigin());
		vertice.x = vector.x * cos(PI * angle / 180) - vector.y * sin(PI * angle / 180) + this->getOrigin().x;
		vertice.y = vector.x * sin(PI * angle / 180) + vector.y * cos(PI * angle / 180) + this->getOrigin().y;
	}

	// Обновление boundingBox.
	float minx = vertices.front().x;
	float miny = vertices.front().y;
	float maxx = vertices.front().x;
	float maxy = vertices.front().y;
	for (sf::Vector2f vertice : this->vertices)
	{
		if (vertice.x < minx)
			minx = vertice.x;
		if (vertice.y < miny)
			miny = vertice.y;
		if (vertice.x > maxx)
			maxx = vertice.x;
		if (vertice.y > maxy)
			maxy = vertice.y;
	}
	this->boundingBox.left = minx;
	this->boundingBox.top = miny;
	this->boundingBox.width = maxx - minx;
	this->boundingBox.height = maxy - miny;
}

void Hitbox::setRotation(const float angle)
{
	this->rotate(-this->getRotation() + angle);
}

 float Hitbox::TriangleArea(const sf::Vector2f a, const sf::Vector2f b, const sf::Vector2f c)
{
	return 0.5f * abs(a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y));
}