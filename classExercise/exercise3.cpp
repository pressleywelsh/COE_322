#include <iostream>
#include <cmath>
using namespace std;
float f(float x){
	return pow(x,2)-2;
}
float deriv(float x){
	return 2*x;
}
int main(){
	float result=0.;
	float x = 10.;
	while (std::abs(x)>=pow(10,-5)){
		x=x-((f(x))/deriv(x));
		cout<<x<<" "<< f(x)<<endl;
	}
	return 0;
}

