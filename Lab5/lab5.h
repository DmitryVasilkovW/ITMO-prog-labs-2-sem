#ifndef UNTITLED6_LAB5_H
#define UNTITLED6_LAB5_H

#include <string>
#include <cmath>
#include <stdexcept>

template<class Type>

Type pow(Type digit, Type degree)
{
	return std::pow(digit, degree);
}

class myexeption : public std::out_of_range
{
public:
	myexeption(std::string ex) : std::out_of_range(ex){}

};

template <typename T, int M, int N>
class Matrix
{
public:
	T data[M][N];

	T& operator() (int i, int j)
	{
		if (i > M || j > N || i < 0 || j < 0)
		{
			throw myexeption("Index out of range!");
		}
		return data[i][j];
	}
};

#endif //UNTITLED6_LAB5_H
