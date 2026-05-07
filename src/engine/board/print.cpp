#include "board.hpp"
#include <iostream>

void Board::print() const {
	std::cout << std::endl;

	for (int y = 7; y >= 0; y--) {
		std::cout << y + 1 << "  ";

		for (int x = 0; x < 8; x++) {
			if (tiles[x][y] == nullptr) {
				std::cout << ". ";
			} else {
				char c = '?';
				switch (tiles[x][y]->getType()) {
				case PieceType::Pawn:
					c = 'p';
					break;

				case PieceType::Rook:
					c = 'r';
					break;

				case PieceType::Knight:
					c = 'n';
					break;

				case PieceType::Bishop:
					c = 'b';
					break;

				case PieceType::Queen:
					c = 'q';
					break;

				case PieceType::King:
					c = 'k';
					break;
				}

				if (tiles[x][y]->getColor() == Color::White) {
					c = toupper(c);
				}

				std::cout << c << " ";
			}
		}

		std::cout << std::endl;
	}

	std::cout << std::endl << "   a b c d e f g h" << std::endl;
}
