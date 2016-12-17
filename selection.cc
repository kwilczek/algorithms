#include <iostream>
#include <vector>

#include "selection.h"

void SelectionSort::sort( std::vector<int>& sequence )
{
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;
	std::vector<int>::iterator min;
	// If inner loop sorts all elements, then last will be
	// sorted too.
	for( it = sequence.begin(); it != sequence.end() - 1; it++ )
	{
		min = it;
		for( it2 = it + 1; it2 != sequence.end(); it2++ )
		{
			if( *it2 < *min )
				min = it2;
		}
		std::swap( *it, *min );
	}
	std::cout << "using selection" << std::endl;
}
