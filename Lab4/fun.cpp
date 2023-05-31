#include <iostream>
#include "lab4.h"

Rectangle::Rectangle()
{
	point.x = 1;
	point.y = 2;
	side_a = 3;
	side_b = 4;
	this -> size_ = sizeof(point.x) + sizeof(point.y) + sizeof(side_a) + sizeof(side_b);
	this -> name_ = "Rectangle";
}

void Rectangle::square()
{
	std::cout << "Rectangle square is " << side_a * side_b << std::endl;
}

void Rectangle::perimeter()
{
	std::cout << "Rectangle perimeter is " << (side_a + side_b) * 2 << std::endl;
}

void Rectangle::draw()
{
	std::cout << "x-coordinate is " << point.x << std::endl;
	std::cout << "y-coordinate is " << point.y << std::endl;
	std::cout << "rectangle side a is " << side_a << std::endl;
	std::cout << "rectangle side b is " << side_b << std::endl;
}

void Rectangle::initFromDialog()
{
	std::string n;
	int s = 0;

	std::cin >> point.x >> point.y >> side_a >> side_b;
	std::cin >> n;

	s = sizeof(point.x) + sizeof(point.y) + sizeof(side_a) + sizeof(side_b);
	this -> name_ = n;
	this -> size_ = s;
}

void Rectangle::classname()
{
	std::cout << this -> name_ << std::endl;
}

unsigned int Rectangle::size()
{
	return this -> size_;
}




Parallelogram::Parallelogram()
{
	point.x = 1;
	point.y = 2;
	side_a = 3;
	side_b = 4;
	height = 5;
	this -> size_ = sizeof(point.x) + sizeof(point.y) + sizeof(side_a) + sizeof(side_b) + sizeof(height);
	this -> name_ = "Parallelogram";
}

void Parallelogram::square()
{
	std::cout << "Parallelogram square is " << side_a * height << std::endl;
}

void Parallelogram::perimeter()
{
	std::cout << "Parallelogram perimeter is " << (side_a + side_b) * 2 << std::endl;
}

void Parallelogram::draw()
{
	std::cout << "x-coordinate is " << point.x << std::endl;
	std::cout << "y-coordinate is " << point.y << std::endl;
	std::cout << "parallelogram side a is " << side_a << std::endl;
	std::cout << "parallelogram side b is " << side_b << std::endl;
	std::cout << "parallelogram height is " << height << std::endl;
}

void Parallelogram::initFromDialog()
{
	std::string n;
	int s = 0;

	std::cin >> point.x >> point.y >> side_a >> side_b >> height;
	std::cin >> n;

	s = sizeof(point.x) + sizeof(point.y) + sizeof(side_a) + sizeof(side_b);
	this -> name_ = n;
	this -> size_ = s;
}

void Parallelogram::classname()
{
	std::cout << this -> name_ << std::endl;
}

unsigned int Parallelogram::size()
{
	return this -> size_;
}

