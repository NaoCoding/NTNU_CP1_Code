#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "hw0304.h"

int main(){

	printf("Please enter the disk number (2-20): ");
	int n;
	scanf("%d",&n);
	if(n<=20&&n>=2)transfer_plate(n,1,2,3);
	else printf("The number is invalid!\n");
	


}