#ifndef __LIST_CPP
#define __LIST_CPP

#include <iostream>
#include <cstdlib>
#include "LinkedList.h"

template <class T>
LinkedList<T>::LinkedList()
{
    head = NULL;
    tail = NULL;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& otherLinkedList)
{
    head = NULL;
    tail = NULL;
    if (otherLinkedList.head == NULL)
    {
        return;
    }
    else
    {
        ListItem<T>* temp = otherLinkedList.head;
        while(temp != NULL)
        {
            insertAtTail(temp->value);
            temp = temp->next;
        }
    }

}

template <class T>
LinkedList<T>::~LinkedList()
{

    while(head != NULL)
    {
        ListItem<T>* temp = head;
        head = head->next;
        delete temp;
    }
   // head = NULL;
    tail = NULL;
}

template <class T>
void LinkedList<T>::insertAtHead(T item)
{
    ListItem<T> *temp = new ListItem<T>(item);
    if (head == NULL)
    {

        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

template <class T>
void LinkedList<T>::insertAtTail(T item)
{
    if (head == NULL)
    {
        head = new ListItem<T>(item);
        tail = head;
    }
    else
    {
        ListItem<T>* temp = new ListItem<T>(item);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

template <class T>
void LinkedList<T>::insertAfter(T toInsert, T afterWhat)
{
     if (head!= NULL)
    {
        ListItem<T> *temp;
        temp= head ;
        while (temp!= NULL)
        {
            if (temp->value ==afterWhat)
            {
                ListItem <T> *new_node = new ListItem<T>(toInsert);
                new_node->next = temp->next;
                new_node->prev = temp;
                temp->next= new_node;
                break;
            }
            else
                temp=temp->next;
        }
        if (temp==NULL)
            return;
    }

}


template <class T>
ListItem<T>* LinkedList<T>::getHead()
{
    return head;
}

template <class T>
ListItem<T>* LinkedList<T>::getTail()
{
    return tail;
}

template <class T>
ListItem<T> *LinkedList<T>::searchFor(T item)
{
    ListItem<T>* temp = head;
    while(temp != NULL)
    {
        if(temp->value == item)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

template <class T>
void LinkedList<T>::deleteElement(T item)
{
    ListItem<T>* tempItem = searchFor(item);
    // If item not found
    if(tempItem == NULL)
    {
        return;
    }
    // If item found
    else if(tempItem == head)
    {
        this->deleteHead();
    }
    else if(tempItem == tail)
    {
        this->deleteTail();
    }
    else
    {
        tempItem->prev->next = tempItem->next;
        tempItem->next->prev = tempItem->prev;
        delete tempItem;
        tempItem = NULL;
    }
}

template <class T>
void LinkedList<T>::deleteHead()
{
    if(head == NULL)
    {
        return;
    }
    else if(head->next == NULL)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
    else
    {
        head = head->next;
        delete head->prev;
        head->prev = NULL;
    }
}

template <class T>
void LinkedList<T>::deleteTail()
{
    if(head == NULL)
    {
        return;
    }
    else if(head->next == NULL)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
    else
    {
        tail = tail->prev;
        delete tail->next;
        tail->next = NULL;
    }
}

template <class T>
int LinkedList<T>::length()
{
    int count = 0;
    ListItem<T>* temp = head;
    while(temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

#endif
