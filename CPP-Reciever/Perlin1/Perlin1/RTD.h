#include <math.h>
const double PI = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170680;
double RAD(double deg){
	double r;
	r = (PI / 180)*deg;
	return r;
}
double rtdx(double t, double r){
	double rad;
	rad = RAD(t);
	double x = r*(cos(rad));
	return x;
}
double rtdy(double t, double r){
	double rad;
	rad = RAD(t);
	double y = r*(sin(rad));
	return y;
}