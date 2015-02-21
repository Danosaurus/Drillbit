#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "cocos2d.h"

class Entity
{
public:
	Entity(float mass,Vec2 pos, Vec2 vel): mass(mass), pos(pos), vel(vel) {}
	Entity(float mass,Vec2 pos, Vec2 vel, List<Entity*> entitySubs): mass(mass), pos(pos), vel(vel), entitySubs(entitySubs) {}
	void addEntitySubs(Entity* entity);
private:
	float mass;
	Vec2 pos;
	Vec2 vel;
	List<Entity*> entitySubs;
};

#endif
