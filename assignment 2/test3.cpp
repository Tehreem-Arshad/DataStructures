#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <signal.h>
#include "avl.hpp"
#include <queue>
using namespace std;

int total_values = 25;
int values[25] = {55,43,26,82,93,04,39,95,50,6,62,17,21,49,77,5,32,60,88,16,44,72,80,8,36};
int TreeAfterAddition[25] = {4,5,6,8,16,17,21,26,32,36,39,43,44,49,50,55,60,62,72,77,80,82,88,93,95};
int TreeAfterDeletion[21] = {5,8,16,17,21,26,32,36,39,44,49,50,55,60,62,72,77,80,88,93,95};

int indx=0;
int pts=0;
int step=0;

template<class T, class S>
void TraverseTree(node<T,S> *P,int test)
{
	if(P->left)
		TraverseTree(P->left,test);
	if(test == 1){
	if(P->key == TreeAfterAddition[indx])
		pts++;
	}
	else if(test == 2){
	if(P->key == TreeAfterDeletion[indx])
		pts++;
	}
	indx++;
	if(P->right)
		TraverseTree(P->right,test);

}

void test_addition()
{
	cout<<"Testing Addition\n";
	pts=0;
	indx=0;
	int success=1;
	AVL<int,string> B(true);
	for (int i=0;i<total_values;i++)
		B.insertNode(new node<int,string>(values[i],"abc"));

	step++;
	TraverseTree(B.getRoot(),1);
	if(pts < 25){
		cout<<"Addition: Order of nodes not okay!!!\n";
		success=0;
	}

	step++;
	pts = 0;
	node<int,string>* root = B.getRoot();

	if(root->key == 43){
		pts++;
	}
	if(root->right->key == 62){
		pts++;
	}
	if(root->left->key == 17){
		pts++;
	}
	if(root->left->left->left->key == 4){
		pts++;
	}
	if(root->left->right->right->key == 36){
		pts++;
	}
	if(root->right->left->right->key == 60){
		pts++;
	}
	if(root->right->right->right->right->key == 95){
		pts++;
	}
	if(root->left->left->right->left->key == 6){
		pts++;
	}
	if(pts < 8){
		cout<<"Addition: Structure of tree not okay!!!\n";
		success=0;
	}
	step++;
	if(success)
		cout<<"Addition Test Successful\n";
}

void test_deletion()
{
	cout<<"Testing Deletion\n";

	pts=0;
	indx=0;
	int success=1;
	AVL<int,string> B(true);
	for (int i=0;i<total_values;i++)
		B.insertNode(new node<int,string>(values[i],"abc"));

	for (int i=0;i<total_values;i++)
		B.deleteNode(values[i]);
	step++;


	for (int i=0;i<total_values;i++)
		B.insertNode(new node<int,string>(values[i],"abc"));

	B.deleteNode(6);
	B.deleteNode(82);
	B.deleteNode(4);
	B.deleteNode(43);
	TraverseTree(B.getRoot(),2);
	if(pts < (total_values-4)){
		cout<<"Deletion: Order of nodes not okay!!!\n";
		success=0;
	}
	step++;
	pts=0;
	node<int,string>* root = B.getRoot();
	//if(root->key == 39) for findmin() when deleting
	if(root->key == 44)
		pts++;
	if(root->right->key == 62)
		pts++;
	if(root->left->key == 17)
		pts++;
	if(root->left->left->left->key == 5)
		pts++;
	if(root->left->right->right->key == 36)
		pts++;
	if(root->right->left->right->key == 60)
		pts++;
	if(root->right->right->right->right->key == 95)
		pts++;
	if(root->left->left->right->left == NULL)
		pts++;
	if(pts < 8){
		cout<<"Deletion: Structure of tree not okay!!!\n";
		success=0;
	}
	step++;
	if(success)
		cout<<"Deletion Test Successful..\n";
}
void test_search()
{
	cout<<"Testing Search\n";
	pts=0;
	indx=0;
	int success=1;
	AVL <int,string> B(true);
	for (int i=0;i<total_values;i++)
		B.insertNode(new node<int,string>(values[i],"abc"));
	for (int i=0;i<total_values;i++){
		if (B.searchNode(values[i])->key == values[i])
			pts++;
	}
	if(pts < 25){
		cout<<"Search: Value returned is not okay!!!\n";
		success=0;
	}
	step++;
	pts=0;

	if(B.searchNode(100) == NULL)
		pts++;
	if(B.searchNode(1) == NULL)
		pts++;
	if(B.searchNode(99) == NULL)
		pts++;
	if(B.searchNode(40) == NULL)
		pts++;
	if(pts < 4){
		cout<<"Search: Non Existing values found!!!\n";
		success=0;
	}
	step++;
	if(success)
		cout<<"Search Test Successful..\n";
}
void testcases()
{
	test_addition();
	test_search();
	test_deletion();

}
void signal_handler(int signum)
{
	if(step == 2)
		cout<<"Addition: Structure of Tree is not okay..\n";
	if(step == 3)
		cout<<"Search: Existing value not found..\n";
	if(step == 5)
		cout<<"Deletion: Error while deleting value..\n";
	if(step == 7)
		cout<<"Deletion: Structure of tree not okay after deletion..\n";

    	cout << " Failed! \n";


    	signal(SIGSEGV, signal_handler);
    	signal(SIGFPE, signal_handler);
	cout<<"Exiting...\n";
	//system("PAUSE");
	exit(1);
}
int main()
{
	signal(SIGSEGV, signal_handler);
	signal(SIGFPE, signal_handler);
	cout<<"Test Cases Started!!!!\n";
	testcases();
}
