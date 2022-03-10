#include <vector>

enum class Symbol {
	Empty,
	Cross,
	Zero
};

struct Point {
	int x, y;
};

struct Figure {
	std::vector<Point> points;
	Figure() {}
	Figure(std::vector<Point> points) : points(points) {}
	Figure rotated();
	Figure shifted(Point center_coordinates, int center_index);
};

struct Board {
	std::vector<std::pair<Point, Sumbol>> cells;
};

class IField {
public:
	std::vector<Figure> get_figures() const;
	void add_figure(Figure);
	void add_figures(std::vector<Figure>);
	bool is_winning(Symbol);

	virtual Board get_board() const = 0;
	virtual bool set_cell(Point, Symbol) = 0; // возвращает был ли ход выполнен

	virtual ~Field() {}
protected:
	vector<Figure> victorious_;
};

class RectangleField : public IField {
public:
	Board get_board() const override;
	bool set_cell(Point, Symbol) override;
	RectangleField(int x_size, int y_size) : x_size_(x_size), y_size_(y_size) {}
private:
	int x_size_, y_size_;
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