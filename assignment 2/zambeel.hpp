#ifndef __ZAMBEEL_HPP
#define __ZAMBEEL_HPP

#include "avl.hpp"

class Zambeel {

	AVL<int,int> *myTree;
public:
	Zambeel(bool isAVL);
	bool istAddCourse(int course_id);
	bool istDropCourse(int course_id);
	void istCleanEnrollment();
	bool stuAddCourse(int course_id);
	bool stuDropCourse(int course_id);
	bool stuSwapCourse(int course1_id, int course2_id);
	~Zambeel();
};

#endif
