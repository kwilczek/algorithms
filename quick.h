#ifndef quick_h
#define quick_h

#include "sorter.h"

class QuickSort : public Sorter
{
	public:
		std::vector<int>::iterator partition( std::vector<int>& sequence,
				std::vector<int>::iterator left_bound,
				std::vector<int>::iterator right_bound );

		void quicksort( std::vector<int>& sequence,
				std::vector<int>::iterator left_bound,
				std::vector<int>::iterator right_bound );
		
		void sort( std::vector<int>& sequence );
};

#endif
