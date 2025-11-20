#include <iostream>
using namespace std;
class Point {
private:
	float x , y;
public: 
	Point(float xx, float yy) : x(xx) , y(yy) {}
	float numx() const { return x;}
	float numy() const {return y;}
	Point add(const Point& other) const{
		return Point(x+other.x,y+other.y);
	}
	Point scale(float num) const{
		return Point(x*num,y*num);
	}
	Point halfway (const Point& other) const {
		return add(other).scale(0.5f);
	}
	void print (ostream& os = cout) const{
		os << "(" << x << " , " << y << ")";
	}
};
int main() {
    Point p(1.0f,2.2f);
    Point q(3.4f,5.6f);
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
    return 0;
}
