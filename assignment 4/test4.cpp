//DO NOT CHANGE ANYTHING IN THIS FILE

#include <iostream>
#include "Graph.cpp"
using namespace std;

int main()
{
    bool kruskal_passed = true;
    bool prims_passed = true;

    Graph mygraph1("test1.txt");
    Graph mygraph2("test2.txt");

    if (mygraph1.Kruskal() != 19)
        kruskal_passed = false;

    if (mygraph2.Kruskal() != 12)
        kruskal_passed = false;

    if (mygraph1.Prims() != 19)
        prims_passed = false;

    if (mygraph2.Prims() != 12)
        prims_passed = false;

    if (kruskal_passed)
        cout << "(OPTION 1) Kruskal Passed\n";
    else
        cout << "(OPTION 1) Kruskal Failed\n";

    if (prims_passed)
        cout << "(OPTION 2) Prims Passed\n";
    else
        cout << "(OPTION 2) Prims Failed\n";
    cout << "Either option passing gives you full marks\n";
    return 0;
}