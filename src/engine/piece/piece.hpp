#ifndef PIECE_HPP
#define PIECE_HPP

enum class PieceType { Pawn, Rook, Knight, Bishop, Queen, King };
enum class Color { White, Black };

class Piece {
  private:
	int x;
	int y;
	PieceType type;
	Color color;

  public:
	Piece(int initX, int initY, PieceType initType, Color initColor) {
		x = initX;
		y = initY;

		type = initType;
		color = initColor;
	}

	int getX() const { return x; }
	int getY() const { return y; }

	PieceType getType() const { return type; }
	Color getColor() const { return color; }
};

#endif
