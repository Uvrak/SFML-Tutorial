#pragma once
class Entity
{
private:

protected:
	sf::RectangleShape shape;
	float movementSpeed;

public:
	//Constructors /Desturctors
	Entity();
	virtual ~Entity();

	//Fuctions
	virtual void move(const float dir_x, const float dir_y, const float& dt);
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* pTarget) = 0;
};

