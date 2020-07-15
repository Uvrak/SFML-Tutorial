#include "stdafx.h"
#include "Entity.h"

void Entity::initVariables()
{
	this->pTexture = nullptr;
	this->pSprite = nullptr;
	this->movementSpeed = 100.f;
}

Entity::Entity()
{
	this->initVariables();
	//this->createSprite();
	
}

Entity::~Entity()
{
	delete this->pSprite;
}

void Entity::createSprite(float x, float y, sf::Texture* pTexture)
{
	this->pSprite = new sf::Sprite(*pTexture);
	this->pSprite->setPosition(x, y);
	this->pTexture = pTexture;
	
}

void Entity::move(const float dir_x, const float dir_y, const float& dt)
{
	if (this->pSprite)
		this->pSprite->move(dir_x * this->movementSpeed *dt, dir_y * this->movementSpeed *dt);
}

void Entity::update(const float& dt)
{
}

void Entity::render(sf::RenderTarget* pTarget)
{
	if (this->pSprite)
		pTarget->draw(*this->pSprite);
}
