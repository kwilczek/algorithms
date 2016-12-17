#include <iostream>
#include <vector>

#include "insertion.h"

void InsertionSort::sort( std::vector<int>& sequence )
{
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;
	int temp;
	for( it = sequence.begin(); it != sequence.end(); it++ )
	{
		temp = *it;
		for( it2 = it; it2 > sequence.begin() && temp < *( it2 - 1 ); it2-- )
		{
			*it2 = *( it2 - 1 );
		}
		*it2 = temp;
	}
	std::cout << "using insertion" << std::endl;
}
