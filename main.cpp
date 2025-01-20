#include <iostream>

#include "Screen.h"
#include "Points.h"

int main(int argc, char* argv[])
{
	Points points(300, 300);
	Screen screen(points);

	while (true)
	{
		screen.show();
		screen.input();
	}

	return 0;
}
