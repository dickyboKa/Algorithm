#include <vector>
#include <iostream>

template <class ForwardIter>
void insertionSort(ForwardIter beg, ForwardIter end)
{
	auto r_end = std::make_reverse_iterator(beg);
 	++beg;
	for (; beg != end; ++beg)
	{
		int key = *beg;
		auto r_it = std::make_reverse_iterator(beg);
		for (; r_it != r_end; ++r_it)
		{
			if (*r_it > key)
			{
				*(r_it - 1) =  *r_it;
			}
			else
				break;
		}
		*(r_it - 1) = key;
	}
}

