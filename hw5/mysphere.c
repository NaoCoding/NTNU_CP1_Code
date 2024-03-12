#include "mysphere.h"

int32_t get_cap_area( double r, double a, double b, double c,double d, double *pArea ){

	if(r<=0)return -1;
	if(a==b&&b==c&&c==0)return -1;
	long double distance = -d / sqrt((a*a+b*b+c*c));
	if(distance>=r){
		*pArea = 0;
		return 0;
	}
	long double gg = r*r - distance * distance;
	*pArea = gg*3.14159265359;
	if(*pArea==0) return 0;
	return 1;


}

