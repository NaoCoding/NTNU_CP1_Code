#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

static int64_t flowed = 0;

void sisiu(int64_t array1[],int64_t array2[],int64_t a,int64_t b){
	int64_t num = -1;
	for(int64_t i= 0;i<=a;i++){
		if(array1[i]!=0){
			num = array1[i] > 0 ? array1[i]:-array1[i];
			break;
		}
	}
	if(num==-1)return;
	
	//printf("%d",num);
	for(int64_t i=2;i<=num;i++){
		int32_t done = 1;
		for(int64_t j=0;j<=a;j++){

			if(array1[j]%i){
				done = 0;
				break;
			}
		}
		for(int64_t j=0;j<=b;j++){
			if(array2[j]%i){
				done = 0;
				break;
			}
		}

		if(done){

			for(int64_t j=0;j<=a;j++) array1[j] /= i;
			for(int64_t j=0;j<=b;j++) array2[j] /= i;
			num /= i;
			i -= 1;
		}
		
	}

}

void output_line(int64_t a){

	while(a){
		printf("-");
		a -= 1;
	}
	printf("\n");

}

void countflowed(int64_t array1[],int64_t array2[],int64_t a,int64_t b){

	while(flowed <= a && flowed <= b){
		if(array1[flowed] == array2[flowed] && array2[flowed] == 0) flowed += 1;
		else return;
	}


}

int64_t number_length(int64_t target){

	if(target<0) target *= -1;
	if(target>9) return number_length(target/10) + 1;
	if(target) return 1;
	return 0;
}

int64_t countline(int64_t array1[],int64_t array2[],int64_t a,int64_t b){

	int64_t bigger[2];
	bigger[0] = 0;
	bigger[1] = 0;
	int64_t las = 1;
	for(int64_t i=a;i>=0;i--){


		if(array1[i]){
			if(!las && array1[i] != 0)bigger[0] += 1;
			else if(las&&array1[i]<0) bigger[0] += 1;
			if(i != 0 && array1[i]!=1 && array1[i]!=-1)bigger[0] += number_length(array1[i]);
			else if(i==0)bigger[0] += number_length(array1[i]);
				if(i>1) bigger[0] += number_length(i) + 2;
				else if(i==1) bigger[0] += 1;
			las = 0;
		}

	}
	las = 1;
	for(int64_t i=b;i>=0;i--){


		if(array2[i]){
			if(!las && array2[i] != 0)bigger[1] += 1;
			else if(las&&array2[i]<0) bigger[1] += 1;
			if(i != 0 && array2[i]!=1 && array2[i]!=-1)bigger[1] += number_length(array2[i]);
			else if(i==0)bigger[1] += number_length(array2[i]);
				if(i>1) bigger[1] += number_length(i) + 2;
				else if(i==1) bigger[1] += 1;
			las = 0;
		}

	}
	int64_t answer = 0;
	while(bigger[0]>0|| bigger[1]>0){
		answer += 1;
		bigger[0] -= 1;
		bigger[1] -= 1;
	}
	return answer;

}

void output(int64_t array[],int64_t length){
	int64_t las = 1;
	for(int64_t i=length;i>=0;i--){
		if(!array[i]&&!i&&las)printf("0");

		if(array[i]){
			if(!las && array[i] > 0)printf("+");
			if(i != 0 && array[i]!=1 && array[i]!=-1)printf("%ld",array[i]);
			else if(i==0)printf("%ld",array[i]);
			else if(array[i]==-1) printf("-");
				if(i-flowed>1) printf("x^%ld",i-flowed);
				else if(i-flowed==1) printf("x");
			las = 0;
		}

	}
	printf("\n");


}

int main(){

	long double ld_degree[2];
	int64_t degree[2];
	int32_t errors = 0;
	char temps[1000];
	

	printf("Please enter f(x) degree: ");
	scanf("%LF",&ld_degree[0]);
	
		if(ld_degree[0]!=(int64_t)ld_degree[0] || ld_degree[0]<0 || ld_degree[0] > 4294967295){
			errors = 1;
			if(errors){
		printf("Error Input, the degree is invalid!\n");
		return 0;
	}
		}
		else{
			degree[0] = ld_degree[0];
		}
	long double *ld_f = calloc(degree[0]+1,sizeof(long double));
	printf("Please enter f(x) coefficients: ");
	if(!errors){

		for(int64_t i=ld_degree[0];i>=0;i--) scanf("%LF",&ld_f[i]);
	}

	int32_t more[2] = {0};
	scanf("%[^\n]%n",temps,&more[0]);
	printf("Please enter g(x) degree: ");
	scanf("%LF",&ld_degree[1]);
	
	if(ld_degree[1]!=(int64_t)ld_degree[1] || ld_degree[1]<0 || ld_degree[1] > 4294967295){
			errors = 1;
			if(errors){
		printf("Error Input, the degree is invalid!\n");
		return 0;
	}
		}
		else{
			
			degree[1] = ld_degree[1];
			
		}
	long double *ld_g = calloc(degree[1]+1,sizeof(long double));
	printf("Please enter g(x) coefficients: ");
	if(!errors){

		for(int64_t i=ld_degree[1];i>=0;i--) scanf("%LF",&ld_g[i]);
	}
	scanf("%[^\n]%n",temps,&more[1]);

	
	if(errors){
		printf("Error Input, the degree is invalid!\n");
		return 0;
	}
	if(more[0]-1> 0|| more[1]-1> 0){
		//printf("%d %d",more[0],more[1]);
		printf("Wrong Input, the coefficients are more than degree!\n");
		return 0;
	}

	/*for(int i=0;i<degree[0]+1;i++)printf("%LF ",ld_f[i]);
	printf("\n");
	for(int i=0;i<degree[1]+1;i++)printf("%LF ",ld_g[i]);
	printf("\n");*/

	int64_t **f = calloc(2,sizeof(int64_t *)),**g= calloc(2,sizeof(int64_t *));
	for(int32_t i=0;i<2;i++){
		f[i] = calloc(degree[0]+1,sizeof(int64_t));
		g[i] = calloc(degree[1]+1,sizeof(int64_t));
	}
	
	for(int64_t i=degree[0];i>=0;i--){
		//printf("%LF\n",ld_g[0]);
		if(i==degree[0]&&!ld_f[i]){
			printf("The input is invalid,first coefficients should not be 0.\n");
			return 0;
		}
		if(ld_f[i] < -2147483648 || ld_f[i] > 2147483647 || ld_f[i]!=(int32_t)ld_f[i]){
			printf("The coefficients is out of range!\n");
			printf("%LF %d",ld_f[i],(int32_t)ld_f[i]);
			return 0;
		}
		f[0][i] = ld_f[i];
		if(i!=0){
			f[1][i-1] = f[0][i] * (i);
		}
	}
	//printf("%LF\n",ld_g[0]);

	for(int64_t i=degree[1];i>=0;i--){
		//printf("%LF %ld\n",ld_g[i],i);
		if(i==degree[1]&&!ld_g[i]){
			printf("The input is invalid,first coefficients should not be 0.\n");
			return 0;
		}
		if(ld_g[i] < -2147483648 || ld_g[i] > 2147483647|| ld_g[i]!=(int32_t)ld_g[i]){
			printf("The coefficients is out of range!\n");
			printf("%LF %d",ld_g[i],(int32_t)ld_g[i]);
			return 0;
		}
		g[0][i] = ld_g[i];
		if(i!=0){
			g[1][i-1] = g[0][i] * (i);
		}
	}



	printf("f(x): ");
	output(f[0],degree[0]);
	printf("g(x): ");
	output(g[0],degree[1]);

	int64_t *multiply_ = calloc(degree[0] + degree[1] + 1,sizeof(int64_t));
	int64_t *fded_mulg = calloc(degree[0] + degree[1] + 1,sizeof(int64_t));
	int64_t *gded_mulf = calloc(degree[0] + degree[1] + 1,sizeof(int64_t));
	
	for(int64_t i=0;i<degree[0] + degree[1] + 1;i++){
		multiply_[i] = 0;
		fded_mulg[i] = 0;
		gded_mulf[i] = 0;
	}
	
	for(int64_t i=degree[0]-1;i>=0;i--){
		for(int64_t j=degree[1];j>=0;j--){
			fded_mulg[i+j] += f[1][i] * g[0][j];
			multiply_[i+j] += f[1][i]  *g[0][j];
		}
	}

	for(int64_t i=degree[1]-1;i>=0;i--){
		for(int64_t j=degree[0];j>=0;j--){
			gded_mulf[i+j] += g[1][i] * f[0][j];
			multiply_[i+j] += g[1][i] * f[0][j];
		}
	}


	printf("(f(x)g(x))': ");
	output(multiply_,degree[0] + degree[1]);

	int64_t *mul_gg = calloc(degree[1] + degree[1] + 1,sizeof(int64_t));
	for(int64_t i=0;i<degree[1]+degree[1]+1;i++) mul_gg[i] = 0;
	for(int64_t i=degree[1];i>=0;i--){
		for(int64_t j=degree[1];j>=0;j--){
			mul_gg[i+j] += g[0][i] * g[0][j];
		}
	}
	for(int64_t i=0;i<degree[0] + degree[1] + 1;i++){
		multiply_[i] -= gded_mulf[i]; 
		multiply_[i] -= gded_mulf[i]; 
	}

	
	countflowed(multiply_,mul_gg,degree[0] + degree[1],degree[1] + degree[1]);
	sisiu(multiply_,mul_gg,degree[0] + degree[1],degree[1] + degree[1]);
	printf(" f(x)    ");
	if(!countline(multiply_,multiply_,degree[0] + degree[1],degree[0] + degree[1])){
		printf("0\n");
	}
	else{
		output(multiply_,degree[0] + degree[1]);
	}
	
	
	printf("(----)': ");
	
	output_line(countline(multiply_,mul_gg,degree[0] + degree[1],degree[1] + degree[1]));
	printf(" g(x)    ");
	output(mul_gg,degree[1] + degree[1]);

	//output(mul_gg,degree[1] + degree[1] + 1);
}