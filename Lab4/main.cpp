#include <iostream>
#include "lab4.h"

int main()
{
	unsigned int size;

	Rectangle Rectangle;

	Rectangle.initFromDialog();
	Rectangle.perimeter();
	Rectangle.square();
	Rectangle.draw();
	Rectangle.classname();
	size = Rectangle.size();

	std::cout << size << std::endl;

	Rectangle.~Rectangle();

	Parallelogram Parallelogram;

	Parallelogram.initFromDialog();
	Parallelogram.perimeter();
	Parallelogram.square();
	Parallelogram.draw();
	Parallelogram.classname();
	size = Parallelogram.size();

	std::cout << size << std::endl;

	Parallelogram.~Parallelogram();
	return 0;
}
