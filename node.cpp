#include "node.hpp"

node::node() {
	operation = ADDITION;
	data = 0;
	total = 0;
	count = 0;
	next = nullptr;
	prev = nullptr;

}


node::node(FUNCTIONS op, double data, double total, int count) {
	operation = op;
	this->data = data;
	this->total = total;
	this->count = count;
	next = nullptr;
	prev = nullptr;
}