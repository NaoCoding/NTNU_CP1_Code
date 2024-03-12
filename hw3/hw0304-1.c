#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "hw0304.h"

void transfer_plate(int32_t n, int32_t where_did_it_from, int32_t where_did_it_go , int32_t last){

	if(n==1){
		printf("move disk %d to rod %d\n",n,where_did_it_go);
		return;
	}

	transfer_plate(n-1,where_did_it_from,last,where_did_it_go);
	printf("move disk %d to rod %d\n",n,where_did_it_go);
	transfer_plate(n-1,last,where_did_it_go,where_did_it_from);




}