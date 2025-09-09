#include <iostream>
using namespace std;
bool is_Prime(int num){
	int count=0;
	for (int i=1; i<=num; i++){
		if ((num % i)==0){
			count+=1;
		}
	}
	if (count>2){
		return false;
	}
	else{
		return true;
	}
}
int main(){
	bool isPrime;
	isPrime = is_Prime(13);
	if ((isPrime==0) == true){
		cout<< "false" << endl;
	}
	else{
		cout<< "true" << endl;
	}
	return 0;
}
