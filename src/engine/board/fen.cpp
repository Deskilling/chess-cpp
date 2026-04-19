#include "board.hpp"

void Board::initDefault() {
	loadFen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
}

void Board::loadFen(const std::string& fen) {
	// TODO
	// https://www.chess.com/terms/fen-chess
	// https://en.wikipedia.org/wiki/Forsyth%E2%80%93Edwards_Notation
	// https://www.chessprogramming.org/Forsyth-Edwards_Notation
}
