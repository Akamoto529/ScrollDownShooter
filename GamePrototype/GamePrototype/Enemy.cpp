#include "Enemy.h"

Enemy::Enemy(const sf::Vector2f pos)
	: Entity(pos, 400.f, enemy2_ID)
{
	gun = new Rifle(sf::Vector2f(0, 1), bullet_ID, this);
	health = 10;
	curPoint = 0;
}

bool Enemy::TakeDamage(const int dmg)
{
	this->health -= dmg;
	if (this->health <= 0)
		// Удаление происходит в сцене, не здесь.
		return 0;
	return 1;
}

std::list<Projectile*> Enemy::Shoot() const
{
	return gun->Shoot(this->getPosition());
}

void Enemy::step(sf::Time dt)
{
	if (curPoint < Path.size() - 1) {
		float x = Path[curPoint + 1].x - Path[curPoint].x;
		float y = Path[curPoint + 1].y - Path[curPoint].y;
		float length = sqrt(x * x + y * y);
		if ((abs(x / length * speed) > abs(Path[curPoint + 1].x - sp.getPosition().x)) || (abs(y / length * speed) > abs(Path[curPoint + 1].y - sp.getPosition().y))) {
			curPoint++;
			sp.setPosition(Path[curPoint].x, Path[curPoint].y);
		}
		else {
			sp.move(sf::Vector2f(x / length, y / length) * speed * (dt.asMicroseconds() / 1000000.f));
		}
	}
}