#ifndef CALCLIST_H
#define CALCLIST_H

#include "CalcListInterface.hpp"
#include "node.hpp"
#include <string>

class CalcList : public CalcListInterface { //The CalcList class manages a list of nodes
public:
	CalcList(); //default constructor
	double total() const { return tail->total; };
	void addNode(FUNCTIONS func, double operand, double newTotal, int count);
	void newOperation(const FUNCTIONS func, const double operand);
	void removeLastOperation(); //removes last operation in the list
	std::string toString(unsigned short precision) const; //returns a formatted string of every calculation in the list
	std::string optoString(FUNCTIONS op) const; //converts a FUNCTIONS enum to string

private:
	node* head;
	node* tail;

};


#endif