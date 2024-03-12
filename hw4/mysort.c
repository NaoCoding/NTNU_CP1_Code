#include "mysort.h"

void mysort( int32_t array[], int32_t size ){

	if(size<=0){
		printf("Error Input!");
		return;
	}
	int twosize = 0;
	int onesize = 0;
	int twos[size], ones[size];
	for(int i=0;i<size;i++){
		if(array[i]%2){
			ones[onesize] = array[i];
			onesize += 1;
		}
		else{
			twos[twosize] = array[i];
			twosize += 1;
		}
	}

	for(int i=0;i<twosize;i++){
		for(int j=i+1;j<twosize;j++){
			if(twos[i] < twos[j]){
				int temp = twos[i];
				twos[i] = twos[j];
				twos[j] = temp;
			}
		}
	}

	for(int i=0;i<onesize;i++){
		for(int j=i+1;j<onesize;j++){
			if(ones[i] > ones[j]){
				int temp = ones[i];
				ones[i] = ones[j];
				ones[j] = temp;
			}
		}
	}

	for(int i=0;i<twosize;i++) array[i] = twos[i];
	for(int i=0;i<onesize;i++) array[i+twosize] = ones[i];

}
void myprint( int32_t array[], int32_t size ){

	if(size<=0){
		printf("Error Input!");
		return;
	}
	for(int i=0;i<size;i++) printf("%d ",array[i]);

	printf("\n");

}