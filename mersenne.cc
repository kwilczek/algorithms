#include <iostream>
#include <random>
#include <vector>
// http://www.cplusplus.com/reference/algorithm/reverse/
// http://www.cplusplus.com/reference/algorithm/swap/
#include <algorithm>
#include "mersenne.h"

using namespace std;

// I took the example of creating pseudo-random
// numbers from the specific range from the site:
// http://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution 

// Filling the sequence with random numbers.
void Mersenne::init_seq_rand( vector<int>& sequence, int min, int max )
{
	random_device rand_dev;
	mt19937 mersenne_twister( rand_dev() );
	uniform_int_distribution<> uniform_dist( min, max );

	vector<int>::iterator it;
	for( it = sequence.begin(); it != sequence.end(); it++ )
	{
		*it = uniform_dist( mersenne_twister );
	}
}
