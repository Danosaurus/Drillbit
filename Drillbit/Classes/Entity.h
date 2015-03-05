#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "cocos2d.h"
#include <list>

USING_NS_CC;

class Entity
{
public:
	static Entity* makeEntity(float mass, Vec2 pos, Vec2 vel, Vec2 acc, Sprite* sprite);
	void updatePos();
	void applyAccel(Vec2 acc);
	float getMass();
	Vec2 getPos();
	Sprite* getSprite();
private:
	Entity(float mass, Vec2 pos, Vec2 vel, Vec2 acc, Sprite* sprite):
			mass(mass), pos(pos), vel(vel), acc(acc), sprite(sprite) {}
	float mass;
	Vec2 pos;
	Vec2 vel;
	Vec2 acc;
	Sprite* sprite;
};

#endif
