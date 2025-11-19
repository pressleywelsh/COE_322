#include "quadlib.hpp"
#include <tuple>
#include <cmath>
#include <utility>
using std::tuple;
using std::pair;
using std::variant;
using std::sqrt;
double discriminant(quadratic coefficients){
	auto [a,b,c] = coefficients;
	return ((b*b)-(4*a*c));
}
//function to find the discriminant for quadratic equation (what goes in square root)
bool discriminant_zero(quadratic coefficients){
	double D=discriminant(coefficients);
	if (std::abs(D)<1e-12){
		return true;
	}
	else{
		return false;
	}
}
//function that checks if discriminant is equal to zero and returns true if it is
double simple_root(quadratic coefficients){
	auto [a,b,c] = coefficients;
	return -(b/(2*a));
}
//finds simple root of equation (used when discriminant = 0)
double evaluate(quadratic coefficients, double root){
	auto [a,b,c] = coefficients;
	return ((a*root*root)+(b*root)+c);
}
//returns quadratic after evaluated with root, used to test
pair<double,double> double_root(quadratic coefficients){
	auto [a,b,c] = coefficients;
	double D=discriminant(coefficients);
	double root1=((-b)+sqrt(D))/(2*a);
	double root2=((-b)-sqrt(D))/(2*a);
	return {root1,root2};
}
//returns complex root (when there's more than one root) using quadratic formula
variant<int,double,std::pair<double,double>> compute_roots(quadratic coefficients){
	double D = discriminant(coefficients);
	if (D<0){
		return 0;
	}
	//no roots case
	else if ((discriminant_zero(coefficients))==true){
		return simple_root(coefficients);
	}
	//one root case
	else{
		return double_root(coefficients);
	}
	//two roots case
}
