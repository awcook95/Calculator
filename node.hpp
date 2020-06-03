#ifndef NODE_H
#define NODE_H

#include "CalcListInterface.hpp"

class node { //the node class holds all data for each step in the list
public:
	node(); //default constructor that makes a starting node. the starting node is ignored when the list is printed
	node(FUNCTIONS op, double data, double total, int count); //constructor for additional nodes

private:
	friend class CalcList;

	FUNCTIONS operation;
	double data; //the operand
	double total; //the new total at the time the node is created
	int count; //each node is numbered
	node* next; //each node has a pointer to the previous node and the following node
	node* prev;

};

#endif