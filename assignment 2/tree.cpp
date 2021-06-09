#ifndef __TREE_CPP
#define __TREE_CPP
#include <iostream>
#include "tree.hpp"


template <class T, class S>
Tree<T,S>::Tree(node<T,S> *root) {
	this->root = root;
}

template <class T, class S>
node<T,S>* Tree<T,S>::findKey(T key) {

		if(root == NULL){return NULL;}

	return findKeyHelper(root,key);

}

template <class T, class S>
node<T,S>* Tree<T,S>::findKeyHelper(node<T,S> *t_node, T key) {

	if(t_node==NULL)
		return NULL;
	if(t_node->key==key)
        return t_node;

	node<T,S> * t_ptr = findKeyHelper(t_node->child, key);
	node<T,S> * t_ptr1 = findKeyHelper(t_node->sibling, key);
	if(t_ptr==NULL)
		return t_ptr1;
	else
		return t_ptr;


}

template <class T, class S>
bool Tree<T,S>::insertChild(node<T,S> *child_ptr, T key) {

	node<T,S> * temp=findKey(child_ptr->key);
	if(temp!=NULL)
    return false;
	else{

	node<T,S> * t_ptr1 = findKey(key);
	if(t_ptr1==NULL)
		return false;
	else if(t_ptr1 !=NULL && t_ptr1->child==NULL)
        {
            t_ptr1->child=child_ptr;
            return true;
		}
		else if (t_ptr1 != NULL && t_ptr1->child != NULL)
		{
			node<T,S> * t_ptr2 = t_ptr1->child;
			t_ptr1->child=child_ptr;
			child_ptr->sibling=t_ptr2;
			return true;
		}
	}
}

template <class T, class S>
std::vector<node<T,S>*> Tree<T,S>::getAllChildren(T k) {

	std::vector<node<T,S>*> v1;

	node<T,S> * t_ptr=findKey(k);

	if(t_ptr != NULL && t_ptr->child != NULL)

	{
		v1.push_back(t_ptr->child);
		t_ptr=t_ptr->child->sibling;
		while(t_ptr!=NULL)
		{
			v1.push_back(t_ptr);
			t_ptr=t_ptr->sibling;
		}
		return v1;
	}
	return std::vector<node<T,S>*>();
}

template <class T, class S>
int Tree<T,S>::findHeight() {

	return findHeightHelper(root);
}

template <class T, class S>
int Tree<T,S>::findHeightHelper(node<T,S> *t_node) {

	if(t_node==NULL)
		return 0;
	int t_ptr = findHeightHelper(t_node->child) + 1;
	int t_ptr1 = findHeightHelper(t_node->sibling);
	if (t_ptr>t_ptr1)
		return	t_ptr;
	else
		return t_ptr1;
    return 0;
}

template <class T, class S>
bool Tree<T,S>::deleteLeaf(T k) {

	if(root==NULL || root->child==NULL)
        return false;

	node<T,S> * t_ptr=deleteLeafHelper(root, k);


	if(t_ptr==NULL)
        return false;
	else{

		if (t_ptr->sibling!=NULL)
            {
                if(t_ptr->sibling->key==k && t_ptr->sibling->sibling==NULL && t_ptr->sibling->child==NULL)
		{

			node<T,S> * t_ptr1=t_ptr->sibling;
			t_ptr->sibling=NULL;
			delete t_ptr1;
			return true;

		}
	}
	if(t_ptr->sibling!=NULL){
		if(t_ptr->sibling->key==k && t_ptr->sibling->sibling!=NULL && t_ptr->sibling->child==NULL)
		{

			node<T,S> * t_ptr1=t_ptr->sibling;
			t_ptr->sibling=t_ptr1->sibling;
			delete t_ptr1;
			return true;

		}
	}
	if(t_ptr->child!=NULL){
		 if(t_ptr->child->key==k && t_ptr->child->child==NULL && t_ptr->child->sibling==NULL )
		{

			node<T,S> * t_ptr1=t_ptr->child;
			t_ptr->child=NULL;
			delete t_ptr1;
			return true;

		}
	}
	if(t_ptr->child!=NULL)
        {
            if (t_ptr->child->key == k && t_ptr->child->child == NULL && t_ptr->child->sibling != NULL )
		{

			node<T,S> * t_ptr1=t_ptr->child;
			t_ptr->child=t_ptr1->sibling;
			delete t_ptr1;
			return true;

		}
	}

		else
			return false;
	}


		return false;
}

template <class T, class S>
node<T,S>* Tree<T,S>::deleteLeafHelper(node<T,S> *t_node, T key) {
	if(t_node==NULL)
	{
		return NULL;
	}

	if(t_node->sibling !=NULL )
	{
		if(t_node->sibling->key==key)
			{
				return t_node;
			}
	}

	if(t_node->child !=NULL)
	{
		 if(t_node->child->key==key)
			{
				return t_node;
			}
	}

	node<T,S> * t_ptr = deleteLeafHelper(t_node->child, key);
	node<T,S> * t_ptr1 = deleteLeafHelper(t_node->sibling, key);

	if (t_ptr==NULL)
		return t_ptr1;
	else
		return t_ptr;
	return NULL;

}

template <class T, class S>
Tree<T,S>::~Tree() {

	deleteTree(root);
}

template <class T, class S>
void Tree<T,S>::deleteTree(node<T,S> *t_node) {
	if(t_node==NULL)
	{
		return;
	}

	delete deleteTree(t_node->child);
	delete deleteTree(t_node->sibling);

	return;
}

template <class T, class S>
node<T,S>* Tree<T,S>::getRoot() {

	return root;
}

#endif
