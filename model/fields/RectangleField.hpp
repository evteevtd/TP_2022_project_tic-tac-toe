#pragma once

#include "IField.hpp"

class RectangleField : public IField {
public:
	RectangleField(int x_size, int y_size);
	Board get_board() const override;
	bool set_cell(Point, Symbol) override;
private:
	int x_size_, y_size_;
	std::vector<std::vector<Symbol>> board_;
};
