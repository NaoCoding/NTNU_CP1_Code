#include <stdio.h>
#include <stdint.h>

int32_t weisu(uint64_t target){
	if(target ==0) return 1;
	int ans = 0;
	while(target>0){
		target /= 10;
		ans += 1;
	}
	return ans;
}

uint64_t ten_weisu(uint64_t target){

	uint64_t ans = 1;
	while(target > 1){
		target --;
		ans *= 10;
	}
	return ans;

}

void output_num(uint64_t target, int32_t length, int32_t right_space){

	int32_t left_space = length - right_space - ((weisu(target)-1)*2+1);
	for(int32_t i=0;i<left_space;i++) printf(" ");

	int32_t middle = weisu(target);
	uint64_t p = ten_weisu(middle);
	while(p >= 10){
		printf("%ld ",target/p);
		target -= p*(target/p);
		p /= 10;

	}
	printf("%ld\n",target);


}

void output_line(int32_t length){

	for(int32_t i=0;i<length;i++) printf("-");
	printf("\n");

}

int32_t main(){

	int64_t a,b;

	printf("Please enter the first  number: ");
	scanf("%ld",&a);
	if(a<0||a>2147483648){
		printf("Error Input!\n");
		return 0; 
	}
	printf("Please enter the second number: ");
	scanf("%ld",&b);
	if(b<0||b>2147483648){
		printf("Error Input!\n"); 
		return 0;
	}

	uint64_t sum = a * b;
	int32_t n = weisu(a);
	if(weisu(b)>n) n = weisu(b);
	if(weisu(sum)>n) n = weisu(sum);
	n = 2 * n + 1;
	if(n<3) n = 3;

	if(a>0)output_num(a,n,0);
	else{
		for(int i=0;i<n-1;i++) printf(" ");
			printf("0\n");
	}
	
	if(b>0){
		printf("*)"); 
		output_num(b,n-2,0);
	}
	else{
		printf("*)");
		for(int i=0;i<n-3;i++) printf(" ");
			printf("0\n");
	}
	output_line(n);

	uint64_t temp_b = b;
	if(!(b<10||a==0||sum<10)){
		for(int32_t i=0;i<weisu(b);i++){
		output_num((temp_b%10)*a,n,i*2);
		temp_b /= 10;

	}
	output_line(n);
	}
	

	

	if(sum>0) output_num(sum,n,0);
	else{
		for(int i=0;i<n-1;i++) printf(" ");
			printf("0\n");
	}




}