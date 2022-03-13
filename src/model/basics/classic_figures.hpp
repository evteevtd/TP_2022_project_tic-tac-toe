#pragma once

#include "Basics.hpp"
#include <vector>

namespace AllDirections {
	std::vector<int> dx = {0, 1, 1, 1, 0, -1, -1, -1};
	std::vector<int> dy = {1, 1, 0, -1, -1, -1, 0, 1};
}

namespace ClassicFigures {
	template <size_t N>
	std::vector<Figure> straight() {
		std::vector<Figure> res;
		for (int dir = 0; dir < 4; ++dir) {
			Figure f;
			Point p{0, 0};
			for (int i = 0; i < N; ++i) {
				f.points.push_back(p);
				p = p + Point{AllDirections::dx[dir], AllDirections::dy[dir]};
			}
			res.push_back(f);
		}
		return res;
	}
}



