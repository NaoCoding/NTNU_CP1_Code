#ifndef DICEROLLS_H
#define DICEROLLS_H
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

int32_t statistics( int32_t *pData , int32_t size, double *pMean, double *pVariance , double *pStd ); 
#endif