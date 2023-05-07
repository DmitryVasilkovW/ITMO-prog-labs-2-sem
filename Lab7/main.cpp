#include "CircularBuffer.h"

using namespace std;

namespace Buffer
{
	template<typename T>
	void print(CircularBuffer<T> &B)
	{
		for (int i = 0; i < B.getcap(); i++)
		{
			std::cout << B[i] << " ";
		}
		std::cout << std::endl;
	}
}


int main()
{
	CircularBuffer<int> buffer(4);

	buffer.push_front(1);
	buffer.push_back(2);
	buffer.push_front(3);
	buffer.push_front(3);

	Buffer::print(buffer);

	buffer.pop_back();

	Buffer::print(buffer);

	buffer.pop_front();

	Buffer::print(buffer);

	buffer.push_front(1);
	buffer.push_back(7);

	Buffer::print(buffer);

	int a = buffer.first();
	int b = buffer.last();

	cout << a << " " << b << endl;

	for (auto it = buffer.begin(); it != buffer.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	buffer.resize(5);

	buffer.push_front(5);

	Buffer::print(buffer);

	return 0;
}
