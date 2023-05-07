#ifndef UNTITLED4_LAB3_H
#define UNTITLED4_LAB3_H

class Square
{
public:
	struct Point
	{
		double x;
		double y;
	};

	struct Square_
	{
		Point point;
		double side_of_a_square;
		double angle_about_the_x_axis;
	};

	Square_ square;

	Square (Square_ &sq);

	bool operator == (const Square& other);

	bool operator != (const Square& other);

	bool operator < (const Square& other);

	bool operator > (const Square& other);

	Square operator * (int digit);

	Square operator + (Point &s);

	void print();

	~Square() = default;
};

class Array_of_integers
{
public:
	struct Array
	{
		int size;
		int* arr = new int [size];
	};

	Array array;

	Array_of_integers(int size);

	Array_of_integers(int size, int arr[]);

	void create_arr();

	void print();

	bool operator == (const Array_of_integers& other);

	bool operator != (const Array_of_integers& other);

	bool operator < (const Array_of_integers& other);

	bool operator > (const Array_of_integers& other);

	Array_of_integers operator + (const Array_of_integers& other);

	~Array_of_integers() = default;
};
#endif
