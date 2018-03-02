#pragma once

#include "GameEngine.h"

class State_Intro :	public GameState {

public:
	State_Intro(GameEngine *engine, ResourceManager *rm);
	~State_Intro();

	//Inherited methods from GameState
	void handleEvents();
	void update();
	void render();

private:
	GameEngine *ptrGameEngine;
	sf::Sprite *background;
	sf::Text *logo;
	
	//add font support to resource manager
	sf::Font *font;
};