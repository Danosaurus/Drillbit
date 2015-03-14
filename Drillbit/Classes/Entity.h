#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "cocos2d.h"
#include "Box2D.h"
#include <list>

USING_NS_CC;

class Entity
{
public:
	static Entity* makeEntity(b2World* world, float density, Vec2 pos, Sprite* sprite);
	void applyForce(Vec2 force);
	Sprite* getUpdateSprite();
	float getMass();
	Vec2 getPos();
	b2Body* getBody();
private:
	Entity(b2World* world, float density, Vec2 pos, Sprite* sprite);
	b2Body* body;
	b2World* world;
};

#endif
