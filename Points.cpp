#include "Points.h"

Points::Points(){}

Points::Points(float _x, float _y)
	:x(_x), y(_y){}

Points Points::getPointLocation(float x, float y)
{
	this->x = x;
	this->y = y;

	return Points{ this->x, this->y };
}

void Points::pixel(float x, float y)
{
	ps.emplace_back(Points{x, y});
}