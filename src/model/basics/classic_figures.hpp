#pragma once

#include "point.hpp"
#include "figure.hpp"

#include <vector>


struct ClassicFigures {
    static inline std::vector<Figure> straight(int n) {
        std::vector<Figure> res;
        for (int dir = 0; dir < 4; ++dir) {
            Figure f;
            Point p{0, 0};
            for (int i = 0; i < n; ++i) {
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
