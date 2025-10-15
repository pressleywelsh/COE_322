#include <iostream>
#include <cstdio>
using namespace std;
class storage2d {
private:
        int rows;
        int cols;
	int *data;
public:
	storage2d(int r, int c) {
		rows = r;
		cols = c;
		data = new int[rows*cols]{};
	}
	~storage2d(){
		delete[] data;
	}
	int get(int i, int j){
		return data[i*cols+j];
	}
	void set(int i, int j, int num){
		data[i*cols+j] = num;
	}
};
class pascal {
private:
	int n;
	storage2d a;
public:
	pascal(int num) : n(num), a(num, num) {
		for (int r=0;r<n;r++){
			a.set(r,0,1);
			a.set(r,r,1);
			for (int c=1;c<=(r-1);c++){
				a.set(r,c,a.get(r-1,c-1) + a.get(r-1,c));
			}
		}
	}
	int getvalue(int i,int j){
		if ((i<1) or (i>n)){
			return (0);
		}
		if ((j<1) or (j>i)){
			return (0);
		}
		return a.get(i-1,j-1);
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
