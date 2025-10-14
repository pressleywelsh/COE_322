#include <iostream>
#include <cstdio>
using namespace std;
class pascal {
private: 
	int n;
	int* data;
public: 
	pascal(int num){
		n=num;
		data = new int [n*n]{};
		for (int r=0;r<n;r++){
			data[r*n + 0] = 1;
			data[r*n + r] = 1;
			for (int c=1;c<=(r-1);c++){
				data[r*n+c] = (data[(r-1)*n+(c-1)]) + (data[(r-1)*n+c]);
			}
		}
	}
	~pascal() {
		delete[] data;
	}
	int getvalue(int i,int j){
		if ((i<1) or (i>n)){
			return (0);
		}
		if ((j<1) or (j>i)){
			return (0);
		}
		return (data[(i-1)*n+(j-1)]);
	}
	void print(){
		int w=4;
		for (int i=1; i<=n; i++){
			int gap = ((n-i)*w)/2;
			for (int g=0;g<gap;g++){
				printf(" ");
			}
			for (int j=1; j<=i; j++){
				printf("%*d", w, getvalue(i, j));
			}
			printf("\n");
		}
	}
};
int main(){
	pascal pyr(9);
	printf("Row 7, Col 3 = %d\n", pyr.getvalue(7, 3));
	pyr.print();
	return 0;
}
