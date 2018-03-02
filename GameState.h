#ifndef GAME_STATE_H
#define GAME_STATE_H


//Small abstract class to represent a game state
class GameState
{
public:
	virtual ~GameState() {};

	virtual void handleEvents() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
};
#endif // !GAME_STATE_H