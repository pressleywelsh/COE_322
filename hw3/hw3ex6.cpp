#include <iostream> 
#include <functional> 
#include <cmath> 
using namespace std; 

double newton_root (function<double(double)> f, function<double(double)>fprime){ 
	double x=1.0; 
	double fx=f(x); 
	while (std::abs(fx)>1.e-5){ 
		double dfx = fprime(x); 
		if (dfx==0.0){ 
			break; 
		} 
		x=x-(fx/dfx); 
		fx=f(x); 
	} 
	return x; 
}

double newton_root (function < double(double)> f){
	double h=1e-6;
	auto grad = [f,h] (double x){
		return (f(x+h)-f(x-h))/(2.0*h);};
	return newton_root(f,grad);
}
int main(){
	int n = 3; 
	auto f = [n](double x) -> double {return x*x-n;}; 
	double root = newton_root(f); 
	cout<<"root is "<< root<<endl; return 0; 
}
