#include <iostream>
#include "avl.hpp"
#include <stack>
#include<ctime>
#include "zambeel.hpp"
using namespace std;

Zambeel::Zambeel(bool isAVL) {

	myTree = new AVL<int,int>(isAVL);
}

Zambeel::~Zambeel() {

	delete myTree;
}

bool Zambeel::istAddCourse(int course_id) {
	myTree->insertNode(new node <int,int>(course_id,0)) ;
	return true;
}

bool Zambeel::istDropCourse(int course_id) {
	myTree->deleteNode(course_id);

	return true;
}

void Zambeel::istCleanEnrollment() {
	stack <node<int,int>*> s1;
	node<int,int>* currNode = myTree->getRoot();
	while (currNode!=NULL || !s1.empty())
	{
		while (currNode!=NULL)
		{
			s1.push(currNode);
			currNode = currNode->left;
		}
		currNode = s1.top();
		s1.pop();
		currNode->value =0;
		currNode=currNode->right;
	}

	return;
}

bool Zambeel::stuAddCourse(int course_id) {

	if (myTree->searchNode(course_id)==NULL)
	return false;
	myTree->searchNode (course_id)->value = myTree->searchNode(course_id)->value+1;
	return true;
}

bool Zambeel::stuDropCourse(int course_id) {

	if(!myTree->searchNode(course_id) || myTree->searchNode(course_id)->value==0)
	return false;
	myTree->searchNode(course_id)->value = myTree->searchNode(course_id)->value-1;
	return true;
}

bool Zambeel::stuSwapCourse(int course1_id, int course2_id) {
	if (!myTree->searchNode(course1_id) || !myTree->searchNode(course2_id) || myTree->searchNode(course2_id)->value==0)
	return false;
	myTree->searchNode(course1_id)->value =myTree->searchNode(course1_id)->value+1;
	myTree->searchNode(course2_id)->value =myTree->searchNode(course2_id)->value-1;
	return true;
}


int main()
{
	srand(time(NULL)) ;
	int r = (rand()%400+1-200)+200;
	cout << "0. BST\n" ;
	cout << "1. AVL\n" ;
	int choice ;
	cout << "Enter choice: " ;
	cin >> choice ;
	Zambeel course(1) ;
	if (choice ==0 || choice ==1)
	{
		cout << "Enter scenario (1,2 or 3): " ;
		int choice1;
		cin >> choice1;
		if (choice1==1)
		{
			course.istAddCourse(202);
			course.istAddCourse(205);
			course.istAddCourse(215);
			course.istAddCourse(225);
			course.istAddCourse(274);
			course.istAddCourse(288);
			course.istAddCourse(307);
			course.istAddCourse(345);
			course.istAddCourse(390);
			course.istAddCourse(385);
			for (int i=0; i <100 ; i++)
			{
			    int add = rand() % (400+1-200)+200;
                course.stuAddCourse(add) ;
			}
			for (int i=0; i <100 ; i++)
			{
			    int add = rand() % (400+1-200)+200;
                course.stuDropCourse(add) ;
			}
			for (int i=0; i <100 ; i++)
			{
			    int add = rand() % (400+1-200)+200;
			    int sw = rand() % (400+1-200)+200;
				course.stuSwapCourse(add,sw) ;
			}

		}
		else if (choice1==2)
		{

            course.istAddCourse(300);
			course.istAddCourse(250);
			course.istAddCourse(350);
			course.istAddCourse(244);
			course.istAddCourse(277);
			course.istAddCourse(202);
			course.istAddCourse(340);
			course.istAddCourse(360);
			course.istAddCourse(325);
			course.istAddCourse(345);

			for (int i=0; i <100 ; i++)
			{
			    int add = rand() % (400+1-200)+200;
				course.stuAddCourse(add) ;
			}
			for (int i=0; i <100 ; i++)
			{
			    int add = rand() % (400+1-200)+200;
				course.stuDropCourse(add) ;
			}
			for (int i=0; i <100 ; i++)
			{
			    int add = rand() % (400+1-200)+200;
			    int sw = rand() % (400+1-200)+200;
				course.stuSwapCourse(add,sw) ;
			}

		}
		else if (choice1==3)
		{
		for (int i =0; i <10; i++)
			{
				course.istAddCourse(r);
			}
			for (int i=0; i <100 ; i++)
			{
                int add = rand() % (400+1-200)+200;
				course.stuAddCourse(add) ;
			}
			for (int i=0; i <100 ; i++)
			{
                int add = rand() % (400+1-200)+200;
				course.stuDropCourse(add) ;
			}
			for (int i=0; i <100 ; i++)
			{
                int add = rand() % (400+1-200)+200;
			    int sw = rand() % (400+1-200)+200;
				course.stuSwapCourse(add,sw) ;
			}

		}
		else
             cout <<"\nWrong input" ;
	}
	else
        cout <<"\nWrong input" ;


	return 0;
}
