#include "Judge.hpp"
#include <iostream>
#include "out_function.cpp"

Judge::Judge(IField* f, std::vector<IPlayer*> p, std::vector<Symbol> s)
		: field_(f), players_(p), symbols_(s) {}


IPlayer* Judge::run(const int try_limit) {

	Point last_move{INT_MIN, INT_MIN};
	for (int step = 0; ; ++step) {
		if (!(field_->has_move())) return nullptr;

		int who = step % players_.size();

		bool made = false;
		Point mv;
		int try_cnt = 0;

		out(field_->get_board(), last_move);
		
		while (!made && ++try_cnt <= try_limit) {
			mv = players_[who]->get_move(field_, symbols_[who]);
			made = field_->set_cell(mv, symbols_[who]);
			if (!made) {
				std::cerr << "somthing got wrong, try again" << std::endl;
			}
		}

		if (try_cnt > try_limit) {
			std::cerr << "some player can not make a move(((" << std::endl;
			return nullptr;
		}
		last_move = mv;
		if (field_->is_winning_at(mv, symbols_[who])) {
			out(field_->get_board(), last_move);
			return players_[who];
		}
	}
}