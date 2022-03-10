#pragma once

#include <vector>
#include <map>
#include <algorithm>

enum class Symbol {
	Empty,
	Cross,
	Zero
};

struct Point {
	int x, y;
	Point operator-(Point other) const { return Point{x - other.x, y - other.y}; }
	Point operator+(Point other) const { return Point{x + other.x, y + other.y}; }
	Point rotated() const { return Point{-y, x} }
};
Point operator<(const Point& lhs, const Point& rhs) {
	return tie(lhs.x, lhs.y) < tie(rhs.x, rhs.y);
}

struct Figure {
	std::vector<Point> points;
	Figure rotated(Point center = Point()) const;
	Figure shifted(int index = 0, Point center = Point()) const;
};

struct Board {
	std::map<Point, Symbol> cells;
};

class IField {
public:
	std::vector<Figure> get_figures() const;
	void add_figure(Figure&);
	void add_figures(const std::vector<Figure>&);
	bool is_winning(Symbol) const;

	virtual Board get_board() const = 0;
	virtual bool set_cell(Point, Symbol) = 0; // возвращает был ли ход выполнен

	virtual ~Field() {}
protected:
	vector<Figure> victorious_;
};

class RectangleField : public IField {
public:
	RectangleField(int x_size, int y_size);
	Board get_board() const override;
	bool set_cell(Point, Symbol) override;
private:
	int x_size_, y_size_;
	std::vector<std::vector<Symbol>> board_;
};

class IPlayer {
public:
	virtual Point get_move(const IField*, Sumbol) const = 0;
};

class BasicAIPlayer : public IPlayer {
public:
	Point get_move(const IField*, Sumbol) const override;
};

class BasicHumanPlayer : public IPlayer {
public:
	Point get_move(const IField*, Sumbol) const override;
};