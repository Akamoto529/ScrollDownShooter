#include "Scene.h"
#include <iostream>

Scene::Scene()
{
	this->windowSize.x = (uint16_t)WINDOW_X;
	this->windowSize.y = (uint16_t)WINDOW_Y;
	this->bonuses = {};
	this->enemies = {};
	this->PlayerProjs = {};
	this->EnemyProjs = {};
	LoadLevel(1);
	this->player = new Player();
	this->ui = new UI(player);
	this->WaveTimer.start();
	this->dtTimer.start();
}
void Scene::LoadLevel(int LvlNum) {
	this->bonuses = {};
	this->enemies = {};
	this->PlayerProjs = {};
	this->EnemyProjs = {};
	this->player = new Player();
	this->ui = new UI(player);
	this->lvl.Load(LvlNum);
	this->bg = lvl.getBG();
	this->curWave = 0;
	this->WaveTimer.reset();
	this->dtTimer.reset();
}
void Scene::AddEntities(std::list<Bonus*> bonuses)
{
	for (Bonus* bonus : bonuses)
	{
		this->bonuses.push_back(bonus);
	}
}
void Scene::AddEntities(std::list<Enemy*> enemies)
{
	for (Enemy* enemy : enemies)
	{
		this->enemies.push_back(enemy);
		this->enemies.back()->setRotation(180);
	}
}
void Scene::AddPlayerProjs(std::list<Projectile*> Projs) {
	for (Projectile* projectile : Projs)
		this->PlayerProjs.push_back(projectile);
}
void Scene::AddEnemyProjs(std::list<Projectile*> Projs) {
	for (Projectile* projectile : Projs)
		this->EnemyProjs.push_back(projectile);
}
void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*bg, states);
	for (Projectile* projectile : this->EnemyProjs)
	{
		target.draw(*projectile, states);
	}
	for (Projectile* projectile : this->PlayerProjs)
	{
		target.draw(*projectile, states);
	}
	// ...
	for (Enemy* enemy : this->enemies)
	{
		target.draw(*enemy, states);
	}
	target.draw(*player, states);

	for (Bonus* bonus : this->bonuses)
	{
		target.draw(*bonus, states);
	}
	target.draw(*ui, states);
}
bool Scene::outOfBounds(const Entity* entity) const
{
	sf::FloatRect box = entity->getSpriteBounds();
	if (box.top+box.height < 0
		|| box.left+box.width < 0
		|| box.top > this->windowSize.y
		|| box.left > this->windowSize.x)
		return 1;
	return 0;
}
void Scene::update()
{
	sf::Time dt = dtTimer.getElapsedTime();
	if (dt.asMicroseconds()/1000.f>= UPDATE_TIME_MSEC) {
		dtTimer.reset();
		if ((curWave == 0) || (WaveTimer.getElapsedTime().asMilliseconds() / 1000.f >= lvl.getWaveTime(curWave - 1))) {
			AddEntities(lvl.getEnemies(curWave++));
			WaveTimer.reset();
		}
		bg->step(dt);
		player->step(dt);
		//this->AddEntities(player->shoot());
		AddPlayerProjs(player->shoot());

		for (auto k = this->bonuses.begin(); k != this->bonuses.end(); ++k)
		{
			auto& bonus = *k;
			bonus->step(dt);
			if (Collision::CollisionTest(bonus, this->player))
			{
				bonus = nullptr;
				k = this->bonuses.erase(k);
			}

			if (this->bonuses.empty() || k == this->bonuses.end())
				break;
		}



		for (auto i = this->PlayerProjs.begin(); i != this->PlayerProjs.end(); ++i)
		{
			auto& proj = *i;
			proj->step(dt);
			if (outOfBounds(proj))	proj = nullptr;
			else
				for (auto& enemy : this->enemies)
				{
					if (Collision::CollisionTest(enemy, proj))
					{
						if (!enemy->takeDamage(proj->getDamage()))
						{
							this->AddEntities({ new Bonus(enemy->getPosition(),"hp-bonus") });
							enemy = nullptr;
						}
						proj = nullptr;
						break;
					}
				}
			if (proj == nullptr)	i = PlayerProjs.erase(i);
			if (this->PlayerProjs.empty() || i == this->PlayerProjs.end())	break;
		}
		for (auto i = this->EnemyProjs.begin(); i != this->EnemyProjs.end(); ++i)
		{
			auto& proj = *i;
			proj->step(dt);
			if (outOfBounds(proj))	proj = nullptr;
			if (proj != nullptr && Collision::CollisionTest(this->player, proj))
			{
				if (!player->takeDamage(proj->getDamage()))
					std::cout << "u ded\n";
				proj = nullptr;
				i = EnemyProjs.erase(i);
			}
			if (proj == nullptr)	i = EnemyProjs.erase(i);
			if (this->EnemyProjs.empty() || i == this->EnemyProjs.end())	break;
		}
		for (auto j = this->enemies.begin(); j != this->enemies.end(); ++j)
		{
			auto& enemy = *j;
			if (Collision::CollisionTest(enemy, this->player))
			{
				this->AddEntities({ new Bonus(enemy->getPosition(),"hp-bonus") });
				enemy = nullptr;
				this->player->takeDamage(player->getFullHP());
				std::cout << player->getHP();
			}

			if (enemy == nullptr)
				j = enemies.erase(j);
			else
			{
				enemy->step(dt);
				AddEnemyProjs(enemy->shoot());
			}

			if (this->enemies.empty() || j == this->enemies.end())
				break;
		}
		ui->Update();
	}
}