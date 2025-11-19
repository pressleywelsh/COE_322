#include <linklib.hpp>
#include <tuple>
#include <cmath>
using std::tuple;
using std::pair;
using std::variant;
double discriminant(quadratic coefficients){
	auto [a,b,c] = coefficients;
	return ((b*b)-(4*a*c));
}
bool discriminant_zero(quadratic coefficients){
	double D=discriminant(coefficients);
	if (std::abs(D)==0){
		return true;
	}
	else{
		return false;
	}
}
double simple_root(quadratic coefficients){
	auto [a,b,c] = coefficients;
	return -(b/(2*a));
}
double evaluate(quadratic coefficients, double root){
	auto [a,b,c] = coefficients;
	return ((a*root*root)+(b*root)+c);
}
pair<double,double> double_root(quadratic coefficients){
	auto [a,b,c] = coefficients;
	double D=discriminant(coefficients);
	double root1=((-b)+sqrt(D))/(2*a);
	double root2=((-b)-sqrt(D))/(2*a);
	return pair<root1,root2>;
}
variant<int,double,std::pair<double,double>> compute_roots(quadratic coefficients){
	double D = discriminant(coefficients);
	if (D<0){
		return 0;
	}
	else if ((discriminant_zero(coefficients))==true){
		return simple_root(coefficients);
	}
	else{
		return double_root(coefficients);
	}
}
