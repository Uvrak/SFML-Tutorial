#pragma once
class Entity
{
private:
	//Functions
	void initVariables();

protected:
	sf::Texture* pTexture;
	sf::Sprite *pSprite;
	
	float movementSpeed;

public:
	//Constructors /Desturctors
	Entity();
	virtual ~Entity();

	//Component functions
	void createSprite(sf::Texture* texture);

	//Fuctions
	virtual void move(const float dir_x, const float dir_y, const float& dt);
	virtual void update(const float& dt) = 0;
    void render(sf::RenderTarget* pTarget);
};

