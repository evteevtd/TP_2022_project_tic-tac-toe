#include "model/model.hpp"
#include "game/game.hpp"
#include<bits/stdc++.h>


#include <iostream>

signed main() {

	for (int i = 0; i < 100; ++i) {

		// RectangleField f(60, 101);
		// f.add_figures(ClassicFigures::straight<4>());
		InfiniteField f;
		f.add_figures(ClassicFigures::straight<5>());

		BasicHumanPlayer hp;
		HeuristicAIPlayer aip;

		Judge j;
		if (i % 2 == 0) {
			j = Judge(&f, {&hp, &aip}, {Symbol::Cross, Symbol::Zero});
		} else {
			j = Judge(&f, {&aip, &hp}, {Symbol::Cross, Symbol::Zero});
		}

		auto winner = j.run();

		std::cout << i << ' ';

		if (winner == &hp) {
			std::cout << "Human wins" << std::endl;
		} else if (winner == &aip) {
			std::cout << "AI wins" << std::endl;
		} else {
			std::cout << "draw" << std::endl;
		}
	}





	return 0;
}
