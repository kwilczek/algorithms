#ifndef merge_h
#define merge_h

#include "sorter.h"

class MergeSort : public Sorter
{
	public:
		void sort( std::vector<int>& sequence );
	private:
		void sort( std::vector<int>& sequence,
				std::vector<int>::iterator left,
				std::vector<int>::iterator right );
		void merge( std::vector<int>& sequence,
				std::vector<int>::iterator left,
				std::vector<int>::iterator middle,
				std::vector<int>::iterator right );
};

#endif
