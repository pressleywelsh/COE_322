#include <print>
using std::print,std::println;

#include <cmath>
using std::sqrt;

class Point {
private:
	float x,y;
public:
	Point(float in_x,float in_y) {
		x = in_x; y = in_y; };
	float distance_to_origin() {
		return sqrt( x*x + y*y );
	};
	float angle() {
		return ((180/(M_PI)*(atan2(y, x));
	};
};
	  

int main() {
  Point p1(1.0,1.0);
  float d = p1.distance_to_origin();
  println( "Distance to origin: {:6.4}",
           d );

  return 0;
}
