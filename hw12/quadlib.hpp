#include <tuple>
#include <variant>
using std::tuple;
using std::pair;
using std::variant;
using quadratic = tuple<double, double, double>;
double discriminant(quadratic);
bool discriminant_zero(quadratic);
double simple_root(quadratic);
double evaluate(quadratic, double);
pair<double,double> double_root(quadratic);
variant<int, double, pair<double,double>> compute_roots(quadratic);
//all functions to be defined later
