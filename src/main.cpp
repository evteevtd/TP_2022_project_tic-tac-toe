#include "model/model.hpp"
#include "game/game.hpp"
#include<bits/stdc++.h>

#include <iostream>


void battle(const IField* f, IPlayer* p1, IPlayer* p2, int nums = 2) {
	int cnt1 = 0;
	int cnt2 = 0;
	int draws = 0;
	while (nums--) {
		IField* f1 = f->copy();
		Judge j;
		if (nums % 2 == 0) {
			j = Judge(f1, {p1, p2}, {Symbol::Cross, Symbol::Zero});
		} else {
			j = Judge(f1, {p2, p1}, {Symbol::Cross, Symbol::Zero});
		}
		auto winner = j.run();
		cnt1 += (winner == p1);
		cnt2 += (winner == p2);
		draws += (winner == nullptr);
		out(f1->get_board());
		std::cerr << cnt1 << " : " << draws << " : " << cnt2 << std::endl;
		delete f1;
	}
	std::cout << "result : " << cnt1 << " : " << draws << " : " << cnt2 << std::endl;
}



signed main() {

	InfiniteField f;
	std::cout << "this is infinite field. It will get bigger, as you play\n";
	// RectangleField f(5, 5);
	f.add_figures(ClassicFigures::straight<5>());

	HeuristicAIPlayer p1;
	HeuristicAIPlayer p2;
	// BasicHumanPlayer p2;

	battle(&f, &p1, &p2);

	return 0;
}
