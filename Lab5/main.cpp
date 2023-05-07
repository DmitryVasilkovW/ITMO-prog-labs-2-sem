#include <iostream>
#include "lab5.h"


int main()
{
	int a, b;
	double c, d;

	std::cin >> a >> b >> c >> d;

	std::cout << pow(a, b) << std::endl;
	std::cout << pow(c, d) << std::endl;

	Matrix<int, 10, 10> matrix;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			matrix(i, j) = i;
		}
	}

	try
	{
		for (int i = -11; i < 11; i++)
		{
			for (int j = -12; j < 10; j++)
			{
				std::cout << "The element at index (" << i << "," << j << ") is: " << matrix(i, j) << std::endl;
			}
		}
	}

	catch (const myexeption &exception)
	{
		std::cerr << exception.what() << std::endl;
	}

	return 0;
}
