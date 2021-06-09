#ifndef GRAPH__H
#define GRAPH__H
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include <limits>
#include <set>
#include <algorithm>
#include <queue>
#include <list>
#include <sstream>
#include <set> 
#include <iterator> 

using namespace std;

class Edge ;

class Node
{
	public:
		char value ;
		bool visited ;
		float distance ;
		Node *prev ;

		vector <Edge> edges ; // edges connected to node

		friend bool operator == (Node a, Node b) ;
		friend bool operator < (Node a, Node b) ;
		friend bool operator > (Node a, Node b) ;
		
		Node(char ch, bool vis)
		{
			value = ch ;
			visited = vis ;
		}

		Node()
		{

		}
} ;

class Edge
{
public:
	Node *origin;
	Node *dest;
	int weight;

	friend bool operator < (Edge a, Edge b);
	friend bool operator == (Edge a, Edge b);
	friend bool operator > (Edge a, Edge b);

	Edge()
	{

	}
};

class Graph
{
	
public:
	list <Edge*> graph ; // adjacency list representation

	set <char> verts ; // to store vertices 
	set <Node*> node_verts ; // vertices in 'Node' form
	vector <Node*> people ;
	vector <Edge> arcs;

	int size = 0;
	Graph(string filename);

	void addEdge(char start, char end, int weight);
	string display(); // displays the graph
	bool Reachable(char start, char dest);
	int Prims();
	int Kruskal(); //runs kruskal algorithm and returns the Minimum spanning tree weight
	int Dijkstra(char start, char dest);
} ;

#endif
