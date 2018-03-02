#include "Board.h"



Board::Board(ResourceManager *rm, float tileScale) {
	map = new std::vector<Tile*>();

	//fill map with tiles;
	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++) {
			Tile *tmp;
			if (row % 2 == 0) {
				if (col % 2 == 0) {
					tmp = new Tile(rm, "tile_Grass", tileScale);
				}
				else {
					tmp = new Tile(rm, "tile_FrozenGround", tileScale);
				}
			}
			else {
				if (col % 2 == 0) {
					tmp = new Tile(rm, "tile_FrozenGround", tileScale);
				}
				else {
					tmp = new Tile(rm, "tile_Grass", tileScale);
				}
			}			
			tmp->setPosition(col * tmp->getTextureSize() * tileScale, row * tmp->getTextureSize() * tileScale);
			map->push_back(tmp);
		}
	}

}

Board::~Board() {
	for (int i = 0; i < map->size(); i++) {
		delete map->at(i);
	}
	delete map;
}

void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for (int i = 0; i < map->size(); i++) {
		target.draw(*map->at(i));
	}
}