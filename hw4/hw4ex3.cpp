#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;
template <class NormCallable>
void normalize(vector <float> &x, NormCallable norm_function){
        float length = norm_function(x);
	for (int i=0; i<x.size() ; i++){
                x[i]=x[i]/length;
        }
}
int main(){
	vector <float> x = {3.0f, 4.0f};
	cout<<"enter p value over 1: "<<endl;
	float p;
	cin>>p;
	auto norm_function=[p](vector<float> vec) ->float{
		float sum = 0.0;
		for (auto i : vec){
			sum+=pow(fabsf(i),p);
		}
		return powf(sum,(1.0f/p));
	};
        normalize(x,norm_function);
	cout << "x after normalized: " << endl;
        for (int i=0 ; i<x.size() ; i++){
                cout << x[i] << " ";
        }
        cout << endl;
}
