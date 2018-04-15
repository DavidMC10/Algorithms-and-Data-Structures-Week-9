/**
 * BinaryHeap.h
 *
 * Generic Dynamic BinaryHeap based on array
 *
 * @author  Aiden McCaughey
 * @email   a.mccaughey@ulster.ac.uk
 * @version 1.0
 */

#ifndef BINARY_HEAP_H_
#define BINARY_HEAP_H_

#include "Array.h"

template <class T>
class BinaryHeap
{
public:
	explicit BinaryHeap( int capacity = 100 );
	BinaryHeap(const BinaryHeap<T> & other);
    BinaryHeap(const Array<T> & other);
        
	bool isEmpty( ) const;
	void makeEmpty( );

	T  find( ) const;
	void deleteMin();

	void insert( const T & value );
	void buildHeap(const Array<T> & data);

protected:
	int currentSize;        // Number of elements in heap
	Array<T> array;        // The heap array

	void percolateDown(int hole); // percolate item in hole down to its correct position

};

// ---------------------- IMPLEMENTATION BinaryHeap.cpp ---------------------------------

/**
* Construct the binary heap.
* capacity is the capacity of the binary heap.
*/
template <class T>
BinaryHeap<T>::BinaryHeap(int capacity) : currentSize{ 0 }, array(capacity + 1) {}

template <class T>
BinaryHeap<T>::BinaryHeap(const BinaryHeap<T> & other) : currentSize(0), array(other) { }

template <class T>
BinaryHeap<T>::BinaryHeap(const Array<T> & other) : currentSize(0), array(other.length()+1) {
    buildHeap(other);
}

/**
* Test if the priority queue is logically empty.
* Return true if empty, false otherwise.
*/
template <class T>
bool BinaryHeap<T>::isEmpty( ) const
{
	return currentSize == 0;
}

/**
* Make the priority queue logically empty.
*/
template <class T>
void BinaryHeap<T>::makeEmpty( )
{
	currentSize = 0;
}


template <class T>
void BinaryHeap<T>::buildHeap(const Array<T> & data)
{
    // COMPLETE THIS METHOD

	// 1. ensure underling heap array 'called array' is big enough and resize if required
	

	// 2. empty the heap


	// 3. finally add each data array element to the heap
	
}

/**
* Find the next item in the priority queue.
* Return the next item, or throw Underflow if empty.
*/
template <class T>
T  BinaryHeap<T>::find( ) const
{
	assert(currentSize > 0);
	return array[ 1 ];
}

template <class T>
void BinaryHeap<T>::deleteMin( )
{
	assert(currentSize > 0);

	// Percolate down
	array[ 1 ] = array[ currentSize-- ];
	percolateDown( 1 );
}


template <class T>
void BinaryHeap<T>::insert( const T & value )
{
	assert(currentSize < array.length()-1);

	// Percolate up
	int hole = ++currentSize;
	for( ; hole > 1 && value < array[ hole / 2 ]; hole /= 2 ) {
	    array[ hole ] = array[ hole / 2 ];
	}

	array[ hole ] = value;
}

// -------------------- Private Methods -------------------

/**
* Internal method to percolate down in the heap.
* hole is the index at which the percolate begins.
*/
template <class T>
void BinaryHeap<T>::percolateDown( int hole )
{
	/* 1*/      int child;
	/* 2*/      T tmp = array[ hole ];

	/* 3*/      for( ; hole * 2 <= currentSize; hole = child )
				{
	/* 4*/          child = hole * 2;
	/* 5*/          if (child != currentSize && array[child + 1] < array[child]) {
	/* 6*/              child++;
					}
	/* 7*/          if (array[child] < tmp) {
	/* 8*/              array[hole] = array[child];
					} else {
	/* 9*/            break;
					}
				}
	/*10*/      array[ hole ] = tmp;
}

#endif
