#pragma once

#include "IField.hpp"

class InfiniteField : public IField {
public:
	InfiniteField();
	Board get_board() const override;
	bool set_cell(Point, Symbol) override;

	IField* copy() const override;
	void undo_move() override;
private:
	std::map<Point, Symbol> board_;
	std::vector<Point> moves_; 
	std::vector<int> cnt_changes_;
};
