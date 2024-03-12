#include "mystatistics.h"

int32_t statistics( int32_t *pData , int32_t size, double *pMean, double *pVariance , double *pStd ){

	if(size<=0||pData==NULL)return -1;
	double sum = 0;
	for(int32_t i=0;i<size;i++){
		sum += *(pData+i);
	}
	sum/=size;
	*pMean = sum;
	double vari = 0;
	for(int32_t i=0;i<size;i++){
		vari += (*(pData+i)-sum)*(*(pData+i)-sum);
	}
	vari /=size;
	*pVariance = vari;
	*pStd = sqrt(vari);



	return 0;
}