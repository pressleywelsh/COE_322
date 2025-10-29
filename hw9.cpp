#include <iostream>
using namespace std;
//power function computes (1 + 1/n)^n it computes the exponent with a loop instead of pow
float power(unsigned long long n){
	float base = (1.0f + (1.0f/n));
	float result = 1.0f;
	//for loop to compute exponent
	for (int i=1; i<=n; i++){
		result=base*result;
	}
	//returns (1 + 1/n)^n
	return result;
}

int main(){
	//unsigned long long to fit big n values like 10^10
	unsigned long long n= 1;
	float approx;
	//loop to compute limit for k=1-10, k is used for n=10^k
	for (int k=1; k<=10;k++){
		for (int j=1;j<=k; j++){
			n=n*10;
		}

		approx = power(n);
		n=1;
		cout<<"when k=" << k << " the approx is " << approx << endl;
		//when printed it has problem of approaching e then going to 1 after approaching e because n too large
	}
}
