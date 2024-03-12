#include <gtk/gtk.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "diceRolls.h"


int high_calcl(int j,int dice_choosed[],int dice_num,int dice_result[]){
	while(dice_choosed[j]!=0){
			j+=1;
			if(j>=dice_num) break;
		}
		for(int k=1;k<dice_num;k++){
			if(dice_result[k]>dice_result[j]&&dice_choosed[k]==0) j = k;
		}
	return j;

}

int low_calcl(int j,int dice_choosed[],int dice_num,int dice_result[]){

	while(dice_choosed[j]!=0){
			j+=1;
			if(j>=dice_num) break;
		}
		for(int k=1;k<dice_num;k++){
			if(dice_result[k]<dice_result[j]&&dice_choosed[k]==0) j = k;
		}
		return j;


}

int dice____(int dice_face){
	return rand()%dice_face + 1;
}