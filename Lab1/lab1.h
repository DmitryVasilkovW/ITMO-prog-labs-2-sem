#ifndef UNTITLED15_LAB1_H
#define UNTITLED15_LAB1_H
#include <vector>
//Task 1
void integer_part_of_number(double *first_number);

void integer_part_of_number_(double &second_number);

//Task 2
void swap_number_sign(double *number_first);

void swap_number_sign_(double &number_second);

//Task 3
class Circle
{

public:
	struct Point
	{
		double x;
		double y;
	};

	double radius;
	Point P;

	Circle (double, Point);

	void move_ref(Point *point);

	void move_ref_(Point &point);

	void print();

	~Circle() = default;
};

//Task 4
struct Matrix
{
	double data1[3];
	double data2[3];
	double data3[3];
};

void input(Matrix* matrix);

void output(Matrix* matrix);

void multiplication(Matrix *matrix, double *digit_for_multiplication);

void multiplication_(Matrix &matrix, double &digit_for_multiplication);
#endif
