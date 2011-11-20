#include <iostream>

#include "extension.h"

int main(int argc, char const* argv[])
{
	std::cout << "Loaded " << load_extensions() << " extensions!" <<
		std::endl;
	return 0;
}