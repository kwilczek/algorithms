#include <iostream>
#include <random>
#include <vector>
#include <chrono>
// http://www.cplusplus.com/reference/algorithm/reverse/
// http://www.cplusplus.com/reference/algorithm/swap/
#include <algorithm>


#include "colors.h"
#include "mersenne.h"
#include "sorter.h"
#include "insertion.h"
#include "selection.h"
#include "bubble.h"
#include "quick.h"
#include "merge.h"

using namespace std;
// http://www.cplusplus.com/reference/chrono/
using namespace std::chrono;

class Helpers
{
	public:
		// Print vector.
		void print_vector( vector<int>& sequence )
		{
			vector<int>::iterator it;
			for( it = sequence.begin(); it != sequence.end(); it++ )
			{
				cout << *it << " "; 
			}
		}
};

// Second argument contains selected algorithm.
// We will initialize appropriate algorithm.
Sorter* init_sorter( int cond )
{
	Sorter* sorter( NULL );
	switch( cond )
	{
		case 1:
			sorter = new BubbleSort();
			break;
		case 2:
			sorter = new SelectionSort();
			break;
		case 3:
			sorter = new InsertionSort();
			break;
		case 4:
			sorter = new QuickSort();
			break;
		case 5:
			sorter = new MergeSort();
			break;
	}
	return sorter;
}

int main( int argc, char* argv[] )
{

	// We want vector size and sorting algorithm.
	if( argc < 3 )
	{
		cerr << endl;
		cerr << argv[0] << COL_FYEL << " vector_size sorting_alg_code" << COL_RS;
		cerr << endl << endl;
		//cerr << "Available sorting algorithms:" << endl;
		cerr << COL_FGRN << "Code" << COL_FYEL << "  Algorithm" << endl;
		cerr << COL_RS << "---------------" << endl;
		cerr << COL_FGRN << "1" << COL_FYEL << "     Bubble" << COL_RS << endl;
		cerr << COL_FGRN << "2" << COL_FYEL << "     Selection" << COL_RS << endl;
		cerr << COL_FGRN << "3" << COL_FYEL << "     Insertion" << COL_RS << endl;
		cerr << COL_FGRN << "4" << COL_FYEL << "     Quick" << COL_RS << endl;
		cerr << COL_FGRN << "5" << COL_FYEL << "     Merge" << COL_RS << endl;
		cerr << endl;
		return 1;
	}

	// First argument ot our program contains desired
	// vector size.
	vector<int> sequence( stoi(argv[1]) );
	Mersenne mersenne;
	Helpers helper;

	Sorter* sorter = init_sorter( stoi(argv[2]) );

	// Initialize sequence with wide range.
	// max is 10 times the sequence size.
	mersenne.init_seq_rand( sequence, 1, 10*sequence.size() );
	cout << "Pristine" << endl;
	//helper.print_vector( sequence );
	cout << endl;
	if( is_sorted( sequence.begin(), sequence.end() ))
		cout << "posortowana" << endl;

	steady_clock::time_point begin = steady_clock::now();
	// Sorting random sequence in ascending order.
	// SORT ASCENDING
	sorter->sort( sequence );
	steady_clock::time_point end = steady_clock::now();
	cout << "First sorting" << endl;
	//helper.print_vector( sequence );
	cout << endl;
	if( is_sorted( sequence.begin(), sequence.end() ))
		cout << "posortowana" << endl;

	duration<double> time_span = duration_cast<duration<double>>( end - begin );
	cout << "Unsorted random: " << time_span.count() << " seconds" << endl;

	begin = steady_clock::now();
	// Sorting already sorted sequence.
	// SORT SORTED
	sorter->sort( sequence );
	end = steady_clock::now();
	cout << "Second sorting" << endl;
	//helper.print_vector( sequence );
	cout << endl;
	if( is_sorted( sequence.begin(), sequence.end() ))
		cout << "posortowana" << endl;

	time_span = duration_cast<duration<double>>( end - begin );
	cout << "Sorting already sorted: " << time_span.count() << " seconds" << endl;

	// Now the vector in ascending order is no longer needed,
	// let us reverse it.
	reverse( sequence.begin(), sequence.end() );
	cout << "Reversed" << endl;
	//helper.print_vector( sequence );
	cout << endl;

	begin = steady_clock::now();
	// Sorting sequence sorted in descending order.
	// SORTING REVERSE SORTED
	sorter->sort( sequence );
	end = steady_clock::now();
	cout << "Sorted reversed" << endl;
	//helper.print_vector( sequence );
	cout << endl;
	if( is_sorted( sequence.begin(), sequence.end() ))
		cout << "posortowana" << endl;

	time_span = duration_cast<duration<double>>( end - begin );
	cout << "Sorting reverse sorted: " << time_span.count() << " seconds" << endl;

}
