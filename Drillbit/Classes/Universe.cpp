#include "Universe.h"
#include "Box2D.h"
#include <cstdlib>
#include <ctime>

#define G_CONSTANT 1000000

USING_NS_CC;

Universe::Universe()
{
	b2Vec2 gravity = b2Vec2(0.0f, 0.0f);
	world = new b2World(gravity);
}

void Universe::addEntity(Entity* entity)
{
	entities.push_back(entity);
}

void Universe::step(float delta)
{
	world->Step(delta, 10, 10);
}

void Universe::generateEntities(){
	//stub

	/**
	 * @TODO
	 * there's a better way to pseudorandom generate in C++11
	 */
	srand (time(0));
	for(auto i = 0; i < 5; ++i)
	{
		auto entity = Entity::makeEntity(world, rand() % 500 + 200, Vec2(rand() % 500 + 250,rand() % 500 + 250), Sprite::create("jupiter.png"));
		addEntity(entity);
	}
}

void Universe::applyGravity()
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
			entities[row]->applyForce(accRow);
			entities[col]->applyForce(accCol);
		}
	}
}

void Universe::render()
{
	for(auto i = 0; i < entities.size(); ++i) {
		entities[i]->getUpdateSprite();
	}
}

std::vector<Entity*> Universe::getEntities()
{
	return entities;
}
