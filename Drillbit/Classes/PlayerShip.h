#ifndef __PLAYERSHIP_H__
#define __PLAYERSHIP_H__

#include "cocos2d.h"
#include "Entity.h"
#include "Box2D.h"
#include <list>

USING_NS_CC;

class PlayerShip : public Entity
{
public:
	static PlayerShip* makePlayerShip(b2World* world, float density, Vec2 pos, Sprite* sprite);
	//void applyForce(Vec2 force);
	//Sprite* getUpdateSprite();
	//float getMass();
	//Vec2 getPos();
	//b2Body* getBody();
private:
	PlayerShip(b2World* world, float density, Vec2 pos, Sprite* sprite);
	//b2Body* body;
	//b2World* world;
	//need to add the ship parts here
};

#endif
