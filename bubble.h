#ifndef bubble_h
#define bubble_h

#include "sorter.h"

class BubbleSort : public Sorter
{
	public:
		void sort( std::vector<int>& sequence );
};

#endif
