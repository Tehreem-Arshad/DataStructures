#ifndef __SORTS_CPP
#define __SORTS_CPP
#include "sorts.h"
#include "heap.cpp"
#include "list.cpp"

//=====================================================================================

vector<long> InsertionSort(vector<long> nums)
{
    int arr_size = nums.size() ;
    long arr[arr_size] ;
    int i = 0;
    while (i<arr_size)
    {
         arr[i] = nums[i];
         i=i+1;
    }

    int a , b ;

    for (int i = 0 ; i < arr_size ; i++)
    {
        a = arr[i] ;
        b = i - 1 ;

        while (arr[b] > a && b >= 0)
        {
            arr[b + 1] = arr[b] ;
            b=b-1 ;
        }

        arr[b + 1] = a ;
    }
    int j = 0;
    while (j<arr_size)
    {
         nums[j] = arr[j];
         j++;
    }


    return nums ;
}

//=====================================================================================

ListItem<long>* disintegrate(ListItem<long> *h_ref)
{
    ListItem<long> *f = h_ref ;
    ListItem<long> *s = h_ref ;

    while (f -> next != NULL && f -> next -> next != NULL)
    {
        f = f -> next -> next ;
        s = s -> next ;
    }

    ListItem <long> *last = s -> next ;

    s -> next = NULL ;

    return last ;
}
ListItem<long> *merger_helper(ListItem<long> *ptr_first , ListItem<long> *ptr_second)
{
    ListItem <long> *f_ref = ptr_first ;

    ListItem <long> *s_ref = ptr_second ;

    if (f_ref == NULL)
        return s_ref ;

    if (s_ref == NULL)

        return f_ref ;


    if (f_ref -> value < s_ref -> value)
    {
        f_ref -> next = merger_helper(f_ref -> next , s_ref) ;
        ListItem <long> *t_ptr = f_ref -> next ;
        t_ptr -> prev = f_ref ;
        f_ref -> prev = NULL ;
        return f_ref ;
    }

    else
    {
        s_ref -> next = merger_helper(f_ref , s_ref -> next) ;
        s_ref -> next -> prev = s_ref ;
        s_ref -> prev = NULL ;
        return s_ref ;
    }
}

ListItem<long> *arranging(ListItem<long> *H)
{
    ListItem <long> *h_ref = H ;

    if (h_ref == NULL || h_ref -> next == NULL)
    	return h_ref ;

    else
    {
        ListItem<long> *s_list = disintegrate(h_ref) ;

        h_ref = arranging(h_ref) ;

        s_list = arranging(s_list) ;

        return merger_helper(h_ref , s_list) ;
    }
}


vector<long> MergeSort(vector<long> nums)
{
   List <long> list ;

    int len = nums.size() ;
    int i =0;
	while (i<len)
	{
		  list.insertAtHead(nums[i]) ;
		i++;
	}


    ListItem <long> *ptr = list.getHead() ;

    ptr = arranging(ptr) ;

    int pos = 0 ;

    while (ptr != NULL)
    {
        nums[pos] = ptr -> value ;
        ptr = ptr -> next ;
        pos++ ;
    }

    return nums ;
}

//=====================================================================================


vector<long> HeapSort(vector<long> nums)
{
	int vector_size = nums.size();
	MinHeap* Heap_vec = new MinHeap(vector_size) ;
	int countr = 0 ;

	for (int i = 0 ; i < nums.size() ; i++)
	{
		Heap_vec -> insertKey(nums[i]) ;
		countr++ ;
	}

	for (int i = 0 ; i < countr ; i++)
	{
		int output = Heap_vec -> extractMin() ;
		nums[i] = output ;
	}

	return nums ;
}

#endif
