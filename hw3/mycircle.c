#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI_ 3.14159265358979323846
static long double circle_radius = -1;
#include "mycircle.h"



int32_t set_radius(double r){

	if(r<=0) return -1;
	circle_radius = r;
	return 0;

}

double get_circle_circumference(){

	if(circle_radius!=-1) return circle_radius*2*PI_;
	return -1;

} 

double get_circle_area(){
	if(circle_radius!=-1) return circle_radius*circle_radius*PI_;
	return -1;
}

double get_tangent_area( double x ){

	if(x>=circle_radius) return -1;
	if(circle_radius==-1) return -1;
	if(x<=-circle_radius) return -1;
	double y = sqrt(circle_radius*circle_radius-x*x);
	if(y==0||x==0)return -1;
	double m = -x / y;
	double c = (m*x)-y , d = c/m;
	if(c<0) c *= -1;
	if(d<0) d*=-1;
	//printf("%lf %lf %lf %lf",y,m,c,d);
	return c*d/2;


}

double get_inner_regular_polygon_area( int32_t  n){

	if(circle_radius!=-1) return circle_radius*circle_radius*sin(2*PI_/n)/2*n;
	return -1;


}


double get_outer_regular_polygon_area( int32_t n){

	if(circle_radius!=-1) return circle_radius*circle_radius*n*tan(PI_/n);

	return -1;


}