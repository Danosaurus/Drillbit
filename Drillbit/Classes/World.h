#ifndef __WORLD_H__
#define __WORLD_H__

#include "cocos2d.h"
#include "Entity.h"
#include <list>

USING_NS_CC;

class World
{
public:
	World(){};
	void addEntity(Entity* entity);
	void generateEntities();
	void updateEntities();
	std::vector<Entity*> getEntities();
private:
	std::vector<Entity*> entities;
};

#endif
