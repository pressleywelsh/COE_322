#include <iostream>
#include <cstdio>
using namespace std;
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
class PrimeGenerator {
private :
	int num{0};
	int prime{1};
public : 
	int number_of_primes_found(){
		return num;
	}
	int nextprime(){
		int test = prime+1;
		while(!(isprime(test))){
			test+=1;
		}
		prime=test;
		num+=1;
		return prime;
	}
};
int main(){
	int bound;
	cin>>bound;
	if (bound<4){
		cout<<"Not applicable to numbers under 4"<<endl;
		return 0;
	}
	for (int e=4; e<=bound; e=e+2){
		PrimeGenerator gen;
		bool found=false;
		while (!(found)){
			int p=gen.nextprime();
			int q=e-p;
			if (isprime(q)){
				printf("The number %d is %d+%d\n", e, p, q);
				found=true;
			}
			if (p>(e/2)){
				cout<< "no pair found for " << e << endl;
				break;
			}
		}
	}
}
