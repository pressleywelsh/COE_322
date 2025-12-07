#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ranges>
#include "climate.hpp"
using std::vector;
using std::string;
using std::ifstream;
using std::cout;
using std::endl;
namespace rng = std::ranges;
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
void prevRecord(vector<int> nyears, vector<int> dev, vector<int>& previousRecord){
	int index;
	int recordDev;
	int recordYear;
	int currentDev;
	int currentYear;
	for (int month=0; month<12;month++){
		for (size_t year=0;year<nyears.size();year++){
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
void gaps(int month, vector<int> nyears, vector<int> previousRecord, vector<int>& gapyears, vector<int>& gapsizes){
	int lastRec=0;
	bool haveRec=false;
	gapyears.clear();
	gapsizes.clear();
	for (size_t year=0; year<(nyears.size());year++){
		int index=(12*year)+month;
		if (previousRecord[index] == nyears[year]){
			if (!haveRec){
				haveRec=true;
				lastRec=nyears[year];
			}
			else{
				gapyears.push_back(lastRec);
				gapsizes.push_back(nyears[year] - lastRec);
				lastRec=nyears[year];
			}
		}
	}
}
void linearFunc(vector<int> x, vector<int> y, double& m, double& b){
	double s = x.size();
	double sx = 0;
	double sxx=0;
	double sxy=0;
	double sy=0;
	for (size_t i = 0; i < x.size(); ++i) {
		sx+=x[i];
		sxx+=(x[i]*x[i]);
		sy+=y[i];
		sxy+=(x[i]*y[i]);
	}
	double delta = (s * sxx) - (sx * sx);
	m = ((s * sxy)-(sx * sy))/delta;
	b = ((sxx * sy) - (sx * sxy))/delta;
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
		cout << "Month " << month << " gaps:" <<endl;
		for (size_t i = 0; i < gapyears.size(); ++i) {
			cout << "  from " << gapyears[i] << " gap of " << gapsizes[i] << " years" << endl;
		}
	}
	//62.5 code:
	double m=0.0;
	double b=0.0;
	int nYears = nyears.size();
	for (int month=0;month<12;month++) {
		vector<int> x;
		vector<int> y;
		for (int i : rng::views::iota(0, nYears)) {
			x.push_back(i);
			int index = (12 * i) + month;
			y.push_back(monthly_deviation[index]);
		}
		linearFunc(x, y, m, b);
		cout << "Month: " << month << " trend: deviation = " << m << " * t " << b << endl;
	}
}
