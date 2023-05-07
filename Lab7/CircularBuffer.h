#ifndef UNTITLED3_CircularBuffer_H
#define UNTITLED3_CircularBuffer_H
#include <iostream>

template <class T>
class CircularBuffer
{
private:
	T *BufferElements = nullptr;
	size_t size;
	size_t capacity;
	size_t Begin;
	size_t End;
public:

	explicit CircularBuffer(size_t Capacity)
	{
		capacity = Capacity;
		BufferElements = new T [Capacity];
		size = 0;
		Begin = 0;
		End = 0;
	}

	CircularBuffer(const CircularBuffer &Buffer)
	{
		capacity = Buffer.capacity;
		BufferElements = new T [capacity];
		size = Buffer.size;
		Begin = Buffer.Begin;
		End = 0;

		for (size_t i = 0; i < size; i++)
		{
			*BufferElements[i] = Buffer.BufferElements[i];
		}
	}

	class Iterator : public std::iterator<std::random_access_iterator_tag, T>
	{
	private:
		T* it;
	public:
		Iterator (T* tmp)
		{
			it = tmp;
		}

		T& operator ++ (int)
		{
			return *it++;
		}

		bool operator != (const Iterator& other)
		{
			return this -> it != other.it;
		}

		T& operator * ()
		{
			return *it;
		}

	};
	
	T &operator[](size_t index) const
	{
		return BufferElements[index % capacity];
	}

	void push_front(T x)
	{
		if (capacity < size)
		{
			throw std::logic_error("Error: Buffer is overflow");
		}

		if (size == 0)
		{
			End = capacity - 1;
		}

		BufferElements[Begin] = x;
		Begin++;
		size++;
	}

	void push_back(const T x)
	{
		if (capacity < size)
		{
			throw std::logic_error("Error: Buffer is overflow");
		}

		if (size == 0)
		{
			End = capacity - 1;
		}

		BufferElements[End] = x;
		size++;
		End--;
	}


	void pop_front()
	{
		if (size > 0)
		{
			Begin = (Begin - size) % capacity;
			BufferElements[Begin] = 0;
			size--;
			Begin = (Begin - capacity) % capacity;
		}
	}


	void pop_back()
	{
		End = (End + 1) % capacity;
		BufferElements[End] = 0;
		size--;
	}

	void resize(size_t newCapacity)
	{
		T *tmp = new T [newCapacity];
		for (size_t i = 0; i < size; i++)
		{
			tmp[i] = BufferElements[i];
		}

		delete [] BufferElements;
		BufferElements = tmp;
		capacity = newCapacity;
		Begin = size;
		End = 0;
	}

	Iterator begin() const
	{
		return BufferElements;
	}

	Iterator end() const
	{
		return BufferElements + capacity;
	}

	T first() const
	{
		return BufferElements[Begin - 1 % capacity];
	}

	T last() const
	{
		return BufferElements[End + 1 % capacity];
	}

	T getcap()
	{
		return capacity;
	}

	~CircularBuffer()
	{
		delete [] BufferElements;
	}
};
#endif
