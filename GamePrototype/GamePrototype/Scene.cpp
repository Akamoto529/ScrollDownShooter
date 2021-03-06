﻿#include "Scene.h"
#include <iostream>

Scene::Scene()
{
	this->windowSize.x = (uint16_t)WINDOW_X;
	this->windowSize.y = (uint16_t)WINDOW_Y;
	this->overlay = new sf::RectangleShape(sf::Vector2f(windowSize));
	overlay->setPosition(0, 0);
	overlay->setFillColor(sf::Color::Transparent);

	this->bonuses = {};
	this->enemies = {};
	this->PlayerProjs = {};
	this->EnemyProjs = {};

}

void Scene::LoadLevel(int LvlNum) {
	this->bonuses = {};
	this->enemies = {};
	this->PlayerProjs = {};
	this->EnemyProjs = {};

	this->player = new Player();
	this->ui = new UI(player);
	this->lvl.Load(LvlNum, player);
	this->bg = lvl.getBG();
	this->curWave = 0;

	this->WaveTimer.reset();
	this->dtTimer.reset();
}

void Scene::AddEntities(std::list<Bonus*> bonuses)
{
	for (Bonus* bonus : bonuses)
	{
		if (bonus != nullptr)
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
	for (Enemy* enemy : this->enemies)
	{
		target.draw(*enemy, states);
	}
	target.draw(*player, states);
	for (Bonus* bonus : this->bonuses)
	{
		target.draw(*bonus, states);
	}
	target.draw(*overlay,states);
	target.draw(*ui, states);
}

void Scene::setOverlay(const sf::Color color)
{
	this->overlay->setFillColor(color);
}

void Scene::freeze()
{
	this->setOverlay(sf::Color(0, 128, 255, 128));
	for (auto& enemy : enemies)
		enemy->freeze();
	for (auto& projectile : EnemyProjs)
		projectile->freeze();
	this->WaveTimer.pause();
	this->setOverlay(sf::Color(0, 128, 255, 100));
}

void Scene::unfreeze()
{
	for (auto& bonus : bonuses)
		bonus->unfreeze();
	for (auto& enemy : enemies)
		enemy->unfreeze();
	for (auto& projectile : EnemyProjs)
		projectile->unfreeze();
	this->WaveTimer.start();
	this->setOverlay(sf::Color::Transparent);
}

bool Scene::outOfBounds(const Entity* entity) const
{
	sf::FloatRect box = entity->getSpriteBounds();
	if (box.top+box.height < 0
		|| box.left+box.width < 0
		|| box.top > this->windowSize.y
		|| box.left > this->windowSize.x)
		return 1;
	else
		return 0;
}

int Scene::update(sf::Time leftTillRender)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
	{
		player->freeze();
		for (auto& projectile : PlayerProjs)
			projectile->freeze();
		freeze();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
	{
		player->unfreeze();
		for (auto& projectile : PlayerProjs)
			projectile->unfreeze();
		unfreeze();
	}
	sf::Time dt = dtTimer.getElapsedTime();
	if (leftTillRender - dt <= this->lastUpdateDuration)
	{
		if ((curWave == 0) || (lvl.getWavesNumber() >= curWave+1) && (WaveTimer.getElapsedTime().asSeconds() >= lvl.getWaveTime(curWave - 1)))
		{
			AddEntities(lvl.getEnemies(curWave++));
			std::cout << curWave <<std::endl;
			WaveTimer.reset();
		}
		bg->step(dt);
		player->step(dt);
		AddPlayerProjs(player->shoot());

		for (auto k = this->bonuses.begin(); k != this->bonuses.end(); ++k)
		{
			auto& bonus = *k;
			bonus->step(dt);
			if (Collision::CollisionTest(bonus, this->player))
			{
				bonus->makeAction(this, this->player);
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
							this->AddEntities({ Bonus::dropBonus(enemy->getPosition()) });
							enemy = nullptr;
						}
						proj = nullptr;
						break;
					}
				}
			if (proj == nullptr)
				i = PlayerProjs.erase(i);
			if (this->PlayerProjs.empty() || i == this->PlayerProjs.end())
				break;
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
			if (proj == nullptr)
				i = EnemyProjs.erase(i);
			if (this->EnemyProjs.empty() || i == this->EnemyProjs.end())
				break;
		}

		for (auto j = this->enemies.begin(); j != this->enemies.end(); ++j)
		{
			auto& enemy = *j;
			if (enemy != nullptr && enemy->getPosition().y > WINDOW_Y && outOfBounds(enemy))
			{
				enemy = nullptr;
			}
			else if (Collision::CollisionTest(enemy, this->player))
			{
				enemy = nullptr;
				this->player->takeDamage(player->getFullHP());
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
		ui->update();
		lastUpdateDuration = dtTimer.getElapsedTime() - dt;
		dtTimer.reset();
	}

	Bonus::update(this, this->player);
	if ((curWave>= lvl.getWavesNumber() && enemies.empty()) || player->getHP() == 0) { return -2; }
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		return -1;
	else {
		return 0;
	}
}