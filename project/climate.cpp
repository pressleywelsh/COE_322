#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using std::vector;
using std::string;
using std::ifstream;
using std::cout;
using std::endl;
void readFile( string fileName, vector<int>& nyears, vector<double>& dev){
	ifstream fin;
	fin.open(fileName);
	if (fin.is_open()) {
		int year;
		double num;
		while (fin >> year) {
			nyears.push_back(year);
			for (int i=1;i<=12;i++){
				if (fin >> num) {
					dev.push_back(num);
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
	//GLB_clean.txt is GLB.Ts+dSST.txt after using grep
	readFile("GLB_clean.txt", nyears, dev);
	cout << "Read " << nyears.size() << " years\n";
	std::cout << "Read " << dev.size() << " monthly deviations\n";
}
