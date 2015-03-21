#include "Entity.h"
#include "Box2D.h"

USING_NS_CC;

Entity::Entity(b2World* world, float density, Vec2 pos, Sprite* sprite):world(world)
{
	// Create ball body
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(pos.x, pos.y);
	bodyDef.userData = sprite;
	body = world->CreateBody(&bodyDef);

	// Create circle shape
	b2CircleShape circle;
	circle.m_radius = sprite->getContentSize().width/2;

	// Create shape definition and add to body
	b2FixtureDef shapeDef;
	shapeDef.shape = &circle;
	shapeDef.density = density;
	shapeDef.friction = 0.f;
	shapeDef.restitution = 0.f;
	body->CreateFixture(&shapeDef);

}

Entity* Entity::makeEntity(b2World* world, float density, Vec2 pos, Sprite* sprite)
{
	return new Entity(world, density, pos, sprite);
}

Sprite* Entity::getUpdateSprite()
{
    Sprite* data = (Sprite*)body->GetUserData();
    data->setPosition(Vec2(body->GetPosition().x, body->GetPosition().y));
    return data;
}

void Entity::applyForce(Vec2 force)
{
	body->ApplyForceToCenter(b2Vec2(force.x, force.y), true);
}

float Entity::getMass()
{
	return body->GetMass();
}

Vec2 Entity::getPos()
{
	return Vec2(body->GetPosition().x, body->GetPosition().y);
}

b2Body* Entity::getBody()
{
	return body;
}
