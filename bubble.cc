#include <iostream>
#include <vector>

#include "bubble.h"

void BubbleSort::sort( std::vector<int>& sequence )
{
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for( it = sequence.begin(); it != sequence.end() - 1; it++ )
	{
		for( it2 = sequence.end() - 1; it2 != it; it2-- )
		{
			if( *it2 < *it )
				std::swap( *it2, *it );
		}
	}
	std::cout << "using bubble" << std::endl;
}
