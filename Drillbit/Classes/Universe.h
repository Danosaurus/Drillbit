#ifndef __WORLD_H__
#define __WORLD_H__

#include "cocos2d.h"
#include "Box2D.h"
#include "Entity.h"
#include "PlayerShip.h"
#include <list>

USING_NS_CC;

class Universe
{
public:
	Universe();
	void addEntity(Entity* entity);
	void generateEntities();
	void moveShip(float x, float y);
	void applyGravity();
	void render();
	void step(float delta);
	std::vector<Entity*> getEntities();
private:
	std::vector<Entity*> entities;
	b2World* world;
};

#endif
