#include <iostream>
#include "lab1.h"

int main()
{
	//Task 1
	double first_number, second_number;

	std::cin >> first_number >> second_number;

	integer_part_of_number(&first_number);
	integer_part_of_number_(second_number);

	std::cout << "Task 1" << "\n";
	std::cout << first_number << " " << second_number << "\n";

	//Task 2
	double number_first, number_second;

	std::cin >> number_first >> number_second;

	swap_number_sign(&number_first);
	swap_number_sign_(number_second);

	std::cout << "Task 2" << "\n";
	std::cout << number_first << " " << number_second << "\n";

	//Task 3
	std::cout << "Task 3\n";

	double x1, y1, radius, move_x, move_y, move_x1, move_y1;

	std::cin >> x1 >> y1 >> radius;
	std::cin >> move_x >> move_y >> move_x1 >> move_y1;

	Circle::Point point1;
	Circle::Point point2;
	Circle::Point point3;

	point1.x = x1;
	point1.y = y1;
	point2.x = move_x;
	point2.y = move_y;
	point3.x = move_x1;
	point3.y = move_y1;


	Circle Circle1(radius, point1);
	Circle Circle2(radius, point1);


	Circle1.move_ref(&point2);
	Circle2.move_ref_(point3);

	Circle1.print();
	Circle2.print();

	Circle1.~Circle();
	Circle2.~Circle();

	//Task 4;
	std::cout << "Task 4\n";

	double digit_for_multiplication;

	std::cin >> digit_for_multiplication;

	Matrix matrix1;
	Matrix matrix2;

	input(&matrix1);
	multiplication(&matrix1, &digit_for_multiplication);
	output(&matrix1);

	std::cout << "\n";

	input(&matrix2);
	multiplication_(matrix2, digit_for_multiplication);
	output(&matrix2);

	return 0;
}

