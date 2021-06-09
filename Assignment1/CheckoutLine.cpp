#ifndef CheckoutLine_CPP
#define CheckoutLine_CPP
#include "CheckoutLine.h"

//base constructor, init
CheckoutLine::CheckoutLine(int size)
{
	time = 0;
	line_size = size;
}

//destructor
CheckoutLine::~CheckoutLine()
{
	line_size = 0;
}

// join the checkout line
// impliment for both waiting systems
bool CheckoutLine::joinCheckoutLine(string name, int line_number, int type)
{

	if (line_number == 1 && container1.length() < line_size)
	{
		person_node newPerson(name, ++this->time, 0);
		container1.enqueue(newPerson);
		return true;

	}
	else if (line_number == 2 && container2.length() < line_size)
	{
		//  person_node obj ;
		person_node newPerson(name, ++this->time, 0);
		container2.enqueue(newPerson);
		return true;


	}
	else
		return false;
}

// impliment serving strategy for both waiting systems
void CheckoutLine::serveCheckoutLine(int type)
{
	if (type == 1)
	{
		int w1 = 9999, w2 = 9999, i=0;
		while (!container1.isEmpty() || !container2.isEmpty()) {

			w1 = 9999; w2 = 9999;
			if(!container1.isEmpty())
				w1 = container1.front().wait_stamp;
			if (!container2.isEmpty())
				w2 = container2.front().wait_stamp;
			if (w1 < w2) {
				container.push(container1.dequeue());
			}
			else if(w2 < w1) {
				container.push(container2.dequeue());
			}
		}
	}
	else if (type == 2)
	{
		person_node temp;
		for (int i = 0; i < line_size; i++)
		{
			if (!container1.isEmpty()) {
				temp = container1.dequeue();
				temp.time_stamp = container.length() + 1;
				container.push(temp);
			}
			if (!container2.isEmpty()){
				temp = container2.dequeue();
				temp.time_stamp = container.length() + 1;
				container.push(temp);
			}
		}
	}

}

// return a vector of strings with the names of last n people served
vector<string> CheckoutLine::history(int n)
{
	vector<string> array;
	Stack<person_node> temp;
	for (int i = 0; i < n; i++) {
		array.insert(array.begin(), container.top().name);
		temp.push(container.pop());
	}
	for (int i = 0; i < n; i++) {
		container.push(temp.pop());
	}
	return array;
}

#endif
