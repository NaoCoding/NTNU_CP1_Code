#include <stdio.h>
#include <stdint.h>

static int64_t n,l;

void print_color(int64_t edges){

	int32_t color_now = 0;


	for(int i=0;i<n-edges/2;i++){
		for(int j=0;j<l*2+1;j++) printf(" ");
	}

	printf("|");
	for(int i=0;i<edges-1;i++){

		for(int j=0;j<l*2;j++){
			if(color_now==0) printf("\033[41m \033[0m");
			else if(color_now==2) printf("\033[44m \033[0m");
			else printf("\033[42m \033[0m");
		}
			if(i>=(edges-1)/2) color_now -= 1;
			else color_now += 1;
			if(color_now>2) color_now = 0;
			if(color_now<0) color_now = 2;
			printf("|");
	}
	printf("\n");

}

void print_edge(int64_t edges){

	for(int i=0;i<n-edges/2;i++){
		for(int j=0;j<l*2+1;j++) printf(" ");
	}
	

	printf("+");

	for(int i=0;i<edges-1;i++){
		for(int j=0;j<l*2;j++) printf("-");
			printf("+");
	}
	printf("\n");



}

int main(){


	printf("Please enter n: ");
	scanf("%ld",&n);
	printf("Please enter the edge length: ");
	scanf("%ld",&l);
	if(n<1||l<1) printf("Enter numbers are invalid to create the result!\n");

	for(int i=1;i<=n;i++){
		print_edge((i*2));
		for(int j=0;j<l;j++){
			print_color(i*2);
		}
	}
	for(int i=n;i>=1;i--){
		print_edge((i*2));
		for(int j=0;j<l&&i!=1;j++){
			print_color((i-1)*2);
		}
	}


}