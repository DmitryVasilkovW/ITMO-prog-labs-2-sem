#include "lab2.h"
#include <cmath>
#include <iostream>

Quadratic_equation::Quadratic_equation(Quadratic_equation_ &Quadratic_equation)
{
	Quadratic_equation__.a = Quadratic_equation.a;
	Quadratic_equation__.b = Quadratic_equation.b;
	Quadratic_equation__.c = Quadratic_equation.c;
}

Quadratic_equation::Quadratic_equation()
{
	Quadratic_equation__.a = 5;
	Quadratic_equation__.b = 5;
	Quadratic_equation__.c = 5;
}

Quadratic_equation::Quadratic_equation(const Quadratic_equation &quadratic_equation)
{
	Quadratic_equation__.a = quadratic_equation.Quadratic_equation__.a;
	Quadratic_equation__.b = quadratic_equation.Quadratic_equation__.b;
	Quadratic_equation__.c = quadratic_equation.Quadratic_equation__.c;
}

void Quadratic_equation::Calculate_value_at_a_given_point(double x)
{
	std::cout << pow(Quadratic_equation__.a, 2) * x + Quadratic_equation__.b * x + Quadratic_equation__.c;
}

void Quadratic_equation::Finding_the_number_of_roots()
{
	double D = (pow(Quadratic_equation__.b, 2) - (4 * Quadratic_equation__.a * Quadratic_equation__.c));

	if (D > 0)
	{
		std::cout << "A quadratic equation has 2 roots";
	}

	else if (D < 0)
	{
		std::cout << "A quadratic equation has no roots";
	}

	else if (D == 0)
	{
		std::cout << "A quadratic equation has 1 root";
	}
}

void Quadratic_equation::Finding_roots()
{
	double x1 = (-Quadratic_equation__.b - sqrt(pow(Quadratic_equation__.b, 2) - (4 * Quadratic_equation__.a * Quadratic_equation__.c))) / 2;
	double x2 = (-Quadratic_equation__.b + sqrt(pow(Quadratic_equation__.b, 2) - (4 * Quadratic_equation__.a * Quadratic_equation__.c))) / 2;

	std::cout << x1 << " " <<  x2;
}

void Quadratic_equation::Finding_the_minimum_or_maximum()
{
	if (Quadratic_equation__.a > 0)
	{
		double x = ((- Quadratic_equation__.b) / (2 * Quadratic_equation__.a));
		double min = pow(Quadratic_equation__.a, 2) * x + Quadratic_equation__.b * x + Quadratic_equation__.c;

		std::cout << "the minimum of the function is " << min;
	}

	else
	{
		double x = ((- Quadratic_equation__.b) / (2 * Quadratic_equation__.a));
		double max = pow(Quadratic_equation__.a, 2) * x + Quadratic_equation__.b * x + Quadratic_equation__.c;

		std::cout << "the minimum of the function is " << max;
	}
}

void Quadratic_equation::print()
{
	std::cout << Quadratic_equation__.a << "x^2" << " + " << Quadratic_equation__.b << "x" << " + " << Quadratic_equation__.c;
}

