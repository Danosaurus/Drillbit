#include "World.h"
#include <cstdlib>
#include <ctime>

#define G_CONSTANT 1

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
	for(auto i = 0; i < 5; ++i)
	{
		auto entity = Entity::makeEntity(rand() % 500 + 200, Vec2(rand() % 500 + 250,rand() % 500 + 250), Vec2(0,0), Vec2(0,0), Sprite::create("jupiter.png"));
		entity->updatePos();
		addEntity(entity);
	}
}

void World::updateEntities()
{
	auto length = entities.size();
	auto r2 = 0.;
	auto sForce = 0.;
	for (auto row = 0; row < length; ++row) {
		for (auto col = row + 1; col < length; ++col) {
			r2 = entities[row]->getPos().distanceSquared(entities[col]->getPos());	//holy cow Vec2 is op, they do everything for us :D
			sForce = G_CONSTANT * entities[row]->getMass() * entities[col]->getMass() / r2;
			Vec2 vForce(entities[row]->getPos(), entities[col]->getPos());
			vForce.normalize();
			vForce.scale(sForce);
			Vec2 accCol = vForce, accRow = vForce;
			accRow.scale(1/entities[row]->getMass());
			accCol.negate();
			accCol.scale(1/entities[row]->getMass());
			entities[row]->accel(accRow);
			entities[col]->accel(accCol);
		}
	}
	for(auto row = 0; row < length; ++row) {
		log("%d: %f-%f", row, entities[row]->getVel().x, entities[row]->getVel().y);
		entities[row]->updatePos();
	}
}

std::vector<Entity*> World::getEntities()
{
	return entities;
}
