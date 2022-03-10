#include "model.hpp"

Figure::Figure rotated(Point center = Point()) const {
	Figure copy = *this;
	for (Point& p : copy.points) {
		p = (p - center).rotated() + center;
	}
	return copy;
}

Figure::Figure shifted(int index = 0, Point center = Point()) const {
	Point shift = center - points[index];
	Figure copy = *this;
	for (Point& p : copy.points) {
		p = p + shift;
	}
	return copy;
}
