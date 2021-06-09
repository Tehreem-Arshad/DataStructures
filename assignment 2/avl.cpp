#ifndef __AVL_CPP
#define __AVL_CPP
#include <cmath>
#include <iostream>
#include <algorithm>
#include "avl.hpp"


template <class T, class S>
AVL<T,S>::AVL(bool isAVL)
{
    this->root = NULL;
    this->isAVL = isAVL;
}

template <class T, class S>
AVL<T,S>:: ~AVL()
{

}

template <class T, class S>
int AVL<T,S> :: height (node<T,S>* node_ptr)
{
 if(node_ptr==NULL) return 0;

if(isAVL==false)
{
    return std::max(height(node_ptr->left),height(node_ptr->right))+1;
}
else if(isAVL==true)
{
return std::max(height(node_ptr->left),height(node_ptr->right))+1;
}
}
template <class T,class S>
int AVL<T,S>::b_factor(node<T,S>*p)
{
    int LH= height(p->left);
    int RH=height(p->right);
    return (LH-RH);
}

template <class T, class S>
void AVL<T,S> :: insertNode(node<T,S>* newNode)
{
if(isAVL==false)
{


    if(root==NULL)
    {
        root=newNode;
    }
  else
  {
      node<T,S>* t_ptr=root;
      node<T,S>* t_ptr1=NULL;

      while(t_ptr!=NULL)
      {
          t_ptr1=t_ptr;
          if(t_ptr->key < newNode->key)
          {
              t_ptr=t_ptr->right;
          }
           else
            t_ptr=t_ptr->left;
      }
      if(t_ptr1->key < newNode->key)
      {
          t_ptr1->right=newNode;
      }
      else
        t_ptr1->left=newNode;
  }
}
else if(isAVL==true)
{
root=Helper_AVL(root,newNode);
}
}
template <class T, class S>
node<T,S>* AVL<T,S>::Helper_AVL(node<T,S>* tr,node<T,S>*p)
{
    if(tr==NULL)
    {
        tr=p;
        return balancing(tr);
    }

    if(p->key>tr->key)
{


     tr->right=Helper_AVL(tr->right,p);

    }
    else if(p->key<tr->key)
    {
     tr->left=Helper_AVL(tr->left,p);

    }

    return balancing(tr);
}
template <class T, class S>
node<T,S>* AVL<T,S> :: searchNode(T key)
{
if(root==NULL) return NULL;
else
{
node<T,S>* t_ptr=root;
if(t_ptr->key==key)
{
    return t_ptr;
}
while(t_ptr!=NULL)
{
    if(t_ptr->key < key)
    {
        t_ptr=t_ptr->right;
    }
    else if(t_ptr->key > key)
    {
        t_ptr=t_ptr->left;
    }
    else if(t_ptr->key==key)
    {
        return t_ptr;
    }
}
return NULL;
}

}



template <class T, class S>
void AVL<T,S>::deleteNode(T k)
{

root=DelNodeHelper(root,k);

}



template <class T, class S>
node<T,S>* AVL<T,S>::DelNodeHelper(node<T,S>* temp,T k)
{
if(isAVL==false) {
    if(temp==NULL) return NULL;
    else if(k>temp->key)
    {
        temp->right=DelNodeHelper(temp->right,k);
    }
    else if(k < temp->key)
    {
        temp->left=DelNodeHelper(temp->left,k);
    }
    else
    {
        if(temp->left==NULL && temp->right==NULL)
        {

            delete temp;
            temp=NULL;
            return temp;
        }
        else if(temp->right==NULL)
        {
            node<T,S>* temp3=temp;
            temp=temp->left;
            delete temp3;
            return temp;

        }
        else if(temp->left==NULL)
        {
            node <T,S>* temp4=temp;
            temp=temp->right;
            delete temp4;
            return temp;
        }
        else
        {
            node<T,S>*temp5=MinVAlNode(temp->right);
            temp->key=temp5->key;
            temp->value=temp5->value;
            temp->right=RemoveMinValNode(temp->right);
            return temp;
        }


    }
}
else if(isAVL==true)
{
    if(temp==NULL)
    return NULL;
    else if(k> temp->key)
    {
        temp->right=DelNodeHelper(temp->right,k);
    }
    else if(k < temp->key)
    {
        temp->left=DelNodeHelper(temp->left,k);
    }
    else
    {
        if(temp->left==NULL && temp->right==NULL)
        {

            delete temp;
            temp=NULL;
            return temp;
        }
        else if(temp->right==NULL)
        {
            node<T,S>* temp3=temp;
            temp=temp->left;
            delete temp3;


        }
        else if(temp->left==NULL)
        {
            node <T,S>* temp4=temp;
            temp=temp->right;
            delete temp4;

        }
        else
        {
            node<T,S>*temp5=MinVAlNode(temp->right);
            temp->key=temp5->key;
            temp->value=temp5->value;
            temp->right=RemoveMinValNode(temp->right);

        }


    }
    return balancing(temp);
}

}

template <class T, class S>
node<T,S>* AVL<T,S>::RemoveMinValNode(node <T,S>* temp)
{   if (temp== NULL)
    {
        return NULL;
    }
    else if (temp->left == NULL)
    {
        return temp->right;
    }
    else
    {
        temp->left = RemoveMinValNode(temp->left);
    }
    return temp;

}
template <class T, class S>
node<T,S>* AVL<T,S>::MinVAlNode(node <T,S>* node_ptr)
{
    if(node_ptr==NULL)
        return NULL;
else
{
    while(node_ptr->left!=NULL)
    {
        node_ptr=node_ptr->left;
    }
    return node_ptr;
}
}
template <class T, class S>
node<T,S>* AVL<T,S>::balancing(node<T,S>*ptr)
{
    int fac=b_factor(ptr);
    if(fac>1)
    {
        if(b_factor(ptr->left) > 0 )
        {
            ptr=LLR(ptr);
        }
        else
        {
            ptr=LRR(ptr);
        }

    }
    else if(fac < -1 )
    {
        if(b_factor(ptr->right) > 0)
        {
            ptr=RLR(ptr);
        }
        else
        {
            ptr=RRR(ptr);
        }
    }
return ptr;
}

template <class T, class S>
node<T,S>* AVL<T,S>::LLR(node<T,S>*node_ptr)
{
    node<T,S>* left_ptr=node_ptr->left;
    node_ptr->left=left_ptr->right;
    left_ptr->right=node_ptr;
    return left_ptr;


}
template <class T, class S>
node<T,S>* AVL<T,S>::RLR(node<T,S>*p)
{
    node<T,S>* temp3=p->right;
    p->right=LLR(temp3);

    return RRR(p);

}
template <class T, class S>
node<T,S>* AVL<T,S>::RRR(node<T,S>*node_ptr)
{
    node<T,S>* right_ptr=node_ptr->right;
    node_ptr->right=right_ptr->left;
    right_ptr->left=node_ptr;
    return right_ptr;


}
template <class T, class S>
node<T,S>* AVL<T,S>::LRR(node<T,S>*node_ptr)
{
    node<T,S>* t_ptr=node_ptr->left;

    node_ptr->left=RRR(t_ptr);
    return LLR(node_ptr);


}

template <class T, class S>
node<T,S>* AVL<T,S>::getRoot()
{
    if(root==NULL )
    {
        return NULL;
    }
    return root;
}

#endif
