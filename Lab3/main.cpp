#include <iostream>
#include "lab3.h"

int main()
{
	double x, y, side_of_a_square, angle_about_the_x_axis;

	Square::Point point;

	point.x = x;
	point.y = y;

	std::cin >> x >> y >> side_of_a_square >> angle_about_the_x_axis;

	Square::Square_ square1;

	square1.point.x = x;
	square1.point.y = y;
	square1.angle_about_the_x_axis = angle_about_the_x_axis;
	square1.side_of_a_square = side_of_a_square;

	Square::Square_ square2;

	std::cin >> x >> y >> side_of_a_square >> angle_about_the_x_axis;

	square2.point.x = x;
	square2.point.y = y;
	square2.angle_about_the_x_axis = angle_about_the_x_axis;
	square2.side_of_a_square = side_of_a_square;

	Square Square1(square1);
	Square Square2(square2);

	Square1.print();
	std::cout << "\n";
	Square2.print();

	std::cout << "\n";

	Square1 + point;
	Square1.print();

	std::cout << "\n";
	Square2 * 2;
	Square2.print();

	if (Square1 == Square2)
	{
		std::cout << "the squares are equal" << "\n";
	}

	if (Square1 != Square2)
	{
		std::cout << "squares are not equal" << "\n";
	}

	if (Square1 < Square2)
	{
		std::cout << "square one is greater than square two" << "\n";
	}

	if (Square1 > Square2)
	{
		std::cout << "square two is greater than square one" << "\n";
	}

	Square1.~Square();
	Square2.~Square();

	int size1, size2;

	std::cin >> size1 >> size2;

	Array_of_integers Array1(size1);
	Array_of_integers Array2(size2);

	Array1.create_arr();
	Array1.print();
	std::cout << "\n";

	Array2.create_arr();
	Array2.print();
	std::cout << "\n";

	Array_of_integers Array3 = Array1 + Array2;
	Array3.print();
	std::cout << "\n";

	if (Array3 != Array2)
	{
		std::cout << "arrays are not equal" << "\n";
	}

	if (Array1 == Array2)
	{
		std::cout << "arrays are equal" << "\n";
	}

	if (Array1 < Array2)
	{
		std::cout << "array two is greater than array one" << "\n";
	}

	if (Array1 > Array2)
	{
		std::cout << "array one is greater than array two" << "\n";
	}

	Array1.~Array_of_integers();
	Array2.~Array_of_integers();
	Array3.~Array_of_integers();

	return 0;
}
