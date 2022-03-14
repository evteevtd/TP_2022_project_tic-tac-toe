#pragma once

#include <vector>
#include "../model/model.hpp"

class Judge {
public:
	Judge() {}
	Judge(IField*, std::vector<IPlayer*>, std::vector<Symbol>);
	IPlayer* run(const int try_limit = 10);

private:
	IField* field_;
	std::vector<IPlayer*> players_;
	std::vector<Symbol> symbols_;
};
