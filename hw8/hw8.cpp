#include <iostream>
#include <cstdio>
#include <cxxopts.hpp>
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
	int mod;
	storage2d a;
public:
	pascal(int num, int m=0) : n(num), mod(m), a(num, num) {
		for (int r=0;r<n;r++){
			int edge = 1;
			if (mod>0){
				edge = 1%mod;
			}
			a.set(r,0,edge);
			a.set(r,r,edge);
			for (int c=1;c<=(r-1);c++){
				int k=(a.get(r-1,c-1)) + (a.get(r-1,c));
				if (mod>0){
					k=k%mod;
				}
				a.set(r,c,k);
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
int main(int argc, char** argv){
	int n=9;
	int mod=0;
	cxxopts::Options options("your_pascal_program","Pascal triangle");
	options.add_options()
		("h,help", "Show help")
		("n,size", "Number of rows", cxxopts::value<int>()->default_value("9"))
		("m,module", "Modulus (0 = none)", cxxopts::value<int>()->default_value("0"));
	auto result = options.parse(argc, argv);
	if (result.count("help")) {
		printf("Usage: your_pascal_program [ -h ] [ -n size ] [ -m module ]\n\n");
		printf("%s\n", options.help().c_str());
		return 0;
	}
	n = result["size"].as<int>();
	mod = result["module"].as<int>();
	pascal pyr(n,mod);
	printf("Row 7, Col 3 = %d\n", pyr.getvalue(7, 3));
	pyr.print();
	return 0;
}
