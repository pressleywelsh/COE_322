#include <iostream>
using namespace std;
int main(){
	int N;
	cout<<"Enter an integer: "<<endl;
	cin>>N;
	bool factorFound=false;
	while (factorFound==false){
		for (int i=0; i<N;i++){
			for (int j=9;j>=0;j--){
				if ((i*j)>N){
					cout<<i<<" , " <<j<<endl;
					factorFound=true;
					break;
				}
			}
		if (factorFound==true){
			break;
		}
		}
	}
	for (int sum=0; ;sum++){
		for (int i=0; i<=sum;i++){
			int j=sum-i;
			if ((i*j)>N){
				cout<<i<<" , "<<j<<endl;
				return 0;
			}
		}
	}

	return 0;
}
