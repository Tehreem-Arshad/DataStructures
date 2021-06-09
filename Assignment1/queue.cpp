#ifndef __QUEUE_CPP
#define __QUEUE_CPP
#include "queue.h"

template <class T>
Queue<T>::Queue()
{

}

template <class T>
Queue<T>::Queue(Queue<T>& otherQueue)
{
    Queue <T> t_Queue ;
         while ( !otherQueue.isEmpty() )
    {
        t_Queue.enqueue(otherQueue.dequeue());
    }
    while ( !t_Queue.isEmpty() )
    {
        T val = t_Queue.dequeue();
        this->enqueue(val);
        otherQueue.enqueue(val);
    }
}

template <class T>
Queue<T>::~Queue()
{

}

template <class T>
void Queue<T>::enqueue(T item)
{
    list.insertAtTail(item) ;
}

template <class T>
T Queue<T>::front()
{
    return list.getHead()->value ;

}

template <class T>
T Queue<T>::dequeue()
{
    T val ;
    val = front () ;
    list.deleteHead() ;
    return val ;
}

template <class T>
int Queue<T>::length()
{
    return list.length ();
}

template <class T>
bool Queue<T>::isEmpty()
{
    if (list.length()==0)
        return true ;
    else
        return false ;
}


#endif
