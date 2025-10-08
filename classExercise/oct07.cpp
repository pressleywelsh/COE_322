#include <iostream>
#include <vector>
#include <string>
#include <print>
using namespace std;
class named_vector {
private: 
	string name;
	vector<float> values;
public:
	named_vector(string name, int n)
		: name(name),
		values(vector<float>(n)){
		};
	float& operator [] (int i) {
		return values[i];
	};
};
int main(){
	named_vector things("thing vector", 50);
	things[0]=5.f;
	println("{}", things[0]);
	return 0;
}
