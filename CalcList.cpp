#include "CalcList.hpp"
#include <sstream>
#include <iomanip>

//constructor that creates an empty head and tail
CalcList::CalcList()
{
	head = new node();
	tail = head;
};

void CalcList::addNode(FUNCTIONS func, double operand, double newTotal, int count){
	//dynamically allocating new node pointer
	node *temp = new node(func, operand, newTotal, count);

	//setting the tail to point to the new node, and setting the new node as the new tail
	temp->prev = tail;
	tail->next = temp;

	tail = temp;
}

//newOperation takes the function and the operand and adds a new node to the list
void CalcList::newOperation(const FUNCTIONS func, const double operand)
{
	double newTotal = 0.0;
	int count = tail->count + 1;
	switch (func) { //determines which operation and updates the variable
	case ADDITION: newTotal = tail->total + operand;
		break;
	case SUBTRACTION: newTotal = tail->total - operand;
		break;
	case MULTIPLICATION:
		newTotal = tail->total * operand;
		break;
	case DIVISION:
		if (operand == 0) { throw "Cannot divide by zero"; }
		newTotal = tail->total / operand;
		break;
	}
	//now that the switch processed the input, the new node can be added
	addNode(func, operand, newTotal, count);
}

void CalcList::removeLastOperation()
{
	if(tail->count == 0){ //if the count is 0, the list only contains the empty starting node which cannot be removed
		throw "list empty, no operation to remove";
		return;}
	
	node* temp = tail->prev;
	tail = temp;
	tail->next = nullptr;
}

//function to convert FUNCTIONS enum to string format
std::string CalcList::optoString(FUNCTIONS op) const {
	switch (op)
	{
	case ADDITION: return "+";
	case SUBTRACTION: return "-";
	case MULTIPLICATION: return "*";
	case DIVISION: return "/";
	default: return "TYPE_ERROR";

	}
}

std::string CalcList::toString(unsigned short precision) const
{
	node* it = tail; //iterator to navigate linked list
	std::ostringstream oss; //stringstream to build the string that gets returned

	while (it->prev != nullptr) {
		oss << std::fixed << std::showpoint;
		oss << it->count << ": " << std::setprecision(precision) << it->prev->total << optoString(it->operation) << it->data << "=" << it->total << std::endl;

		it = it->prev;
	}

	std::string foutput = oss.str();
	return foutput;
	

}