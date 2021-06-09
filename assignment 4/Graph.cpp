#ifndef GRAPH__CPP
#define GRAPH__CPP
#include "Graph.h"
#include <fstream>
#include <list>
#include <cstring>
#include <string>
#include <vector>
#include <sstream> 
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <sstream> 
#include <set> 
#include <iterator> 

using namespace std ;

int str_to_int(string str) // converts numbers from string datat type to integer data type
{
	stringstream temp(str); 
    int integer = 0; 
    temp >> integer ;
	return integer ; 
}

bool operator == (Node a, Node b)
{
	if (a.value == b.value)
	{
		return true ;
	}

	return false ;
}

bool operator < (Node a, Node b)
{
	if (a.value < b.value)
	{
		return true ;
	}

	return false ;
}

bool operator > (Node a, Node b)
{
	if (a.value < b.value)
	{
		return true ;
	}

	return false ;
}

Graph::Graph(string file)
{
	ifstream fin(file) ;
	ifstream fin2(file) ;

	// Reading n and c
    string trash, nodes ;
	string trash2, conn ;
    fin >> trash >> nodes ; 
	fin >> trash2 >> conn ;

	// Ignore these 4 lines
	string trash3, nodes2 ;
	string trash4, conn2 ;
    fin2 >> trash3 >> nodes2 ; 
	fin2 >> trash4 >> conn2 ;

	// Converting n and c to integers
	int connections = str_to_int(conn) ;
	size = str_to_int(nodes) ;

	// Reading connections and weights line by line
	string line ;
	char start, end ;
	int weight ;
	int c = 0 ; // connections tracker while file reading
	while (getline(fin , line))
	{
		fin >> start >> end >> weight ;

		Node *o = new Node(start, false) ;
		Node *d = new Node(end, false) ;
		node_verts.insert(o) ;
		node_verts.insert(d) ;
		
		// addEdge(start, end, weight) ;
		c++ ;
		if (c == connections)
			break ;
	}

	fin.close() ;

	for (auto it=node_verts.begin(); it != node_verts.end(); ++it) 
	{
		Node *temp = *it ; 
		people.push_back(temp) ;
	}   

	string line2 ;
	char start2, end2 ;
	int weight2 ;
	int c2 = 0 ; // connections tracker while file reading

	while (getline(fin2 , line2))
	{
		fin2 >> start2 >> end2 >> weight2 ;
		
		addEdge(start2, end2, weight2) ;
		c2++ ;
		if (c2 == connections)
			break ;
	}

	fin2.close() ;
}

void Graph::addEdge(char start, char end, int weight)
{
	// Adding vertices to set
	verts.insert(start) ;
	verts.insert(end) ;

	Node *get_origin ;
	for (int i = 0; i < people.size(); i++)
	{
		if (people[i]->value == start)
		{
			get_origin = people[i] ;
			goto jump ;
		}
	}

	jump : Node *node_origin = get_origin ;

	Node *get_dest ;
	for (int i = 0; i < people.size(); i++)
	{
		if (people[i]->value == end)
		{
			get_dest = people[i] ;
			goto jump2 ;
		}
	}

	jump2 : Node *node_dest = get_dest ;

	Edge edge_origin ; 
	edge_origin.origin = node_origin ;
	edge_origin.dest = node_dest ;
	edge_origin.weight = weight ;

	Edge edge_dest ; 
	edge_dest.origin = node_dest ;
	edge_dest.dest = node_origin ;
	edge_origin.weight = weight ;

	arcs.push_back(edge_origin) ;

	node_origin -> edges.push_back(edge_origin) ;
	node_dest -> edges.push_back(edge_dest) ;
}

string Graph::display()
{
	string result = "" ;

	for (int i = 0 ; i < arcs.size() ; i++)
	{
		Edge temp = arcs[i] ;

		// Converting char to string 
		string str(1, temp.origin->value);
		string str2(1, temp.dest->value);	

		result = result + "(" + str + "," + str2 + "," + to_string(temp.weight) + ")" + " " ;
		result = result + "(" + str2 + "," + str + "," + to_string(temp.weight) + ")" + " " ;
	}

	return result ;
}

bool Graph::Reachable(char start, char end)
{
    bool found_start = false ;
    Node *start_node ;
    for (int i = 0 ; i < people.size() ; i++)
    {
        if (people[i] -> value == start)
        {
            start_node = people[i] ;
            found_start = true ;
            break ;
        }

        else
            continue ;
    }

    if (found_start == false)
    {
        return false ;
    }

    bool found_end = false ;
    Node *end_node ;
    for (int i = 0 ; i < people.size() ; i++)
    {
        if (people[i] -> value == end)
        {
            end_node = people[i] ;
            found_end = true ;
            break ;
        }

        else
            continue ;
    }

    if (found_end == false)
    {
        return false ;
    }

    if (start == end)  // Self loop or reached end
	{
		for (int i = 0 ; i < people.size() ; i++)
		{
			people[i] -> visited = false ;
		}

		return true ;
	}
        
    if (start_node -> visited == 1)  // returned back to initial position
        return false ;

    start_node -> visited = 1 ;
    int flag = 0 ;

    for (int i = 0 ; i < start_node -> edges.size() ; i++)
    {
        Node *temp = start_node -> edges[i].dest ;
        char new_start = temp -> value ;
        if (Reachable(new_start , end))
        {
            flag = 1 ;
            break ;
        }
    }

    if (flag == 1)
	{
		return true ;
	}
        
    else
	{
		return false ;
	}
}

int Graph::Prims()
{

	return 0 ;
}

int min_extractor(vector<set<Node*> >cloud, Node *temp)
{
	for (int i = 0 ; i < cloud.size() ; i++)
	{
		if (cloud[i].find(temp) != cloud[i].end())
		{
			return i ;
		}
	}

	return -1 ;
}

int Graph::Kruskal()
{
	for (int i = 0 ; i < people.size() ; i++)
        people[i] -> visited = 0 ;

    priority_queue <Edge, vector<Edge>, greater<Edge> > p_queue ;  

    for (int i = 0 ; i < arcs.size() ; i++)
        p_queue.push(arcs[i]) ;

    vector<set<Node*> >cloud ;

    for (int i = 0 ; i < people.size() ; i++)
	{
		set<Node*> temp ;
		temp.insert(people[i]) ;
		cloud.push_back(temp) ;
	}

	vector<Node*> result ;

	vector <Edge> spanning_edges ;

    while (p_queue.empty() == false)
    {
        Edge min_edge = p_queue.top() ;  // extract edge with minimum distance
        p_queue.pop() ;

        // Find index of Origin and Dest of min_edge
        int origin_index = min_extractor(cloud, min_edge.origin );
		int dest_index = min_extractor(cloud, min_edge.dest) ;

		if (origin_index != dest_index)
		{
			spanning_edges.push_back(min_edge) ;

			cloud[origin_index].insert(cloud[dest_index].begin(), cloud[dest_index].end()) ;
			cloud.erase(cloud.begin() + dest_index) ;
		}
    }

	float total_cost = 0 ;

    for (int i = 0 ; i < spanning_edges.size() ; i++)
    {
        total_cost = total_cost + spanning_edges[i].weight ;
    }

	return total_cost ;
}

int minimumindex(vector <Node*> temporary)
{
    int l = 0 ;
    float lowest_distance = temporary[0] -> distance ;

    for(int i = 1 ; i < temporary.size() ; i++)
    {
        if(lowest_distance > temporary[i] -> distance)
        {
            lowest_distance = temporary[i] -> distance ;
            l = i ;
        }
    }

    return l ;
}

float evaluatemindistance(vector <Node*> temporary)
{
    int lowest = 0 ;
    float lowest_distance = temporary[0] -> distance ;

    for(int i = 1 ; i < temporary.size() ; i++)
    {
        if(lowest_distance > temporary[i] -> distance)
        {
            lowest_distance = temporary[i] -> distance ;
            lowest = i ;
        }
    }
	

    return lowest_distance ;
}


int Graph::Dijkstra(char start, char dest)
{

	Node *start_node ; 
	Node *end_node ;
    bool start_found = false ;
    bool end_found = false ;

    for (int i = 0 ; i < people.size() ; i++)
    {
        if (people[i] -> value == start)
        {
            start_node = people[i] ;
            start_found = true ;
            break ;
        }
    }

    for (int i = 0 ; i < people.size() ; i++)
    {
        if (people[i] -> value == dest)
        {
            end_node = people[i] ;
            end_found = true ;
            break ;
        }
    }

    if(start_found == false)
    {
        return -1 ;
    }

    if(end_found == false)
    {
        return -1 ;
    }

	vector <Node*> temporary ;
    for (int i = 0 ; i < people.size() ; i++)
        temporary.push_back(people[i]) ;

	for (int i = 0 ; i < people.size() ; i++)
    {
        people[i] -> distance = 90000 ;
        people[i] -> visited = 0 ;
    }

	start_node -> distance = 0 ;

	while (temporary.size() > 0)
    {
        int min_index = minimumindex(temporary) ;
        float min_distance = evaluatemindistance(temporary) ;

        Node *min_index_node = temporary[min_index] ;
        temporary.erase(temporary.begin() + min_index) ;  

        min_index_node -> visited = 1 ;

        for(int i = 0 ; i < min_index_node -> edges.size() ; i++)
        {
            if(min_index_node -> edges[i].dest -> visited == 0)
            {
                float w = min_index_node -> edges[i].weight ;
                float update_distance = min_index_node -> distance + w ;

                if(min_index_node -> edges[i].dest -> distance > update_distance)
                {
                    min_index_node -> edges[i].dest -> distance = update_distance ;
                    min_index_node -> edges[i].dest -> prev = min_index_node ;
                }
            }
        }
    }

	if (end_node -> distance == 90000)
		return -1 ;

	else
		return end_node -> distance ;
}

bool operator < (Edge a, Edge b)
{
	if (a.weight < b.weight)
	{
		return true ;
	}

	return false ;
}

bool operator == (Edge a, Edge b)
{
	if (a.weight == b.weight)
	{
		return true ;
	}

	return false ;
}

bool operator > (Edge a, Edge b)
{
	if (a.weight > b.weight)
	{
		return true ;
	}

	return false ;
}

#endif
