#include "linklib.hpp"

int List::length() {
	if (head==nullptr) {
		return 0;
	}
	//returns length=0 if empty
	else {
		return head->length();
	}
	//computes length from head of list
};
int Node::length() {
	if (!next) {
		return 1;
	}
	//if no next, length is 1
	return (1+next->length());
	//returns 1 + length of following nodes
};
int List::length_iterative() {
	int count = 0;
	if (head!=nullptr) {
		//if there is a head it runs this if
		auto current_node = head;
		count=1;
		while (current_node->has_next()) {
			current_node = current_node->nextnode(); 
			count += 1;
			//increases count when there's a next node
		}
	}
	return count;
};
Node& List::headnode() {
	if (!head) {
		throw(1);
		//throws if head is empty
	}
	return *head;
	//returns pointer to head
};
Node& List::nth_node(int n) {
	if (n<0){
		throw(1);
	}
	if (!head){
		throw(1);
	}
	//test cases to throw if head empty or n negative
	return head->nth_node(n);
	//returns the nth node
};
Node& Node::nth_node(int n) {
	if (n<0){
		throw(1);
	}
	if (!next) {
		throw(1);
	}
	//two test cases to throw if n is negative, or there's no next node
	if (n==0) {
		return *this;
	}
	//returns current node
	return next->nth_node(n - 1);
	//returns the nth node
};
bool List::contains_value(int v) {
	if (head == nullptr) {
		return false;
	}
	//if no head returns false
	else {
		return head->contains_value(v);
	}
	//checks values and returns true if v is in the values
};
bool Node::contains_value(int v) {
	if (datavalue == v){
		return true;
	}
	//tests if first value is v
	if (!next) {
		return false;
	}
	return next->contains_value(v);
	//tests if v is in following values
};
bool List::is_sorted() {
	if (head == nullptr){
		return true;
	}
	//empty list is sorted
	return head->is_sorted();
	//checks if list is sorted
};
bool Node::is_sorted() {
	if (!next){
		return true;
	}
	//returns true if no next bc only one value is sorted
	if (datavalue > next->value()) {
		return false;
	}
	//if value is more than next value, returns false
	return next->is_sorted();
	//checks rest
};
std::string List::as_string() {
	if (head == nullptr){
		return ("[]");
	}
	//empty list returns empty brackets
	std::ostringstream out;
	out << "[" << head->as_string() << "]";
	//uses ostringstream to return string
	return out.str();
};
std::string Node::as_string() {
	std::ostringstream out;
	out<<datavalue;
	//first value to string
	if (next) {
		out << "," << next->as_string();
	}
	//adds following values to string
	return out.str();
};
