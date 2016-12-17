#include <iostream>
#include <vector>

#include "merge.h"
using namespace std;


void MergeSort::sort( vector<int>& sequence )
{
	vector<int>::iterator left;
	vector<int>::iterator right;

	left = sequence.begin();
	right = sequence.end() - 1;

	sort( sequence, left, right );
}


void MergeSort::sort( vector<int>& sequence,
		vector<int>::iterator left,
		vector<int>::iterator right )
{

	// If already one element => sorted.
	if( left >= right )
		return;

	vector<int>::iterator middle;
	middle = (vector<int>::iterator)(left + ( right - left )/2);
	sort( sequence, left, middle );
	sort( sequence, middle + 1, right );
	merge( sequence, left, middle, right );
}


void MergeSort::merge( std::vector<int>& sequence,
		vector<int>::iterator left,
		vector<int>::iterator middle,
		vector<int>::iterator right )

{
	vector<int> aux1;
	for( vector<int>::iterator l = left; l != middle; l++ )
	{
		aux1.push_back( *l );
	}
	cout << "aux1.size() = " << aux1.size() << endl;
	for( unsigned int i = 0; i < aux1.size(); i++ )
		cout << aux1[i] << " ";
}

// Przyda sie metoda kopiujaca wektor do wektora.
