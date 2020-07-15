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
	void createSprite(float x, float y, sf::Texture* texture);

	//Fuctions
	void move(const float dir_x, const float dir_y, const float& dt);
	void update(const float& dt);
    void render(sf::RenderTarget* pTarget);
};

