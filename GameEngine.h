#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <SFML\Graphics.hpp>
#include <iostream>
#include "ResourceManager.h"
#include "Definitions.h"
#include "GameState.h"

//Game engine class that takes control of the whole game procedure
class GameEngine
{
public:
	GameEngine();
	~GameEngine();

	void run();
	
	void handleEvents();
	void update(float frametime);	
	void render();

	void calculateFrametime();
	float getActualScreenWidth() { return actualScreenWidth; }
	float getActualScreenHeight() { return actualScreenHeight; }
	sf::RenderWindow* getMainWindow() const { return mainWindow; };


/*	Unclear if still needed here
	void setNextState(int nextState);
	void changeState();
*/
private:
	void quit();

	sf::RenderWindow *mainWindow;
	sf::Event *event;
	sf::Clock *clock;
	ResourceManager *rm;

	bool isRunning;
	float calculatedFrametime;

	//GameState variables
	GameState *currentState;

	float actualScreenWidth;
	float actualScreenHeight;
};
#endif // !GAME_ENGINE_H