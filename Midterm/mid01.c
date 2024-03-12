#include <stdio.h>
#include <stdint.h>


static long double start_y ,start_m,start_d,start_h,start_min,start_sec;
static long double end_y ,end_m,end_d,end_h,end_min,end_sec;
static int pin_month_day[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
static int ren_month_day[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};


int pin_ren(long double y, long double m){

	if((uint64_t)y%400==0) return ren_month_day[(uint64_t)m];
	if((uint64_t)y%4==0 && (uint64_t)y%100 !=0)	return ren_month_day[(uint64_t)m];
	return pin_month_day[(uint64_t)m];


}

int timesup(){

	if(start_y==end_y && start_m==end_m&&start_d==end_d&&start_h==end_h&&start_min==end_min&&(uint64_t)start_sec%60==end_sec) return 1;
	return 0;


}

long double time_calc(){
long double total_time = 0;

while(start_y<end_y-1){

	if((uint64_t)start_y%400==0) total_time += 366*24*60*60;
	else if((uint64_t)start_y%4==0&&(uint64_t)start_y%100!=0) total_time += 366*24*60*60;
	else total_time += 365*24*60*60;
	start_y += 1;
}

while(start_y<=end_y){
		while(start_m<=12){
				while(start_d<=pin_ren(start_y,start_m)){
				while(start_h <= 23){
					while(start_min <60){
						while(start_sec <60){
							total_time += 1;
							start_sec += 1;
							if(timesup()) return total_time;
						}
						//printf("%LF \n",total_time);
						start_min += 1;
						start_sec = 0;
						if(timesup()) return total_time;

					}
					start_h += 1;
					start_min = 0;
					if(timesup()) return total_time;
				}
				start_d += 1;
				start_h = 0;
				if(timesup()) return total_time;
			}
			
			start_m+=1;
			start_d = 1;if(timesup()) return total_time;
		}
		start_y += 1;
		start_m = 1;if(timesup()) return total_time;
	}


}

int main(){

	

	printf("Start Time: ");
	scanf("%LF-%LF-%LF %LF:%LF:%LF",&start_y ,&start_m,&start_d,&start_h,&start_min,&start_sec);
	printf("End Time:   ");
	scanf("%LF-%LF-%LF %LF:%LF:%LF",&end_y ,&end_m,&end_d,&end_h,&end_min,&end_sec);

	

	

	if(start_y>end_y){
		printf("Duration: 0 (Start Time is later than end time!)");
		return 0;
	}
	

	printf("Duration: %.0LF sec\n",time_calc());


}