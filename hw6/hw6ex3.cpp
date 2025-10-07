#include <iostream>
using namespace std;
class primegenerator {
public : 
	int num;
private : 
	primegenerator (num){
		return;
	}
}
bool isprime(int n){
	bool prime = true;
	for (int i=2; i<n ; i++){
		if ((n%i)==0){
			prime = false;
		}
	}
	if (n<2){
		prime = false;
	}
	return prime;
}
