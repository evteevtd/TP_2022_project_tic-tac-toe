#include "Judge.hpp"
#include <iostream>

Judge::Judge(IField* f, std::vector<IPlayer*> p, std::vector<Symbol> s)
		: field_(f), players_(p), symbols_(s) {}


IPlayer* Judge::run(const int try_limit) {
	for (int step = 0; ; ++step) {
		if (!(field_->has_move())) return nullptr;

		int who = step % players_.size();

		bool made = false;
		Point mv;
		int try_cnt = 0;
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

		if (field_->is_winning_at(mv, symbols_[who])) return players_[who];
	}
}