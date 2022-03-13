#include "Basics.hpp"

Figure Figure::rotated(Point center) const {
	Figure copy = *this;
	for (Point& p : copy.points) {
		p = (p - center).rotated() + center;
	}
	return copy;
}

Figure Figure::shifted(int index, Point center) const {
	Point shift = center - points[index];
	Figure copy = *this;
	for (Point& p : copy.points) {
		p = p + shift;
	}
	return copy;
}
