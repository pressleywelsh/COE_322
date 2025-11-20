#include <iostream>
using namespace std;
template<typename T>
class Point {
private:
	float x , y;
public: 
	Point(T xx, T yy) : x(xx) , y(yy) {}
	T numx() { return x;}
	T numy() {return y;}
	Point add( Point& other) {
		return Point(x+other.x,y+other.y);
	}
	Point scale(T num) {
		return Point(x*num,y*num);
	}
	Point halfway ( Point& other) {
		return add(other).scale(0.5f);
	}
	void print (ostream& os = cout) {
		os << "(" << x << " , " << y << ")";
	}
};
int main() {
    Point<double> p(1.0,2.2);
    Point<double> q(3.4,5.6);
    Point h = p.halfway(q);
    cout << "p = ";
    p.print();
    cout<<endl;
    cout << "q = ";
    q.print();
    cout<<endl;
    cout<< "halfway = ";
    h.print();
    cout<<endl;

    Point<float> p2(1.0f,2.2f);
    Point<float> q2(3.4f,5.6f);
    Point h2 = p2.halfway(q2);
    cout << "p = ";
    p2.print();
    cout<<endl;
    cout << "q = ";
    q2.print();
    cout<<endl;
    cout<< "halfway = ";
    h2.print();
    cout<<endl;
    return 0;
}
