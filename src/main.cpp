#include "model/basics/point.hpp"
#include "model/basics/classic_figures.hpp"

#include "model/fields/rectangle_field.hpp"

#include "model/players/basic_human_player.hpp"
#include "model/players/random_ai_player.hpp"

#include "game/judge.hpp"

#include <bits/stdc++.h>
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
		std::cerr << cnt1 << " : " << draws << " : " << cnt2 << std::endl;
		delete f1;
	}
	std::cout << "result : " << cnt1 << " : " << draws << " : " << cnt2 << std::endl;
}



int main() {

	std::cout << "type \"h\", or \"H\", if you want to play, or type any other button, to see a combat." << std::endl;
	std::string s = "no";
	std::cin >> s;


	// std::cout << "this is infinite field. It will get bigger, as you play\n";
	
	// InfiniteField f;
	RectangleField f(5, 5);
	f.addFigures(ClassicFigures::straight<4>());
	
	RandomAIPlayer raip;
	// HeuristicAIPlayer haip;
	// FewMovesAIPlayer fmaip;
	BasicHumanPlayer bhp;

	IPlayer* p1;
	IPlayer* p2;

	if (s == "h" || s == "H") {
		p1 = &raip;
		p2 = &bhp;
	} else {
		p1 = &raip;
		p2 = &raip;
	}

	battle(&f, p1, p2, 10);

	return 0;
}
