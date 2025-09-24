#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
float norm(vector<float> &x){
	float sum = 0.0;
	for (auto i : x){
		sum+=pow(i,2);
	}
	return sqrt(sum);
}
void normalize(vector <float> &x){
	float length = norm(x);
	for (int i=0; i<x.size() ; i++){
		x[i]=x[i]/length;
	}
}
int main(){
	vector<float> x = {3.0f,4.0f};
	cout << norm(x)<<endl;
	normalize(x);
	for (int i=0 ; i<x.size() ; i++){
		cout << x[i] << " ";
	}
	cout << endl;
}
