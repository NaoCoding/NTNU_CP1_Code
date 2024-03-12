#include <stdio.h>
#include <stdint.h>
#include "weight.h"

static uint32_t girl_W = -1,boy_W = -1;

void setup_girl_weight( uint32_t a){

	girl_W = a;

}
void setup_boy_weight( uint32_t b){

	boy_W = b;

}

int64_t selfWeight(int32_t pos){

	if(pos%2) return boy_W;
	else return girl_W;

}

int64_t afford_weight( int32_t x, int32_t y ){

	

	if(y>x||boy_W==-1||girl_W==-1) return -1;

	if(x==0) return 0;

	if(y==x) return (long double)afford_weight(x-1,y-1) + (long double)selfWeight(x-1)/2;
	if(y==0) return (long double)afford_weight(x-1,0) + (long double)selfWeight(x-1)/2;

	return (long double)selfWeight(x-1) + (long double)afford_weight(x-1,y-1) + (long double)afford_weight(x-1,y);



}