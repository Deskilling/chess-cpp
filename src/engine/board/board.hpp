#ifndef BOARD_HPP
#define BOARD_HPP

#include <string>

#include "../piece/piece.hpp"

struct Move {
	int fromX, fromY;
	int toX, toY;
};

class Board {
  private:
	Piece* tiles[8][8];
	Color currentTurn;

  public:
	Board();
	~Board();

	void initDefault();
	void loadFen(const std::string& fen);

	Piece* getPiece(int x, int y) const;

	bool isValidMove(const Move& move) const;
	void move(Move& move);

	bool isInCheck(Color color) const;
	bool isCheckmate(Color color) const;

	Color getCurrentTurn() const;
	void print() const;
};

#endif
