#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "mycontrol.h"
static int32_t intiset = 0;

static double char_x,char_y,char_angle;

void initialize( double x, double y, double a){

	char_x = x;
	char_y = y;
	char_angle = a;
	while(char_angle<0) char_angle += 2*M_PI;
	while(char_angle>2*M_PI) char_angle -= 2*M_PI;
	intiset = 1;
}

int32_t forward( double length ){

	if(!intiset) return -1;
	char_y += length * sin(char_angle);
	char_x += length * cos(char_angle);
	return 0;


}

int32_t clock_turn( double x ){
	if(!intiset) return -1;
	char_angle -= x;
	while(char_angle<0) char_angle += 2*M_PI;
	while(char_angle>2*M_PI) char_angle -= 2*M_PI;
	return 0;

}

int32_t counterclock_turn( double x ){

	if(!intiset) return -1;
	char_angle += x;
	while(char_angle<0) char_angle += 2*M_PI;
	while(char_angle>2*M_PI) char_angle -= 2*M_PI;
	return 0;
}

int32_t print(){

	if(!intiset) return -1;
	while(char_angle<0) char_angle += 2*M_PI;
	while(char_angle>2*M_PI) char_angle -= 2*M_PI;
	printf("position: (%.2lf,%.2lf), angle: %.2lf\n",char_x,char_y,char_angle/M_PI);
	return 0;

}