#include "board.hpp"
#include "../../util.hpp"

bool Board::isValidMove(const Move& move) const {
	Piece* piece = getPiece(move.fromX, move.fromY);
	if (piece == nullptr) {
		return false;
	}

	if ((move.fromX == move.toX) && (move.fromY == move.toY)) {
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

	case PieceType::Rook: {
		int deltaX = dist(move.fromX, move.toX);
		int deltaY = dist(move.fromY, move.toY);
		int steps = deltaX + deltaY;

		bool moveRank = (deltaX != 0 && deltaY == 0);
		bool moveFile = (deltaX == 0 && deltaY != 0);

		int moveX = (moveRank) ? (move.toX > move.fromX ? 1 : -1) : 0;
		int moveY = (moveFile) ? (move.toY > move.fromY ? 1 : -1) : 0;

		if (moveFile || moveRank) {
			for (int i = 1; i < steps; i++) {
				if (tiles[move.fromX + i * moveX][move.fromY + i * moveY] != nullptr) {
					return false;
				}
			}

			return target == nullptr || notSameColor;
		}
		break;
	}

	case PieceType::Knight: {
		int deltaX = dist(move.fromX, move.toX);
		int deltaY = dist(move.fromY, move.toY);

		bool lShape = ((deltaX == 2 && deltaY == 1) || (deltaX == 1 && deltaY == 2));

		if (lShape) {
			return target == nullptr || notSameColor;
		}
		break;
	}

	case PieceType::Bishop: {
		int deltaX = dist(move.fromX, move.toX);
		int deltaY = dist(move.fromY, move.toY);
		int steps = deltaX;

		bool moveDiagonal = (deltaX == deltaY);

		int moveX = (move.toX > move.fromX) ? 1 : -1;
		int moveY = (move.toY > move.fromY) ? 1 : -1;

		if (moveDiagonal) {
			for (int i = 1; i < steps; i++) {
				if (tiles[move.fromX + i * moveX][move.fromY + i * moveY] != nullptr) {
					return false;
				}
			}

			return target == nullptr || notSameColor;
		}
		break;
	}
	}

	return false;
}

void Board::move(Move& move) {
	// TODO
}
