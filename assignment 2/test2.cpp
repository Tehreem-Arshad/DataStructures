#include "avl.hpp"
#include <vector>

using namespace std;


void test_insert(AVL<int,string>* tree);
int trav(node<int,string> *P,int i);
vector<int> find_delete(int k,vector<int> v);
void test_delete(AVL<int,string>* tree);
void test_search(AVL<int,string>* tree);
void test_replace(AVL<int,string>* tree);
void test_height(AVL<int,string>* tree);
vector<int> test_vec;
vector<int> ref_vec;
int main()
{
	AVL<int,string>* tree=new AVL<int,string>(false);
//------------------------
	tree->insertNode(new node<int,string>(34,"a"));
	tree->insertNode(new node<int,string>(7,"b"));
	tree->insertNode(new node<int,string>(53,"c"));
	tree->insertNode(new node<int,string>(12,"d"));
	tree->insertNode(new node<int,string>(68,"e"));
	tree->insertNode(new node<int,string>(90,"f"));
	tree->insertNode(new node<int,string>(24,"g"));
	tree->insertNode(new node<int,string>(71,"h"));
	tree->insertNode(new node<int,string>(13,"i"));
	tree->insertNode(new node<int,string>(3,"j"));
	tree->insertNode(new node<int,string>(1,"k"));
	tree->insertNode(new node<int,string>(61,"l"));
	tree->insertNode(new node<int,string>(18,"m"));
	tree->insertNode(new node<int,string>(30,"n"));
	tree->insertNode(new node<int,string>(50,"o"));
	tree->insertNode(new node<int,string>(4,"p"));
	tree->insertNode(new node<int,string>(11,"q"));
	tree->insertNode(new node<int,string>(52,"r"));
	tree->insertNode(new node<int,string>(54,"r"));
	tree->insertNode(new node<int,string>(56,"r"));
	tree->insertNode(new node<int,string>(55,"r"));
	tree->insertNode(new node<int,string>(80,"r"));
//--
//--
//---------------------------------------------------------
	ref_vec.push_back(1);
	ref_vec.push_back(3);
	ref_vec.push_back(4);
	ref_vec.push_back(7);
	ref_vec.push_back(11);
	ref_vec.push_back(12);
	ref_vec.push_back(13);
	ref_vec.push_back(18);
	ref_vec.push_back(24);
	ref_vec.push_back(30);
	ref_vec.push_back(34);
	ref_vec.push_back(50);
	ref_vec.push_back(52);
	ref_vec.push_back(53);
	ref_vec.push_back(54);
	ref_vec.push_back(55);
	ref_vec.push_back(56);
	ref_vec.push_back(61);
	ref_vec.push_back(68);
	ref_vec.push_back(71);
	ref_vec.push_back(80);
	ref_vec.push_back(90);
//-----------------------------------------------------------

	cout<< endl<<endl<<"Testing Binary Search Tree (AVL without balancing)"<<endl<<endl;
	test_insert(tree);
	test_search(tree);
	test_delete(tree);
	//test_replace(tree);
	test_height(tree);
	return 0;
}

void test_insert(AVL<int,string>* tree)
{
	cout<<"Testing Insert function.."<<endl;
	test_vec.clear();
	int counter=0;
	int a=trav(tree->getRoot(),0);
	for (int i=0;i<test_vec.size();i++)
	{
		if (test_vec[i]==ref_vec[i])
		{
			counter++;
		}

	}
	cout<<"Total points:: "<<(counter/ref_vec.size())*10<<"/10"<<endl<<endl;
	return;

}
void test_delete(AVL<int,string>* tree)
{
	cout<<"Testing delete function.."<<endl;
	test_vec.clear();
	tree->deleteNode(90);
	tree->deleteNode(18);
	tree->deleteNode(50);
	tree->deleteNode(24);
	tree->deleteNode(68);
	tree->deleteNode(54);
	ref_vec=find_delete(90,ref_vec);
	ref_vec=find_delete(18,ref_vec);
	ref_vec=find_delete(50,ref_vec);
	ref_vec=find_delete(24,ref_vec);
	ref_vec=find_delete(68,ref_vec);
	ref_vec=find_delete(54,ref_vec);
	//for (int j=0;j<ref_vec.size();j++)
		//cout<<ref_vec[j]<<" ref"<<endl;

	int counter=0;
	int a=trav(tree->getRoot(),0);
	//tree->Traverse(tree->getroot());
	for (int i=0;i<test_vec.size();i++)
	{
		if (test_vec[i]==ref_vec[i])
		{
			counter++;
		}

	}

	cout<<"Total points:: "<<(counter/ref_vec.size())*10<<"/10"<<endl<<endl;
	return;


}
void test_search(AVL<int,string>* tree)
{
	cout<< "Testing Search Function.."<<endl;
	vector<int> ref_search;
	int counter=0;
	test_vec.clear();
	test_vec.push_back(tree->searchNode(13)->key);
	test_vec.push_back(tree->searchNode(11)->key);
	test_vec.push_back(tree->searchNode(52)->key);
	test_vec.push_back(tree->searchNode(90)->key);
	test_vec.push_back(tree->searchNode(24)->key);
	ref_search.push_back(13);
	ref_search.push_back(11);
	ref_search.push_back(52);
	ref_search.push_back(90);
	ref_search.push_back(24);
	for (int i=0;i<test_vec.size();i++)
	{
		if (test_vec[i]==ref_search[i])
		{
			counter++;
		}

	}
	cout<<"Total points:: "<<(counter/ref_search.size())*10<<"/10"<<endl<<endl;
	return;
}

void test_height(AVL<int,string>* tree)
{
	cout<<"Testing Height Function.."<<endl;
	test_vec.clear();
	int counter=0;
	int h=tree->height(tree->getRoot());

	if (h==6)
		counter=1;
	else
		counter=0;
	cout<< "Total Points:: "<<counter*5<<"/5"<<endl;
}
int trav(node<int,string> *P,int i)
{
	if(P->left)
		i=trav(P->left,i);
	test_vec.push_back(P->key);
	i++;
	if(P->right)
		i=trav(P->right,i);
	return i;

}
vector<int> find_delete(int k,vector<int> v)
{
	for (int i=0;i<v.size();i++)
	{
		if (v.at(i)==k)
		{
			v.erase(v.begin()+i);
			return v;
		}
	}
}
