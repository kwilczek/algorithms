#ifndef selection_h
#define selection_h

#include "sorter.h"

class SelectionSort : public Sorter
{
	public:
		void sort( std::vector<int>& sequence );
};

#endif
