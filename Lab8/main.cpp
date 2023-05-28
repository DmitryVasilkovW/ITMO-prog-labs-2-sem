#include "Cube.h"

int main()
{
	std::string filename = "Cubik.txt";
	Cube cube;
	cube.LoadFromFile(filename);

	cube.Mixing();

	cube.cubeSolve();

	int t = 0;
	for (auto i : cube.mass)
	{
		if(t % 3 == 0) std::cout << "\n";
		std::cout << i << " ";
		t++;
	}

	std::cout << "\n";


	for (auto i : cube.mass)
	{
		cube.printt();
	}


	return 0;
}
