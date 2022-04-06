#include "model/basics/point.hpp"
#include "model/basics/classic_figures.hpp"

#include "model/fields/rectangle_field.hpp"

#include "model/players/human_player.hpp"
#include "model/players/random_ai_player.hpp"

#include "interface/game.hpp"
#include "interface/graphics/console_graphics.hpp"
#include "interface/move_input/console_move_input.hpp"

#include <bits/stdc++.h>
#include <iostream>


// void battle(const IField* f, IPlayer* p1, IPlayer* p2, int nums = 2) {
// 	int cnt1 = 0;
// 	int cnt2 = 0;
// 	int draws = 0;
// 	while (nums--) {
// 		IField* f1 = f->copy();
// 		Judge j;
// 		if (nums % 2 == 0) {
// 			j = Judge(f1, {p1, p2}, {Symbol::Cross, Symbol::Zero});
// 		} else {
// 			j = Judge(f1, {p2, p1}, {Symbol::Cross, Symbol::Zero});
// 		}
// 		auto winner = j.run();
// 		cnt1 += (winner == p1);
// 		cnt2 += (winner == p2);
// 		draws += (winner == nullptr);
// 		std::cerr << cnt1 << " : " << draws << " : " << cnt2 << std::endl;
// 		delete f1;
// 	}
// 	std::cout << "result : " << cnt1 << " : " << draws << " : " << cnt2 << std::endl;
// }


int main() {

	std::cout << "type \"h\", or \"H\", if you want to play with a friend, or anything else, if you want to play with AI" << std::endl;
	std::string s = "no";
	std::cin >> s;

	RectangleField field(5, 5);
	field.addFigures(ClassicFigures::straight(4));

	ConsoleGraphics output;
	ConsoleMoveInput input;
	
	RandomAIPlayer raip;

	HumanPlayer hp;
	hp.setMoveInput(&input);

	IPlayer* p1 = &hp;
	IPlayer* p2;

	if (s == "h" || s == "H") {
		p2 = &hp;
	} else {
		p2 = &raip;
	}

	Game game(&field, {p1, p2}, {Symbol::Cross, Symbol::Zero}, &output);
	game.run();

	return 0;
}
