#include <iostream>
#include "domain/artist.hpp"

int main()
{
	Artist artist(1.0, 2.0, 0.5, 0.2);

	std::cout << "Artist: (x=" << artist.getX() << ", y=" << artist.getY()
		<< ", vx=" << artist.getVX() << ", vy=" << artist.getVY() << ")" << std::endl;

	return 0;
}
