//DO NOT CHANGE ANYTHING IN THIS FILE

#include <iostream>
#include "Graph.cpp"
using namespace std;

int main()
{
	bool display_passed = true;

	Graph mygraph1("test1.txt");
	Graph mygraph2("test2.txt");
	Graph mygraph4("test4.txt");

	// testing display 1
	vector<string> display_check1 = {"(A,B,6)", "(A,C,7)", "(B,A,6)", "(B,C,3)", "(C,A,7)", "(C,B,3)", "(C,E,8)", "(D,E,2)", "(E,C,8)", "(E,D,2)"};
	stringstream ss1(mygraph1.display());
	vector<string> results1;
	do
	{
		string word;
		ss1 >> word;
		if (word != "")
			results1.push_back(word);
	} while (ss1);
	if (display_check1.size() != results1.size())
		display_passed = false;
	for (string str : display_check1)
	{
		if (std::find(results1.begin(), results1.end(), str) == results1.end())
			display_passed = false;
	}
	// testing display 2

	vector<string> display_check2 = {"(A,B,3)", "(A,C,2)", "(A,G,6)", "(B,A,3)", "(B,C,2)", "(B,D,1)", "(B,E,6)", "(C,A,2)", "(C,B,2)", "(C,D,3)", "(D,B,1)", "(D,C,3)", "(D,F,4)", "(E,B,6)", "(E,F,1)", "(F,D,4)", "(F,E,1)", "(F,G,2)", "(G,A,6)", "(G,F,2)"};
	stringstream ss2(mygraph2.display());
	vector<string> results2;
	do
	{
		string word;
		ss2 >> word;
		if (word != "")
			results2.push_back(word);
	} while (ss2);
	if (display_check2.size() != results2.size())
		display_passed = false;
	for (string str : display_check2)
	{
		if (std::find(results2.begin(), results2.end(), str) == results2.end())
			display_passed = false;
	}

	// testing display 4
	vector<string> display_check4 = {"(A,B,2)", "(A,C,7)", "(A,E,2)", "(B,A,2)", "(B,C,3)", "(C,A,7)", "(C,B,3)", "(C,E,1)", "(E,C,1)", "(D,F,2)", "(E,A,2)", "(F,D,2)"};
	stringstream ss4(mygraph4.display());
	vector<string> results4;
	do
	{
		string word;
		ss4 >> word;
		if (word != "")
			results4.push_back(word);
	} while (ss4);
	if (display_check4.size() != results4.size())
		display_passed = false;
	for (string str : display_check4)
	{
		if (std::find(results4.begin(), results4.end(), str) == results4.end())
			display_passed = false;
	}

	if (display_passed)
		cout << "Display Test Passed\n";
	else
		cout << "Display Test Failed\n";

	return 0;
}