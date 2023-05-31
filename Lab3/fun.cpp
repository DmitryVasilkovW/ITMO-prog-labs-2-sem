#include "lab3.h"
#include <iostream>


Square::Square(Square_ &sq)
{
	square.point.x = sq.point.x;
	square.point.y = sq.point.y;
	square.side_of_a_square = sq.side_of_a_square;
	square.angle_about_the_x_axis = sq.angle_about_the_x_axis;
}

bool Square::operator == (const Square& other)
{
	if (square.side_of_a_square == other.square.side_of_a_square)
	{
		return true;
	}

	else
	{
		return false;
	}
}

bool Square::operator != (const Square& other)
{
	if (square.side_of_a_square != other.square.side_of_a_square)
	{
		return true;
	}

	else
	{
		return false;
	}
}

bool Square::operator < (const Square& other)
{
	if (square.side_of_a_square < other.square.side_of_a_square)
	{
		return true;
	}

	else
	{
		return false;
	}
}

bool Square::operator > (const Square& other)
{
	if (square.side_of_a_square > other.square.side_of_a_square)
	{
		return true;
	}

	else
	{
		return false;
	}
}

Square Square::operator * (int digit)
{
	square.side_of_a_square *= digit;
}

Square Square::operator + (Point &s)
{
	square.point.x + s.x;
	square.point.y + s.y;
}

void Square::print()
{
	std::cout << "The x-coordinate of the vertex of the square is " << " " << square.point.x << " " << "The y-coordinate of the vertex of the square is " << " " << square.point.y << "\n";
	std::cout << "side of a square is " << square.side_of_a_square << "\n";
	std::cout << "angle about the x axis is " << square.angle_about_the_x_axis << "\n";
}





Array_of_integers::Array_of_integers(int size)
{
	array.size = size;
}

Array_of_integers::Array_of_integers(int size, int arr[])
{
	array.size = size;

	for (int i = 0; i < size; i++)
	{
		array.arr[i] = arr[i];
	}
}

void Array_of_integers::create_arr()
{
	for (int i = 0; i < array.size; i++)
	{
		int val;
		std::cin >> val;
		array.arr[i] = val;
	}
}

void Array_of_integers::print()
{
	for (int i = 0; i < array.size; i++)
	{
		std::cout << array.arr[i] << " ";
	}
}

bool Array_of_integers::operator == (const Array_of_integers& other)
{
	if(array.size != other.array.size)
	{
		return false;
	}

	else
	{
		for(int i = 0; i < array.size; i++)
		{
			if (array.arr[i] != other.array.arr[i])
			{
				return false;
			}
		}
	}
	return true;
}

bool Array_of_integers::operator != (const Array_of_integers& other)
{
	if(array.size != other.array.size)
	{
		return true;
	}

	else
	{
		for(int i = 0; i < array.size; i++)
		{
			if (array.arr[i] != other.array.arr[i])
			{
				return true;
			}
		}
	}
	return false;
}

bool Array_of_integers::operator < (const Array_of_integers& other)
{
	if(array.size < other.array.size)
	{
		return true;
	}

	else
	{
		return false;
	}
}

bool Array_of_integers::operator > (const Array_of_integers& other)
{
	if(array.size > other.array.size)
	{
		return true;
	}

	else
	{
		return false;
	}
}

Array_of_integers Array_of_integers::operator + (const Array_of_integers& other)
{
	int* mas = new int[other.array.size + array.size];

	for (int i = 0; i < array.size; i++)
	{
		mas[i] = array.arr[i];
	}

	for (int i = array.size; i < other.array.size + array.size; i++)
	{
		mas[i] = other.array.arr[i - array.size];
	}

	Array_of_integers res(other.array.size + array.size, mas);

	return res;
}

