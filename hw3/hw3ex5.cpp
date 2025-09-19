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

int main(){
        int n = 3;
        auto f = [n](double x) -> double {return x*x-n;};
        auto fprime = [](double x) -> double {return 2*x;};
	for (float n=2. ; n<10 ; n+=.5){
		auto f = [n] (double x){return x*x-n;};
		cout << "sqrt " << n << " = " << newton_root(f,fprime) << endl;
	}
	return 0;
}
