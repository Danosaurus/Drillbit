#include "World.h"
#include <cstdlib>
#include <ctime>

#define G_CONSTANT 6673

USING_NS_CC;

void World::addEntity(Entity* entity)
{
	entities.push_back(entity);
}

void World::generateEntities(){
	//stub

	/**
	 * @TODO
	 * there's a better way to pseudorandom generate in C++11
	 */
	srand (time(0));
	for(auto i = 0; i < 10; ++i)
	{
		auto entity = Entity::makeEntity(rand() % 900 + 100, Vec2(rand() % 1000,rand() % 1000), Vec2(0,0), Vec2(0,0), Sprite::create("jupiter.png"));
		entity->updatePos();
		addEntity(entity);
	}
}

void World::updateEntities()
{
	/**
	 * @TODO Not complete
	 * don't touch pls
	 */

	//construct acceleration table
	std::vector<std::vector<float>> accelTable;
	std::vector<float> accelRow;

	auto length = entities.size();
	auto r2 = 0.;
	auto force = 0.;
	for (auto row = 0; row < length; ++row) {
		for (auto col = row; col < length; ++col) {
			r2 = entities[row]->getPos().distanceSquared(entities[col]->getPos());	//holy cow Vec2 is op, they do everything for us :D
			force = G_CONSTANT * entities[row]->getMass() * entities[col]->getMass() / r2;
			Vec2 direction(entities[row]->getPos(), entities[col]->getPos());
			direction.normalize();
			direction.scale(force/entities[row]->getMass());
		}
		accelTable.push_back(accelRow);
	}
}

std::vector<Entity*> World::getEntities()
{
	return entities;
}
