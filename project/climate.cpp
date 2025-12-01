#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "climate.hpp"
using std::vector;
using std::string;
using std::ifstream;
using std::cout;
using std::endl;
void readFile( string fileName, vector<int>& nyears, vector<int>& dev){
	ifstream fin;
	fin.open(fileName);
	if (fin.is_open()) {
		int year;
		int num;
		while (fin >> year) {
			nyears.push_back(year);
			int count = 0;
			for (int i=1;i<=12;i++){
				if (fin >> num) {
					dev.push_back(num);
					count+=1;
				}
				else{
					break;
				}
			}
			if (count<12){
				nyears.resize(nyears.size() - 1);
				dev.resize(dev.size() - count);
			}
		}
	}
	else{
		cout << "failed to open file !" << endl;
		exit (-1);
	}
	fin.close();
}
void prevRecord(vector<int>& nyears, vector<int>& dev, vector<int>& previousRecord){
	int index;
	int recordDev;
	int recordYear;
	int currentDev;
	int currentYear;
	for (int month=0; month<12;month++){
		for (int year=0;year<nyears.size();year++){
			index=(12*year)+month;
			currentDev = dev[index];
			currentYear = nyears[year];
			if (year==0){
				recordYear=nyears[year];
				recordDev=currentDev;
				previousRecord[index]=recordYear;
			}
			if (year>0){
				if (currentDev>recordDev){
					recordDev=currentDev;
					recordYear=currentYear;
					previousRecord[index]=recordYear;
				}
				else{
					previousRecord[index]=recordYear;
				}
			}
		}
	}
}
void gaps(int month, vector<int>& nyears, vector<int>& previousRecord, vector<int>& gapyears, vector<int>& gapsizes){
	int lastRec=0;
	bool haveRec=false;
	int numGaps=0;
	for (int year=0; year<(nyears.size());year++){
		int index=(12*year)+month;
		if (previousRecord[index] == nyears[year]){
			if (!haveRec){
				haveRec=true;
				lastRec=nyears[year];
			}
			else{
				gapyears[numGaps]=lastRec;
				gapsizes[numGaps]=nyears[year] - lastRec;
				numGaps+=1;
				lastRec=nyears[year];
			}
		}
	}
}
int main(){
	vector<int> nyears;
	vector<int> monthly_deviation;
	//GLB_clean.txt is GLB.Ts+dSST.txt after using grep
	readFile("GLB_monthly.txt", nyears, monthly_deviation);
	cout << "Read " << nyears.size() << " years"<<endl;
	cout << "Read " << monthly_deviation.size() << " monthly deviations"<<endl;
	vector<int> previous_record(monthly_deviation.size());
	prevRecord(nyears, monthly_deviation, previous_record);
	vector<int> gapyears(nyears.size());
	vector<int> gapsizes(nyears.size());
	for (int month=0;month<12;month++){
		gaps(month, nyears, previous_record, gapyears, gapsizes);
		cout << "Month " << month << " gaps"<<endl;
	}
}
