#include <iostream>
#include <print>
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
class primegenerator {
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
		return prime;
	}
	num+=1;
		
};

int main(){
	cin >> nprimes;
	primegenerator sequence;
	while (sequence.number_of_primes_found()<nprimes) {
		int number = sequence.nextprime();
		cout << "Number " << number << " is prime" << '\n';
	}
}
