#pragma once

#include <math.h>
#include <vector>

class Points
{
public:
	float x, y;
	int numberPoints = 360;
	std::vector<Points> ps;

public:
	Points();
	Points(float x, float y);
	Points getPointLocation(float,float);
	void pixel(float x, float y);
};

