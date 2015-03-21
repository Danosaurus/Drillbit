#include "Universe.h"
#include "Box2D.h"
#include <cstdlib>
#include <ctime>

#define G_CONSTANT 0.001

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

void Universe::generateEntities(Vec2 origin, Size visibleSize){
	//stub

	/**
	 * @TODO
	 * there's a better way to pseudorandom generate in C++11
	 */

	//srand (time(0));
	addEntity(Entity::makeStar(world, 10000, Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y), Vec2::ZERO, Sprite::create("Star01.png")));
	for(auto i = 0; i < 4; ++i)
	{
		addEntity(Entity::makePlanet(world, 100, Vec2(visibleSize.width/2 + origin.x + 100 + 100 * ( i + 1 ), visibleSize.height/2 + origin.y), Vec2(0,160000000000 - 50000000000 * i), Sprite::create("Planet01.png")));
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
			Vec2 accRow(entities[row]->getPos(), entities[col]->getPos());
			accRow.normalize();
			accRow.scale(sForce);
			Vec2 accCol = accRow;
			accCol.negate();
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
