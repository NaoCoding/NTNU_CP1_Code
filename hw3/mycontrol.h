#ifndef MYCONTROL_H_
#define MYCONTROL_H_
#include <stdint.h>

void initialize( double x, double y, double a);

int32_t forward( double length );
int32_t clock_turn( double x );
int32_t counterclock_turn( double x );
int32_t print();


#endif