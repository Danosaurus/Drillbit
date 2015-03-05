#include "Entity.h"

USING_NS_CC;

void Entity::updatePos()
{
	pos.add(vel);
	sprite->setPosition(pos);
}

Entity* Entity::makeEntity(float mass, Vec2 pos, Vec2 vel, Vec2 acc, Sprite* sprite)
{
	return new Entity(mass, pos, vel, acc, sprite);
}

void Entity::applyAccel(Vec2 acc)
{
	vel.add(acc);
}

float Entity::getMass()
{
	return mass;
}

Vec2 Entity::getPos()
{
	return pos;
}

Sprite* Entity::getSprite()
{
	return sprite;
}
