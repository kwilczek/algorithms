#include <iostream>
#include <vector>

#include "quick.h"
using namespace std;

// This is the partition function.
// Its purpose is to determine the pivot iterator
// for the sequence.
vector<int>::iterator QuickSort::partition(
		vector<int>& sequence,
		vector<int>::iterator left_bound,
		vector<int>::iterator right_bound )
{
	int last = *right_bound;
	vector<int>::iterator pivot;
	vector<int>::iterator j;
	pivot = left_bound;
	for( j = left_bound; j < right_bound; j++ )
	{
		if( *j <= last )
		{
			swap( *j, *pivot );
			pivot = pivot + 1;
		}
	}
	swap( *pivot, *right_bound );
	return pivot;
}

void QuickSort::quicksort( vector<int>& sequence,
		vector<int>::iterator left_bound,
		vector<int>::iterator right_bound )
{
	// This is ok.
	// If previous pivot element will be the first element
	// (i.e. in reverse sorted array), the subsequent recursion
	// will have zero length vector on the left side.
	// quicktsort( sequence, 1, 0 )
	// The if condition will fail for subvectors smaller than 2.
	if( left_bound < right_bound )
	{
		vector<int>::iterator pivot = this->partition( sequence, left_bound, right_bound );
		quicksort( sequence, left_bound, pivot - 1 );
		quicksort( sequence, pivot + 1, right_bound );
	}
}

// We nedd to initialize the first quicksort call with
// the original vector boundaires.
void QuickSort::sort( vector<int>& sequence )
{
	vector<int>::iterator left_bound = sequence.begin();
	vector<int>::iterator right_bound = sequence.end() - 1;
	quicksort( sequence, left_bound, right_bound );
}

