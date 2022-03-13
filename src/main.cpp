#include "model/model.hpp"
#include "game/game.hpp"
#include<bits/stdc++.h>


#include <iostream>

signed main() {

	for (int i = 0; i < 100; ++i) {

		RectangleField f(3, 3);
		f.add_figures(ClassicFigures::straight<3>());

		BasicHumanPlayer hp;
		BasicAIPlayer aip;

		Judge j(&f, {&hp, &aip}, {Symbol::Cross, Symbol::Zero});
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
