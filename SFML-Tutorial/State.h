#pragma once
class State
{
private:
	std::vector<sf::Texture>* textures;

public:
	//Constructors /Destructors
	State();
	virtual ~State();
	
	//Functions
	virtual void update() = 0;
	virtual void render() = 0;

};

