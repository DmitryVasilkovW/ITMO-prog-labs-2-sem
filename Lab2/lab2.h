#ifndef UNTITLED1_LAB2_H
#define UNTITLED1_LAB2_H
#include <cmath>

class Quadratic_equation
{
	public:
		struct Quadratic_equation_
		{
			double a;
			double b;
			double c;
		};

		Quadratic_equation_ Quadratic_equation__;


	    Quadratic_equation(Quadratic_equation_ &quadratic_equation);

		Quadratic_equation();

		Quadratic_equation(const Quadratic_equation& quadratic_equation);


		void Calculate_value_at_a_given_point(double x);

		void Finding_the_number_of_roots();

		void Finding_roots();

		void Finding_the_minimum_or_maximum();

		void print();

		~Quadratic_equation() = default;
};
#endif
