#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "parity.h"

static int32_t bit2arrays[5][33];
static int32_t ans_array[33];

void calc_ans(){

	for(int32_t i=0;i<33;i++){

		int32_t p =0;
		for(int32_t j=0;j<5;j++){
			p += bit2arrays[j][i];
		}
		ans_array[i] = p%2==0 ? 1 : 0;

	}

}

void bit_array(int32_t target, int32_t n){

	int32_t total_one_bit = 0;
	int64_t transformed = (uint32_t)target;
	for(int i=31;i>=0;i--){
		bit2arrays[n][i] = transformed / (int64_t)pow(2,i);
		total_one_bit += bit2arrays[n][i];
		transformed %= (int64_t)pow(2,i);
		//printf("%d",bit2arrays[n][i]);
	}
	if(total_one_bit%2==0) bit2arrays[n][32] = 1;
	//printf("%d\n",bit2arrays[n][32]);

}

uint64_t parity_2d( int32_t a, int32_t b, int32_t c, int32_t d, int32_t e){

	
	bit_array(a,0);
	bit_array(b,1);
	bit_array(c,2);
	bit_array(d,3);
	bit_array(e,4);

	calc_ans();

	uint64_t ans = 0;
	for(int32_t i=31;i>=0;i--){
		ans += (uint64_t)pow(2,i+1)*ans_array[i];
		//printf("%d",ans_array[i]);
	}
	//printf("%d \n",ans_array[32]);
	return ans + ans_array[32];

}