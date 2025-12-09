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
//read file uses fstream to read file and assign the first column to nyears and the next 12 columns to dev
void readFile( string fileName, vector<int>& nyears, vector<int>& dev){
	ifstream fin;
	fin.open(fileName);
	if (fin.is_open()) {
		int year;
		int num;
		while (fin >> year) {
			nyears.push_back(year);
			int count = 0;
			//counts how many columns are counted for the year
			for (int i=1;i<=12;i++){
				if (fin >> num) {
					dev.push_back(num);
					count+=1;
				}
				else{
					break;
				}
			}
			//if less than 12 full columns in a year, year is deleted and all columns for that year deleted
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
			//for each month, it goes through every year
			index=(12*year)+month;
			currentDev = dev[index];
			currentYear = nyears[year];
			if (year==0){
				//initial values are set like first year is record year, and record dev is first dev
				recordYear=nyears[year];
				recordDev=currentDev;
				previousRecord[index]=recordYear;
			}
			if (year>0){
				//if there's a record set, record dev and record year changed then previousRecord is set
				if (currentDev>recordDev){
					recordDev=currentDev;
					recordYear=currentYear;
					previousRecord[index]=recordYear;
				}
				//if no record set, previousRecord is set to previous record year
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
	//two vectors cleared in case of reuse
	gapyears.clear();
	gapsizes.clear();
	for (size_t year=0; year<(nyears.size());year++){
		int index=(12*year)+month;
		//goes through every year for one month
		if (previousRecord[index] == nyears[year]){ //years where record is set
			if (!haveRec){
				haveRec=true;
				lastRec=nyears[year];
			}
			//if first year, set lastRec to current year
			else{
				gapyears.push_back(lastRec);
				gapsizes.push_back(nyears[year] - lastRec);
				lastRec=nyears[year];
			}
			//adds that year to gapyears and assigns difference between that year and lastRec to gapsizes   and then assigns that year to lastRec
		}
	}
}
void linearFunc(vector<int> x, vector<int> y, double& m, double& b){
	//uses equation from numerical recipes to find line of best fit using y= m*x + b
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
		//calculate all needed elements for delta, m, and b
	}
	double delta = (s * sxx) - (sx * sx);
	m = ((s * sxy)-(sx * sy))/delta;
	b = ((sxx * sy) - (sx * sxy))/delta;
}
int main(){
	//first file: land-ocean
	{
		vector<int> nyears;
		vector<int> monthly_deviation;
		//GLB.Ts+dSST_clean.txt is GLB.Ts+dSST.txt after using grep
		cout << "=== Analysis for GLB.Ts+dSST_clean.txt ===" << endl;
		readFile("GLB.Ts+dSST_clean.txt", nyears, monthly_deviation);
		cout << "Read " << nyears.size() << " years"<<endl;
		cout << "Read " << monthly_deviation.size() << " monthly deviations"<<endl;
		//previous_record hold year of record so far
		vector<int> previous_record(monthly_deviation.size());
		prevRecord(nyears, monthly_deviation, previous_record);
		//stores gap analysis per month
		vector<int> gapyears(nyears.size());
		vector<int> gapsizes(nyears.size());
		//analyzes gaps between years
		for (int month=0;month<12;month++){
			gaps(month, nyears, previous_record, gapyears, gapsizes);
			cout << "Month " << month << " gaps:" <<endl;
			for (size_t i = 0; i < gapyears.size(); ++i) {
				cout << "  from " << gapyears[i] << " gap of " << gapsizes[i] << " years" << endl;
			}
			int numGaps = gapsizes.size();
			vector<int> xgap;
			vector<int> ygap;
			for (int i : rng::views::iota(0, numGaps)) {
				xgap.push_back(i+1);
				ygap.push_back(gapsizes[i]);
			}
			//calculates regression for each month using gap size vs record
			double mgap=0.0;
			double bgap=0.0;
			linearFunc(xgap, ygap, mgap, bgap);
			cout << "Regression: gap size = " << mgap << " * recordIndex + " << bgap << endl;
		}
		//62.5 code for GLB.Ts+dSST_clean:
		//calculates regression for each month using deviation vs time
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
			cout << "Month " << month << " trend: deviation = " << m << " * t + " << b << endl;
		}
		cout << "=== End of GLB.Ts+dSST_clean.txt analysis ===" <<endl;
	}
	//Second file: station
	{
		vector<int> nyears;
                vector<int> monthly_deviation;
                //GLB.Ts_clean.txt is GLB.Ts.txt after using grep
                cout << "=== Analysis for GLB.Ts_clean.txt ===" << endl;
                readFile("GLB.Ts_clean.txt", nyears, monthly_deviation);
                cout << "Read " << nyears.size() << " years"<<endl;
                cout << "Read " << monthly_deviation.size() << " monthly deviations"<<endl;
                //previous_record hold year of record so far
		vector<int> previous_record(monthly_deviation.size());
                prevRecord(nyears, monthly_deviation, previous_record);
                //stores gap analysis per month
		vector<int> gapyears(nyears.size());
                vector<int> gapsizes(nyears.size());
		//analyzes gaps between years
                for (int month=0;month<12;month++){
                        gaps(month, nyears, previous_record, gapyears, gapsizes);
                        cout << "Month " << month << " gaps:" <<endl;
                        for (size_t i = 0; i < gapyears.size(); ++i) {
                                cout << "  from " << gapyears[i] << " gap of " << gapsizes[i] << " years" << endl;
                        }
                        int numGaps = gapsizes.size();
                        vector<int> xgap;
                        vector<int> ygap;
                        for (int i : rng::views::iota(0, numGaps)) {
                                xgap.push_back(i+1);
                                ygap.push_back(gapsizes[i]);
                        }
			//calculates regression for each month using gap size vs record
                        double mgap=0.0;
                        double bgap=0.0;
                        linearFunc(xgap, ygap, mgap, bgap);
                        cout << "Regression: gap size = " << mgap << " * recordIndex + " << bgap << endl;
                }
		//62.5 code for GLB.Ts_clean:
		//calculates regression for each month using deviation vs time
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
                        cout << "Month " << month << " trend: deviation = " << m << " * t + " << b << endl;
                }
                cout << "=== End of GLB.Ts_clean.txt analysis ===" <<endl;
	}
}
