#include <iostream>
#include <stdlib.h>
#include <signal.h>
#include "tree.hpp"

using namespace std;


int test_case;

void signal_handler(int);
void print_success();
bool compare_vectors(vector<node<int,string>*>, vector<int>);

int main()
{
	signal(SIGSEGV, signal_handler);


	Tree<int,string> *myTree = new Tree<int,string>(new node<int,string>(1,"A"));

	cout << "-----Testing insert function-----\n";
	//Case-I : Insert first child of root
	test_case = 1;
	if(myTree->insertChild(new node<int,string>(2,"B"), 1))
	{
		node<int,string> *ptr = myTree->getRoot()->child;
		if(ptr->key!=2)
		{
			raise(SIGSEGV);
			exit(-1);
		}
	}
	else
	{
		raise(SIGSEGV);
		exit(-1);
	}
	print_success();

	//Case-II : Insert second child of root
	test_case = 2;
	if(myTree->insertChild(new node<int,string>(3,"C"), 1))
	{
		node<int,string> *ptr = myTree->getRoot()->child;
		if(ptr->key!=3 && ptr->sibling->key!=3)
		{
			raise(SIGSEGV);
			exit(-1);
		}
	}
	else
	{
		raise(SIGSEGV);
		exit(-1);
	}
	print_success();

	//Case-III : Insert third child of root
	test_case = 3;
	if(myTree->insertChild(new node<int,string>(4,"D"), 1))
	{
		node<int,string> *ptr = myTree->getRoot()->child;
		if(ptr->key!=4 && ptr->sibling->key!=4 && ptr->sibling->sibling->key!=4)
		{
			raise(SIGSEGV);
			exit(-1);
		}
	}
	else
	{
		raise(SIGSEGV);
		exit(-1);
	}
	print_success();

	//Case-IV : Insert child of first child of root
	test_case = 4;
	if(myTree->insertChild(new node<int,string>(5,"E"), 2))
	{
		node<int,string> *ptr = myTree->getRoot()->child;
		if((ptr->child!=NULL && ptr->child->key!=5)
			|| (ptr->sibling->child!=NULL && ptr->sibling->child->key!=5)
			|| (ptr->sibling->sibling->child!=NULL && ptr->sibling->sibling->child->key!=5))
		{
			raise(SIGSEGV);
			exit(-1);
		}
	}
	else
	{
		raise(SIGSEGV);
		exit(-1);
	}
	print_success();

	//Case-V : Insert child of last child of root
	test_case = 5;
	if(myTree->insertChild(new node<int,string>(6,"F"), 4))
	{
		node<int,string> *ptr = myTree->getRoot()->child;
		if((ptr->child!=NULL && ptr->child->key!=6 && ptr->child->key!=5)
			|| (ptr->sibling->child!=NULL && ptr->sibling->child->key!=6 && ptr->sibling->child->key!=5)
			|| (ptr->sibling->sibling->child!=NULL && ptr->sibling->sibling->child->key!=6 && ptr->sibling->sibling->child->key!=5))
		{
			raise(SIGSEGV);
			exit(-1);
		}
	}
	else
	{
		raise(SIGSEGV);
		exit(-1);
	}
	print_success();

	//Case-VI : Insert duplicate key
	test_case = 6;
	if(myTree->insertChild(new node<int,string>(6,"FF"), 3))
	{
		raise(SIGSEGV);
		exit(-1);
	}
	print_success();



	cout << "\n-----Testing search function-----\n";
	//Case-I : Search existing node
	test_case = 1;
	node<int,string> *ptr = myTree->findKey(5);
	if(ptr==NULL)
	{
		raise(SIGSEGV);
		exit(-1);
	}
	print_success();

	//Case-II : Search non-existent node
	test_case = 2;
	ptr = myTree->findKey(7);
	if(ptr!=NULL)
	{
		raise(SIGSEGV);
		exit(-1);
	}
	print_success();

	cout << "\n-----Testing height function-----\n";
	//Case-I : Find height of tree
	test_case = 1;
	if(myTree->findHeight()!=3)
	{
		raise(SIGSEGV);
		exit(-1);
	}
	print_success();


	cout << "\n-----Testing get all children function-----\n";
	//Case-I : Find children of root
	test_case = 1;
	vector<node<int,string>*> v1 = myTree->getAllChildren(1);
	vector<int> v2;
	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(4);
	if(!compare_vectors(v1,v2))
	{
		raise(SIGSEGV);
		exit(-1);
	}
	print_success();

	//Case-II : Find children of some node other than root
	test_case = 2;
	myTree->insertChild(new node<int,string>(7,"G"), 3);
	myTree->insertChild(new node<int,string>(8,"H"), 3);
	myTree->insertChild(new node<int,string>(9,"I"), 3);
	v1.clear();
	v1 = myTree->getAllChildren(3);
	v2.clear();
	v2.push_back(7);
	v2.push_back(8);
	v2.push_back(9);
	if(!compare_vectors(v1,v2))
	{
		raise(SIGSEGV);
		exit(-1);
	}
	print_success();

	//Case-III : Find children of node with no child
	test_case = 3;
	v1.clear();
	v1 = myTree->getAllChildren(8);
	v2.clear();
	if(!compare_vectors(v1,v2))
	{
		raise(SIGSEGV);
		exit(-1);
	}
	print_success();


	//Case-IV : Find children of non-existent node
	test_case = 4;
	v1.clear();
	v1 = myTree->getAllChildren(10);
	v2.clear();
	if(!compare_vectors(v1,v2))
	{
		raise(SIGSEGV);
		exit(-1);
	}
	print_success();



	cout << "\n-----Testing delete leaf node-----\n";
	//Case-I : Delete child with no sibling
	test_case = 1;
	if(myTree->deleteLeaf(5))
	{
		v1.clear();
		v1 = myTree->getAllChildren(2);
		v2.clear();
		if(!compare_vectors(v1,v2))
		{
			raise(SIGSEGV);
			exit(-1);
		}
	}
	else
	{
		raise(SIGSEGV);
		exit(-1);
	}
	print_success();

	//Case-II : Delete parent of deleted node which is now itself a leaf node
	test_case = 2;
	if(myTree->deleteLeaf(2))
	{
		v1.clear();
		v1 = myTree->getAllChildren(1);
		v2.clear();
		v2.push_back(3);
		v2.push_back(4);
		if(!compare_vectors(v1,v2))
		{

			raise(SIGSEGV);
			exit(-1);
		}
	}
	else
	{
		raise(SIGSEGV);
		exit(-1);
	}
	print_success();

	//Case-III : Delete non-leaf node
	test_case = 3;
	if(myTree->deleteLeaf(3))
	{
		raise(SIGSEGV);
		exit(-1);
	}
	print_success();

	//Case-IV : Delete complete tree and try deleting root
	test_case = 4;
	myTree->deleteLeaf(7);
	myTree->deleteLeaf(8);
	myTree->deleteLeaf(9);
	myTree->deleteLeaf(3);
	myTree->deleteLeaf(6);
	myTree->deleteLeaf(4);
	if(myTree->deleteLeaf(1))
	{
		raise(SIGSEGV);
		exit(-1);
	}
	print_success();


	return 0;
}

void signal_handler(int signum)
{
	cout << "Test # " << test_case << " failed!\n";
}

void print_success()
{
	cout << "Test # " << test_case << " passed!\n";
}


bool compare_vectors(vector<node<int,string>*> v1, vector<int> v2)
{
	if(v1.size()!=v2.size())
		return false;

	for(int i=0; i<v1.size(); i++)
	{
		bool isFound = false;
		for(int j=0; j<v2.size(); j++)
		{
			if(v1[i]->key==v2[j])
			{
				isFound = true;
				continue;
			}
		}
		if(!isFound)
			return false;
	}
	return true;
}
