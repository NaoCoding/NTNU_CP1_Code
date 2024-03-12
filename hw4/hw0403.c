#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "gsat.h"

void sorting_(int32_t array[]){

	for(int i=0;i<STUDENT_NUMBER;i++){
		for(int j=i+1;j<STUDENT_NUMBER;j++){
			if(array[i] > array[j]){
				int32_t temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}

}

int main(){

	int32_t overall_score[6][STUDENT_NUMBER];

	for(int32_t i=0;i<6;i++){
		for(int32_t j=0;j<STUDENT_NUMBER;j++){
			overall_score[i][j] = score[j][i];
		}
		sorting_(overall_score[i]);
	}
	int64_t p[5] = {STUDENT_NUMBER*0.88+0.9999,STUDENT_NUMBER*0.75+0.9999,STUDENT_NUMBER*0.5+0.9999,STUDENT_NUMBER*0.25+0.9999,STUDENT_NUMBER*0.12+0.9999};

	printf("\tCHINESE | ENGLISH | MATH_A  | MATH_B  | SOCIAL  | SCIENCE\n");
	int64_t t[5]={12,25,50,75,88};
	for(int32_t i=0;i<5;i++){
		printf("TOP %ld%%    ",t[i]);
		printf("%2d        ",overall_score[CHINESE][p[i]-1]);
		printf("%2d        ",overall_score[ENGLISH][p[i]-1]);
		printf("%2d        ",overall_score[MATH_A][p[i]-1]);
		printf("%2d        ",overall_score[MATH_B][p[i]-1]);
		printf("%2d        ",overall_score[SOCIAL][p[i]-1]);
		printf("%2d        ",overall_score[SCIENCE][p[i]-1]);
		printf("\n");
	}


	/*for(int32_t i=0;i<6;i++){
		for(int32_t j=0;j<STUDENT_NUMBER;j++) printf("%d ",overall_score[i][j]);
		printf("\n");
	}*/







}
