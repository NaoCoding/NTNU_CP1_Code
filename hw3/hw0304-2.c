#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "hw0304.h"
 
int32_t which_plate(int32_t n){

	int32_t c = n ^ (n+1);
	int32_t i=0;
	while(c!=0){
		c = c >> 1;
		i ++;
	}
	return i;


}

void transfer_plate(int32_t n, int32_t where_did_it_from, int32_t where_did_it_go , int32_t last){

	int32_t total_moves = pow(2,n)-1;
	int32_t position[n];
	for(int32_t i=0;i<n;i++) position[i] = 1;
	int32_t direction[2];
	direction[0] = n%2==0? 1:0;
	direction[1] = n%2==0? 0:1;

	for(int32_t i=0;i<total_moves;i++){

		int32_t plate = which_plate(i);
		int32_t p_idx = plate - 1;
		int32_t d_idx = plate & 1;
		int32_t next = (position[p_idx] + direction[d_idx])%3+1;
		position[p_idx] = next;
		if(next==3) next=2;
		else if(next==2) next = 3;
		printf("move disk %d to rod %d\n",p_idx+1,next);
		

	}




	




}