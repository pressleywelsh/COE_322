#include <tuple>
#include <variant>
usind std::tuple;
using std::pair;
using std::variant;
using quadratic = tuple<double, double, double>;
double discriminant(quadratic);
bool discriminant_zero(quadratic);
double simple_root(quadratic);
double evaluate(quadratic, double);
pair<double,double> double_root(quadratic);
variant<Type0, Type1, Type2>;
