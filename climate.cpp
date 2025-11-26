#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using std::vector;
using std::string;
using std::ifstream;
using std::cout;
using std::endl;
void readFile( string fileName; vector<int>& nyears, vector<double>& dev){
	ifstream fin;
	fin.open("text.txt");
	if (fin.is_open()) {
		int year;
		double num;
		while (fin >> year) {
			nyears.push_back(year);
			for (int i=1;i<=12;i++){
				if (fin >> value) {
					dev.push_back(value);
				}
			}
		}
	}
	else{
		cout << "failed to open file !" << endl;
		exit (-1);
	}
	fin.close();
}
int main(){
	vector<int> nyears;
	vector<double> dev;
}
