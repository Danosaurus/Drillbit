#include "PlayerShip.h"
#include "Box2D.h"

USING_NS_CC;

PlayerShip::PlayerShip(b2World* world, float density, Vec2 pos, Sprite* sprite):
		Entity(world, density, pos, sprite)
{

}

PlayerShip* PlayerShip::makePlayerShip(b2World* world, float density, Vec2 pos, Sprite* sprite)
{
	return new PlayerShip(world, density, pos, sprite);
}

