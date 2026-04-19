#include "board.hpp"
#include "../../util.hpp"

bool Board::isValidMove(const Move& move) const {
	Piece* piece = getPiece(move.fromX, move.fromY);
	if (piece == nullptr) {
		return false;
	}

	Piece* target = tiles[move.toX][move.toY];
	bool notSameColor = target != nullptr && piece->getColor() != target->getColor();

	switch (piece->getType()) {
	case PieceType::Pawn: {
		int dir = (piece->getColor() == Color::White) ? 1 : -1;
		int rank = (piece->getColor() == Color::White) ? 1 : 6;

		int deltaX = dist(move.fromX, move.toX);
		int moved = move.toY - move.fromY;

		bool targetEmpty = (target == nullptr);

		bool sameFile = (move.fromX == move.toX);
		bool forwardOne = (moved * dir == 1 && sameFile && targetEmpty);
		bool forwardTwo =
		    (rank == move.fromY && moved * dir == 2 && sameFile && tiles[move.toX][move.fromY + dir] == nullptr && targetEmpty);
		bool capture = (moved * dir == 1 && deltaX == 1 && tiles[move.toX][move.toY] != nullptr && notSameColor);

		if (forwardOne || capture || forwardTwo) {
			return true;
		}
		break;
	}
	}

	return false;
}

void Board::move(Move& move) {
	// TODO
}
