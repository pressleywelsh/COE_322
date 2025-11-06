#include <iostream>
#include <cxxopts.hpp>
#include <cstdio>
#include <memory>
#include <vector>
using std::shared_ptr;
using std::make_shared;
using std::unique_ptr;
using std::make_unique;
class Point {
private: 
	//x and y variables
	double x;
	double y;
public: 
	//constructs point
	Point(double x1, double y1) {
		x=x1;
		y=y1;
	}
	//returns x-value
	double getx(){
		return x;
	}
	//returns y-value
	double gety(){
		return y;
	}
	//sets new x-value
	void setx(double num){
		x=num;
	}
	//sets new y-value
	void sety(double num){
		y=num;
	}
	//prints point
	void print(){
		std::printf("(%g, %g)\n", x, y);
	}
};
class DynRectangle {
private: 
	//bottom left point
	shared_ptr<Point> bottom;
	//top right point
	shared_ptr<Point> top;
public:
       //constructs rectangle	
	DynRectangle(shared_ptr<Point> bl, shared_ptr<Point> tl){
		bottom=bl;
		top=tl;
	}
	//width of rectangle
	double width(){
		return ((top->getx())-(bottom->getx()));
	}
	//height of rectangle 
	double height(){
		return ((top->gety())-(bottom->gety()));
	}
	//area of rectangle
	double area(){
		return (width()*height());
	}
};
int main( int argc,char** argv ) {
	//add options
	cxxopts::Options options("dynrectangle","Compute areas of two rectangles");
	options.add_options()
		("h,help", "Show help")
		("p,point_p", "bottom left of rect1: (px,py)", cxxopts::value<std::vector<double>>()->default_value("0,0"))
		("q,point_q", "shared corner: (qx,qy)", cxxopts::value<std::vector<double>>()->default_value("2,2"))
		("r,point_r", "top right of rect2: (rx,ry)", cxxopts::value<std::vector<double>>()->default_value("4,4"))
		("m,shift", "shift, point m: (mx,my)", cxxopts::value<std::vector<double>>()->default_value("3,3"));
	auto result = options.parse(argc, argv);
	//help option
	if ( result.count("h") ) {
		std::cout << options.help() << '\n';
	}
	//read results
	auto P = result["point_p"].as<std::vector<double>>();
	auto Q = result["point_q"].as<std::vector<double>>();
	auto R = result["point_r"].as<std::vector<double>>();
	auto M = result["shift"].as<std::vector<double>>();
	//assigns points
	auto Ppt = std::make_shared<Point>(P[0], P[1]);
	auto Qpt = std::make_shared<Point>(Q[0], Q[1]);
	auto Rpt = std::make_shared<Point>(R[0], R[1]);
	//build rectangles with shared point
	DynRectangle rect1(Ppt, Qpt);
	DynRectangle rect2(Qpt, Rpt);
	//print area before shift
	std::printf("Before: A1=%.3f  A2=%.3f\n", rect1.area(), rect2.area());
	//shift point
	Qpt->setx(Qpt->getx() + M[0]);
	Qpt->sety(Qpt->gety() + M[1]);
	//print after shift
	std::printf("After:  A1=%.3f  A2=%.3f\n", rect1.area(), rect2.area());
	return 0;
}
