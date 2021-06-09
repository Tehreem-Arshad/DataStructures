#ifndef CheckoutLine_H
#define CheckoutLine_H
#include <fstream>
#include <vector>
#include <string>
#include "stack.cpp"
#include "queue.cpp"

using namespace std;

// A person_node contains their name, how long they have been waiting (wait_time) as well as when they were served (time_stamp).
struct person_node{
	string name;
	int wait_stamp;
	int time_stamp;
	person_node(){
		name = "";
		wait_stamp=0;
		time_stamp=0;
	}
	person_node (string n, int w, int t){
		name = n;
		wait_stamp = w;
		time_stamp = t;
	}
};

// The checkout line system will have a container to store the different checkout lines and to store history, you have to make choice between stack or queue.
// Also argue in favour of your choice of container.
class CheckoutLine{
public:
	// Containers
	// Make three containers: two for the checkout lines and one to store serving history
	// decide between:
    Stack<person_node> container;
	Queue<person_node> container1;
	Queue<person_node> container2;

	int time;
	int line_size;
	// Base constructor
	CheckoutLine(int size);
	//Destructor
	~CheckoutLine();
	//Functionalities
	bool joinCheckoutLine(string name, int line_number, int type);
	void serveCheckoutLine(int type);
	vector<string> history(int n);
};

#endif
