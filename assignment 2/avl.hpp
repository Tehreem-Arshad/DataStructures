#include "avl.cpp"

#ifndef __AVL_HPP
#define __AVL_HPP


template <class T, class S>
struct node{
    T key;
    S value;
    node *left;
    node *right;
    int height;

    node (T key, S value){
        this->key = key;
        this->value = value;
        left = NULL;
        right = NULL;
        height = 1;
    }
};


template <class T, class S>
class AVL {
    node<T,S> *root;
    bool isAVL;
    node<T,S>* LRR(node<T,S>*);
    node<T,S>* RLR(node<T,S>*);
    node<T,S>* DelNodeHelper(node<T,S>*,T );
    node<T,S>* MinVAlNode(node<T,S>*) ;
    node<T,S>* RemoveMinValNode(node<T,S>*);
    node<T,S>* Helper_AVL(node<T,S>* ,node<T,S>*);
    node<T,S>* LLR(node<T,S>*) ;
    node<T,S>* InsertNodeHelper(node<T,S>*,node<T,S>*);
    node<T,S>* SearchNodeHelper(T , node<T,S>*) ;
    node<T,S>* RRR(node<T,S>*);
    node<T,S>* balancing(node<T,S>*);
    int b_factor(node<T,S>*);




public:
    AVL(bool);
    ~AVL();
    void insertNode(node<T,S>*);
    void deleteNode(T k);
    node<T,S>* searchNode(T k);
    node<T,S>* getRoot();
    int height (node<T,S>* p);


};


#endif
