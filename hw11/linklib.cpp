#include "linklib.hpp"

int List::length() {
	
	if (head==nullptr) {
		return 0;
	}
	else {
		return head->length();
	}
};
int List::length_iterative() {
	//returns length by checking list
	int count = 0;
	if (head!=nullptr) {
		auto current_node = head;
		while (current_node->has_next()) {
			current_node = current_node->nextnode(); count += 1;
		}
	}
	return count;
};
int Node& List::headnode() {
	if (!head) {
		throw(1);
	}
	return *head;
};
int List::nth_node(int n) {
	if (n<0){
		throw(1);
	}
	if (n>list.length()){
		throw(1);
	}
	//test cases to throw
	return head->nth_node(n);
	//returns position n
};
int Node::nth_node(int n) {
	if (n<0){
		throw(1);
	}
	if (n==0) {
		return *this;
	}
	if (!next) {
		throw(1);
	}
	//three test cases to throw
	return next->nth_node(n - 1);
	//returns the n node
};
bool List::contains_value(int v) {
	if (head == nullptr) {
		return false;
	}
	else {
		return head->contains_value(v);
	}
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
	//checks
	return head->is_sorted();
};
bool Node::is_sorted() {
	if (!next){
		return true;
	}
	if (datavalue > next->value()) {
		return false;
	}
	return next->is_sorted();
};
std::string List::as_string() {
	if (head == nullptr){
		return ("[]");
	}
	std::ostringstream out;
	out << "[" << head->as_string() << "]";
	return out.str();
};
std::string Node::as_string() {
	std::ostringstream out;
	out<<datavalue;
	if (next) {
		out << "," << next->as_string();
	}
	return out.str();
};
