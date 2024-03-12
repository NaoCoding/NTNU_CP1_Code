#include "frac.h"


int64_t gcd(int64_t a,int64_t b){

	if(a%b==0)return b;
	return gcd(b,a%b);

}


static int64_t mom = 0 , son = 0;

int32_t frac_add( int32_t *x, int32_t *y,int32_t a, int32_t b, int32_t c, int32_t d ){
	if(b==0||d==0) return -1;
	mom = b * d;
	son = a * d + b * c;
	if(son==0){
		*x = 0;
		*y = 1;
	}
	int32_t lack = 0;
	if(son<0){
		lack += 1;
		son *= -1;
	}
	if(mom<0){
		lack += 1;
		mom *= -1;
	}
	int64_t rep = mom > son ? gcd(mom,son) : gcd(son,mom);
	if(son/rep>2147483647||son/rep<-2147483648||mom/rep>2147483647||mom/rep<-2147483648) return -1;
	*x = son/rep;
	if(lack%2) *x *= -1;
	*y = mom/rep;
	return 0;
}
int32_t frac_del( int32_t *x, int32_t *y,int32_t a, int32_t b, int32_t c, int32_t d ){
	if(b==0||d==0) return -1;
	mom = b * d;
	son = a * d - b * c;
	if(son==0){
		*x = 0;
		*y = 1;
	}
	int32_t lack = 0;
	if(son<0){
		lack += 1;
		son *= -1;
	}
	if(mom<0){
		lack += 1;
		mom *= -1;
	}
	int64_t rep = mom > son ? gcd(mom,son) : gcd(son,mom);
	if(son/rep>2147483647||son/rep<-2147483648||mom/rep>2147483647||mom/rep<-2147483648) return -1;
	*x = son/rep;
	if(lack%2) *x *= -1;
	*y = mom/rep;
	return 0;
}
int32_t frac_mul( int32_t *x, int32_t *y,int32_t a, int32_t b, int32_t c, int32_t d ){
	if(b==0||d==0) return -1;
	mom = b * d;
	son = a * c;
	if(son==0){
		*x = 0;
		*y = 1;
	}
	int32_t lack = 0;
	if(son<0){
		lack += 1;
		son *= -1;
	}
	if(mom<0){
		lack += 1;
		mom *= -1;
	}
	int64_t rep = mom > son ? gcd(mom,son) : gcd(son,mom);
	if(son/rep>2147483647||son/rep<-2147483648||mom/rep>2147483647||mom/rep<-2147483648) return -1;
	*x = son/rep;
	if(lack%2) *x *= -1;
	*y = mom/rep;
	return 0;
}
int32_t frac_div( int32_t *x, int32_t *y,int32_t a, int32_t b, int32_t c, int32_t d ){
	if(b==0||d==0||c==0) return -1;
	mom = b * c;
	son = a * d;
	if(son==0){
		*x = 0;
		*y = 1;
	}
	int32_t lack = 0;
	if(son<0){
		lack += 1;
		son *= -1;
	}
	if(mom<0){
		lack += 1;
		mom *= -1;
	}
	int64_t rep = mom > son ? gcd(mom,son) : gcd(son,mom);
	if(son/rep>2147483647||son/rep<-2147483648||mom/rep>2147483647||mom/rep<-2147483648) return -1;
	*x = son/rep;
	if(lack%2) *x *= -1;
	*y = mom/rep;
	return 0;
}