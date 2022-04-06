#include "model/basics/point.hpp"
#include "model/basics/classic_figures.hpp"

#include "model/fields/rectangle_field.hpp"

#include "model/players/human_player.hpp"
#include "model/players/random_ai_player.hpp"

#include "interface/game.hpp"
#include "interface/console/console_graphics.hpp"

#include <bits/stdc++.h>
#include <iostream>


int main() {

	std::cout << "type \"h\", or \"H\", if you want to play with a friend, or anything else, if you want to play with AI" << std::endl;
	std::string s = "no";
	std::cin >> s;

	RectangleField field(5, 5);
	field.addFigures(ClassicFigures::straight(4));

	ConsoleGraphics output;
	RandomAIPlayer raip;

	HumanPlayer hp;
	hp.setMoveInput(output.getInputer());

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
