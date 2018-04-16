//============================================================================
// Name        : practical9.cpp
// Author      : a.mccaughey@ulster.ac.uk
// Version     : 1.0
// Description : 
//============================================================================
#include <iostream>
#include "BinaryHeap.h"

using namespace std;

// Selection Algorithm
//PreCondition: k >=0 && k <= data.length
//PostCondition: return k'th smallest element in array
int selection(int k, const Array<int> & data) {
    assert(k> 0 && k <= data.length());

    // create a heap of correct size
	BinaryHeap<int> heap(data.length());
	
    // add array elements to heap (build heap)
	heap.buildHeap(data);

    // remove k-1 min elements from heap
	for (int i{ 0 }; i < k - 1; i++)
	heap.deleteMin();

    // return k'th element from the heap
	return heap.find();
}

// Sort the supplied array using the heapSort algorithm
void heapSort(Array<int> & data) {

    // create binary heap of correct size
	BinaryHeap<int> heap(data.length());

    // add array elements to heap
	heap.buildHeap(data);
   
    // remove elements from heap and add to array
	// thus sorting the array which is passed by reference  
	for (int i{ 0 }; i < data.length(); i++) {
		data[i] = heap.find();
		heap.deleteMin();
	}
}

void testHeapSort() {
    // create an array of random values
	Array<int> test(5);
	test[0] = 21; test[1] = 14; test[2] = 54;
	test[3] = 43; test[4] = 25;
    
	// print the unsorted data
	cout << "Unsorted Data: ";
	for (int i{ 0 }; i < test.length(); i++)
		cout << test[i] << ", ";
	cout << endl << endl;
  
    // sort the array by calling the heapSort algorithm
	// rememeber the array is passed by reference
	heapSort(test);
  
    // print the sorted data
	cout << "Sorted Data: ";
	for (int i{ 0 }; i < test.length(); i++)
		cout << test[i] << ", ";
	cout << endl << endl;
   
}

// test selection algorithm
void testSelection()
{
   
    // create and fill an unsorted array
	Array<int> test(5);
	test[0] = 21; test[1] = 14; test[2] = 54;
	test[3] = 43; test[4] = 25;
  
    // print array values
	cout << "Array values: ";
	for (int i{ 0 }; i < test.length(); i++)
		cout << test[i] << ", ";
	cout << endl << endl;

  
    // use a loop to ensure user enters a valid value for k (>0 && <=data.length())
	int k{ 0 };
	do {
		cout << "Please enter a value for K: ";
		cin >> k;
	} while (k <= 0 && k > test.length());
	cout << endl << endl;
   

    // call selection algorithm defined above
	// print result of selection algorithm
	cout << "Result of selection algorithm: " << selection(k, test);

}

int main()
{
    // Test heapsort
    testHeapSort();

    // Test Selection algorithm
    testSelection();

    // ---------------------------------------------------
    std::cout << std::endl << "Press enter to quit";
    std::cin.sync(); // flush input buffer
    std::cin.ignore(); // ignore what user enters
    std::cin.get();

    return 0;
}
