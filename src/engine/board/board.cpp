#include <cstdlib>

#include "board.hpp"

Board::Board() {
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			tiles[x][y] = nullptr;
		}
	}
}

Board::~Board() {
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			delete tiles[x][y];
		}
	}
}

Piece* Board::getPiece(int x, int y) const {
	return tiles[x][y];
}

Color Board::getCurrentTurn() const {
	return currentTurn;
};
