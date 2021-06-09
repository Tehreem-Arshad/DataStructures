#ifndef __STACK_CPP
#define __STACK_CPP
#include "stack.h"
template <class T>
Stack<T>::Stack()
{
}

template <class T>
Stack<T>::Stack(Stack<T>& otherStack)
{
    Stack<T> t_Stack;
    while ( !otherStack.isEmpty() )
    {
        t_Stack.push(otherStack.pop());
    }
    while ( !t_Stack.isEmpty() )
    {
        T val = t_Stack.pop();
        this->push(val);
        otherStack.push(val);
    }
}

template <class T>
Stack<T>::~Stack()
{
}

template <class T>
void Stack<T>::push(T item)     // Item pushed at head
{
    list.insertAtHead(item);
}

template <class T>
T Stack<T>::top()
{
        return (list.getHead())->value;

}

template <class T>
T Stack<T>::pop()
{
    T poped_element = list.getHead()->value;
	list.deleteHead();
    return poped_element;
}

template <class T>
int Stack<T>::length()
{
    return list.length();
}

template <class T>
bool Stack<T>::isEmpty()
{
        if (list.length()==0)
            return true;
        else
            return false ;
}

#endif
