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
    

    // add array elements to heap (build heap)
   

    // remove k-1 min elements from heap
   

    // return k'th element from the heap
    return 0;
}

// Sort the supplied array using the heapSort algorithm
void heapSort(Array<int> & data) {
    // create binary heap of correct size
    

    // add array elements to heap
   

    // remove elements from heap and add to array
    // thus sorting the array which is passed by reference   

}

void testHeapSort() {
    // create an array of random values
   
    // print the unsorted data
  
    // sort the array by calling the heapSort algorithm
    // rememeber the array is passed by reference
  
    // print the sorted data
   
}

// test selection algorithm
void testSelection()
{
   
    // create and fill an unsorted array
  
    // print array values
  
    // use a loop to ensure user enters a valid value for k (>0 && <=data.length())
   

    // call selection algorithm defined above
   

    // print result of selection algorithm
    
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
