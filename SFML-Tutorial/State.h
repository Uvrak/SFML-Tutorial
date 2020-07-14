#pragma once
class State
{
private:
	sf::RenderWindow* pWindow;
	std::vector<sf::Texture>* textures;

public:
	//Constructors /Destructors
	State(sf::RenderWindow* pWindow);
	virtual ~State();
	
	//Functions
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* pTarget) = 0;

};

