#pragma once

#include "point.hpp"
#include "figure.hpp"

#include <vector>


struct ClassicFigures {
    template <size_t N>
    static std::vector<Figure> straight() {
        std::vector<Figure> res;
        for (int dir = 0; dir < 4; ++dir) {
            Figure f;
            Point p{0, 0};
            for (int i = 0; i < N; ++i) {
                f.points.push_back(p);
                p = p + Point{dx[dir], dy[dir]};
            }
            res.push_back(f);
        }
        return res;
    }

private:
    inline static const std::vector<int> dx = {0, 1, 1, 1, 0, -1, -1, -1};
    inline static const std::vector<int> dy = {1, 1, 0, -1, -1, -1, 0, 1};
};
