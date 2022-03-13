#pragma once

#include "../model.hpp"

class IField {
public:
	std::vector<Figure> get_figures() const;
	void add_figure(const Figure&);
	void add_figures(const std::vector<Figure>&);
	virtual bool has_move() const;
	virtual bool is_winning(Symbol) const;
	virtual bool is_winning_at(Point, Symbol) const;

	virtual Board get_board() const = 0;
	virtual bool set_cell(Point, Symbol) = 0; // возвращает был ли ход выполнен

	virtual ~IField() {}
protected:
	std::vector<Figure> victorious_;
};
