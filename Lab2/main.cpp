#include <iostream>
#include "lab2.h"

int main()
{
	double a, b, c, x;

	std::cin >> a >> b >> c;

	Quadratic_equation::Quadratic_equation_ Q;

	Q.a = a;
	Q.b = b;
	Q.c = c;

	Quadratic_equation Quadratic_equation1(Q);
	Quadratic_equation Quadratic_equation2;
	Quadratic_equation Quadratic_equation3(Quadratic_equation1);

	std::cin >> x;

	Quadratic_equation1.Calculate_value_at_a_given_point(x);
	std::cout << "\n";

	Quadratic_equation1.Finding_the_number_of_roots();
	std::cout << "\n";

	Quadratic_equation1.Finding_roots();
	std::cout << "\n";

	Quadratic_equation1.Finding_the_minimum_or_maximum();
	std::cout << "\n";

	Quadratic_equation1.print();
	std::cout << "\n";

	Quadratic_equation1.~Quadratic_equation();
	std::cout << "\n";

	Quadratic_equation2.Calculate_value_at_a_given_point(x);
	std::cout << "\n";

	Quadratic_equation2.Finding_the_number_of_roots();
	std::cout << "\n";

	Quadratic_equation2.Finding_roots();
	std::cout << "\n";

	Quadratic_equation2.Finding_the_minimum_or_maximum();
	std::cout << "\n";

	Quadratic_equation2.print();
	std::cout << "\n";

	Quadratic_equation2.~Quadratic_equation();
	std::cout << "\n";

	Quadratic_equation3.Calculate_value_at_a_given_point(x);
	std::cout << "\n";

	Quadratic_equation3.Finding_the_number_of_roots();
	std::cout << "\n";

	Quadratic_equation3.Finding_roots();
	std::cout << "\n";

	Quadratic_equation3.Finding_the_minimum_or_maximum();
	std::cout << "\n";

	Quadratic_equation3.print();

	Quadratic_equation3.~Quadratic_equation();
	return 0;
}
