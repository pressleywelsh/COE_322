#include <iostream>
#include <format>
#include <print>
using namespace std;
int main(){
	for(int i=0;i<16;i++){
		for(int j=0;j<16;j++){
			
			print("{0:>2} " , i*16+j);
		}
		println();
	}
}
