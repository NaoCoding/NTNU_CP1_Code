#include "mytlv.h"

int check_valid(uint8_t *arr,int32_t size){

	int idx = 0;
	while(idx < size){
		//printf("%d %d\n",idx,arr[idx]);
		while(arr[idx]>10||arr[idx]<1) idx += 3 + arr[idx+1] + arr[idx+2] * 256;
		if(arr[idx] == 4 || arr[idx] == 5 || arr[idx] == 8 || arr[idx] == 9 || arr[idx] == 10){
			if(arr[idx+1] != 0 || arr[idx+2] != 0) return 0;
			idx += 3;
		}
		else{
			if(arr[idx+1] > 20 || arr[idx+2] > 0) return 0;
			for(int i=idx + 3;i< idx + 3 + arr[idx+1];i++){
				if(arr[i] > 9) return 0;
			}
			idx += 3 + arr[idx+1];
		} 
	}
	return 1;

}

int64_t merge(int64_t a , int64_t b){

	int64_t c = b;
	int64_t digit = b == 0 ? 1 : 0;
	while(c){
		c /= 10;
		digit += 1;
	}

	while(digit){
		a *= 10;
		digit -= 1;
	}
	return a + b;

}


int32_t run( uint8_t *arr , int32_t size ){

	int idx = 0;
	uint64_t ans  = 0;
	int initial = 0;
	if(!check_valid(arr,size)) return -1;
	while(idx < size){

		int mode = arr[idx];
		int length = arr[idx+1] + arr[idx+2] * 256;
		int cancel_t = mode == 10 ? 1 : 0,cancel_idx = idx + 3 + length;

		while(cancel_idx < size){
			if(arr[cancel_idx] != 10) break;
			cancel_idx += 3;
			cancel_t += 1;
		}
		if(cancel_t%2 && idx == 0) return -1;
		if(cancel_t%2){
			idx += 3 + length;
			continue;
		}
		if(mode != 1 && mode != 8 && !initial && mode > 1 && mode < 10) return -1;
		
		if(mode == 1){
			ans = 0;
			for(int i=idx+3;i<idx + 3 + length;i++){
				ans =  ans * 10 + arr[i];
			}
			idx += 3 + length;
			initial = 1;
		}

		else if(mode == 2){
			uint64_t plus = 0;
			for(int i=idx+3;i<idx + 3 + length;i++){
				plus =  plus * 10 + arr[i];
			}
			idx += 3 + length;
			ans += plus;
		}

		else if(mode == 3){
			uint64_t plus = 0;
			for(int i=idx+3;i<idx + 3 + length;i++){
				plus =  plus * 10 + arr[i];
			}
			idx += 3 + length;
			ans *= plus;
		}

		else if(mode == 4){
			idx += 3;
			ans /= 2;
		}

		else if(mode == 5){
			idx += 3;
			ans /= 10;
		}

		else if(mode == 6){
			uint64_t plus = 0;
			for(int i=idx+3;i<idx + 3 + length;i++){
				plus =  plus * 10 + arr[i];
			}
			idx += 3 + length;
			ans = merge(plus,ans);
		}

		else if(mode == 7){
			uint64_t plus = 0;
			for(int i=idx+3;i<idx + 3 + length;i++){
				plus =  plus * 10 + arr[i];
			}
			idx += 3 + length;
			ans = merge(ans,plus);
		}

		else if(mode == 8){
			idx += 3;
			ans = 0;
			initial = 1;
		}

		else if(mode == 9){
			idx += 3;
			printf("%ld\n",ans);
		}
		else if(mode > 10 || mode < 1) idx += 3 + arr[idx+1] + arr[idx+2]*256;
		else if(mode == 10) idx += 3;
		//printf("%ld\n",ans);


	}	
	return 0;



}
