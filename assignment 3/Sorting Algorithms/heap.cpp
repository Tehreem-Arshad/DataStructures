#ifndef __HEAP_CPP
#define __HEAP_CPP
#include "heap.h"


MinHeap::MinHeap(int cap)
{
	heap_size = 0 ;
    capacity = cap ;
    harr = new int [cap] ;
}

void MinHeap::MinHeapify(int i)
{
	int MinHeap = i ;

    if (left(i) < heap_size && harr[left(i)] < harr[MinHeap])
        MinHeap = left(i) ;

    if (right(i) < heap_size && harr[right(i)] < harr[MinHeap])
        MinHeap = right(i) ;

    if (MinHeap != i)
    {
        int t = harr[i] ;
        harr[i] = harr[MinHeap] ;
        harr[MinHeap] = t ;
        MinHeapify(MinHeap) ;
    }
}
 
int MinHeap::parent(int i)
{
	 int P = (i - 1)/2 ; 
    return P;
}
 
int MinHeap::left(int i)
{
	  int L =  (2 * i + 1) ;
    return L;
}
 
int MinHeap::right(int i)
{
    int R =  (2 * i + 2) ;
    return R ;

}
 
int MinHeap::extractMin()
{
	if (heap_size <= 0)
        return -1 ;

    if (heap_size == 1)
    {
        heap_size = heap_size-1 ;
        return harr[0];
    }

    int R = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size = heap_size-1;
    MinHeapify(0);

    return R;
}
 
void MinHeap::decreaseKey(int i, int new_val)
{
	harr[i] = new_val ;

    while (harr[parent(i)] > harr[i] && i != 0 )
    {
       int t = harr[i] ;
       harr[i] = harr[parent(i)] ;
       harr[parent(i)] = t ;

       i = parent(i) ;
    }
}
 
int MinHeap::getMin()
{
	return harr[0] ;
}
 
void MinHeap::deleteKey(int i)
{
	if (i >= heap_size)
        return ;

    decreaseKey(i, -1);
    extractMin();
}
 
void MinHeap::insertKey(int k)
{
	if (heap_size == capacity)
        return ;
    
    heap_size = heap_size + 1 ;

    harr[heap_size - 1] = k ;

    int Last = heap_size - 1 ;

    while (harr[parent(Last)] > harr[Last] && Last != 0)
    {
       int t = harr[Last] ;
       harr[Last] = harr[parent(Last)] ;
       harr[parent(Last)] = t ;

       Last = parent(Last) ;
    }
}

int* MinHeap::getHeap()
{
	return harr;
}

#endif