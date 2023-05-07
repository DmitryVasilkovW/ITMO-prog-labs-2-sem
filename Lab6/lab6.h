#ifndef UNTITLED7_LAB6_H
#define UNTITLED7_LAB6_H


template <typename InputIt, typename Predicate>
bool all_off(InputIt first, InputIt last, Predicate pred)
{
	bool flag = true;
	for (auto it = first; it != last; it++)
	{
		if(!pred(*it))
		{
			flag = false;
			break;
		}
	}
	return flag;
}


template <typename InputIt, typename Predicate>
bool one_off(InputIt first, InputIt last, Predicate pred)
{
	int count = 0;
	for (auto it = first; it != last; it++)
	{
		if (pred(*it))
		{
			++count;
			if (count > 1)
			{
				return false;
			}
		}
	}
	return true;
}

template <typename InputIt, typename T>
auto find_backwardd(InputIt first, InputIt last, T& value)
{
	for (auto it = last; it != first; it--)
	{
		if (*it == value)
		{
			return *it;
		}
	}
}


#endif
