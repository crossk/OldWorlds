#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "Tile.h"

class Board : public sf::Drawable {
public:
	Board(ResourceManager* rm, float tileScale);
	~Board();

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	std::vector<Tile*> *map;
};
#endif