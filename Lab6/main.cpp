#include <iostream>
#include <vector>
#include "lab6.h"


template<class T>
bool is_not_Null(const T& t)
{
	if (t.get_a() != 0 || t.get_b() != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
};

template<typename T>
class Point
{
private:
	T x;
	T y;
public:
	Point(const T& a, const T& b)
	{
		x = a;
		y = b;
	}

	T get_a() const
	{
		return x;
	}

	T get_b() const
	{
		return y;
	}

};

template<typename T>
class Pair
{
private:
	T a;
	T b;
public:
	Pair(T a, T b)
	{
		this -> a = a;
		this -> b = b;
	}

	T get_a() const
	{
		return a;
	}

	T get_b() const
	{
		return b;
	}
};


int main()
{
	std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
	int val = 6;
	std::vector<Pair<int>> pairs = {Pair<int>(1, 2), Pair<int>(3, 4), Pair<int>(5, 6), Pair<int>(7, 8), Pair<int>(9, 10)};
	std::vector<Point<int>> points = { Point(1, 2), Point(3, 4), Point(5, 6), Point(7, 8)};

	if (all_off(pairs.begin(), pairs.end(), is_not_Null<Pair<int>>))
	{
		std::cout << "True" << std::endl;
	}
	else
	{
		std::cout << "False" << std::endl;
	}

	if (one_off(points.begin(), points.end(), is_not_Null<Point<int>>))
	{
		std::cout << "True" << std::endl;
	}
	else
	{
		std::cout << "False" << std::endl;
	}

	auto result = find_backwardd(arr.begin(), arr.end(), val);

	std::cout << result;

	return 0;
}
