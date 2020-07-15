#include "stdafx.h"
#include "Entity.h"

Entity::Entity()
{
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
	this->movementSpeed = 100.f;
}

Entity::~Entity()
{
}

void Entity::move(const float dir_x, const float dir_y, const float& dt)
{

	this->shape.move(dir_x * this->movementSpeed *dt, dir_y * this->movementSpeed *dt);
}
