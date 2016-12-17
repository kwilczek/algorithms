#ifndef insertion_h
#define insertion_h

#include "sorter.h"

class InsertionSort : public Sorter
{
	public:
		void sort( std::vector<int>& sequence );
};

#endif
