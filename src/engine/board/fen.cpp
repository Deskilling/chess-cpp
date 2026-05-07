#include "board.hpp"

#include <iostream>

void Board::initDefault() {
	loadFen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
}

void Board::loadFen(const std::string& fen) {
	// TODO
	// https://www.chess.com/terms/fen-chess
	// https://en.wikipedia.org/wiki/Forsyth%E2%80%93Edwards_Notation
	// https://www.chessprogramming.org/Forsyth-Edwards_Notation

	int rank = 0;
	int file = 7;
	int mode = 0;
	for (char c : fen) {
		switch (mode) {
		case 0: {
			if (c == ' ') {
				mode++;
				break;
			}

			if (c == '/') {
				rank = 0;
				file--;
				continue;
			}

			if (isdigit(c)) {
				rank += c - '0';
				continue;
			}

			Color color = isupper(c) ? Color::White : Color::Black;
			char cl = tolower(c);
			PieceType type;
			switch (cl) {
			case 'p':
				type = PieceType::Pawn;
				break;
			case 'r':
				type = PieceType::Rook;
				break;
			case 'n':
				type = PieceType::Knight;
				break;
			case 'b':
				type = PieceType::Bishop;
				break;
			case 'q':
				type = PieceType::Queen;
				break;
			case 'k':
				type = PieceType::King;
				break;
			default:
				std::cout << "Invalid Piece";
				return;
			}
			tiles[rank][file] = new Piece{rank, file, type, color};
			rank++;
			break;
		}

		case 1: {
			if (c == ' ') {
				mode++;
				break;
			}
			Color color = (c == 'w') ? Color::White : Color::Black;
			currentTurn = color;
			break;
		}

		case 2:
		case 3: {
			if (c == ' ') {
				mode++;
				break;
			}
			switch (c) {
			case '-': {
				mode = 4;
				break;
			}
			case 'K':
				White.canKingSideCastle = true;
				break;
			case 'Q':
				White.canQueenSideCastle = true;
				break;
			case 'k':
				Black.canKingSideCastle = true;
				break;
			case 'q':
				Black.canQueenSideCastle = true;
				break;
			}
			break;
		}
		}
	}
}
