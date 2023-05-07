#include "lab1.h"
#include <cmath>
#include <iostream>

//Task 1
void integer_part_of_number(double *first_number)
{
	double integer;

	std::modf(*first_number, &integer);
	*first_number = integer;
}

void integer_part_of_number_(double &second_number)
{
	double integer;

	std::modf(second_number, &integer);
	second_number = integer;
}

//Task 2
void swap_number_sign(double *number_first)
{
	*number_first *= -1;
}

void swap_number_sign_(double &number_first)
{
	number_first *= -1;
}

//Task 3
Circle::Circle(double radius, Point point)
{
	P.x = point.x;
	P.y = point.y;
	this -> radius = radius;
}

void Circle::move_ref(Point *point)
{
	P.x += point -> x;
	P.y += point -> y;
}

void Circle::move_ref_(Point &point)
{
	P.x += point.x;
	P.y += point.y;
}

void Circle::print()
{
	std::cout << P.x << " " << P.y << " " << this -> radius <<  "\n";
}

//Task 4

void input(Matrix* matrix)
{
	double digit1, digit2, digit3;
	for (int i = 0; i < 3; i ++)
	{
		std::cin >> digit1 >> digit2 >> digit3;
		matrix -> data1[i] = digit1;
		matrix -> data2[i] = digit2;
		matrix -> data3[i] = digit3;
	}
}

void output(Matrix* matrix)
{
	for (int i = 0; i < 3; i ++)
	{
		std::cout << matrix -> data1[i] << " " << matrix -> data2[i] << " " << matrix -> data3[i] << "\n";
	}
}

void multiplication(Matrix *matrix, double *digit_for_multiplication)
{
	for (int i = 0; i < 3; i ++)
	{
		matrix -> data1[i] = matrix -> data1[i] * *digit_for_multiplication;
		matrix -> data2[i] = matrix -> data2[i] * *digit_for_multiplication;
		matrix -> data3[i] = matrix -> data3[i] * *digit_for_multiplication;
	}
}

void multiplication_(Matrix &matrix, double &digit_for_multiplication)
{
	for (int i = 0; i < 3; i ++)
	{
		matrix.data1[i] = matrix.data1[i] * digit_for_multiplication;
		matrix.data2[i] = matrix.data2[i] * digit_for_multiplication;
		matrix.data3[i] = matrix.data3[i] * digit_for_multiplication;
	}
}
