#include <stdio.h>
#include <stdint.h>

int32_t main(){

    long double start_m, start_y , end_m , end_y;
    long double initial, month,annual_return;
    long double rate= 0;
    long double earn = 0;

    printf("Initial Investment:           ");
    scanf("%LF",&initial);
    printf("Recurring Monthly Investment: ");
    scanf("%LF",&month);
    printf("Start Month:                  ");
    scanf("%LF",&start_m);
    printf("Start Year:                   ");
    scanf("%LF",&start_y);
    printf("End Month:                    ");
    scanf("%LF",&end_m);
    printf("End Year:                     ");
    scanf("%LF",&end_y);
    printf("Annual Rate of Return (%%):    ");
    scanf("%LF",&annual_return);
    if(initial<1 || initial > 10000000 || initial != (int64_t) initial){
        printf("Initial Investment is invalid!\n");
        return 0;
    }

    if(initial<0 || month > 10000000|| month != (int64_t) month){
        printf("Recurring Monthly Investment is invalid!\n");
        return 0;
    }
    if(start_m<1 || start_m > 12|| start_m != (int64_t) start_m){
        printf("Start Month is invalid!\n");
        return 0;
    }
    if(start_y<1 || start_y > 10000|| start_y != (int64_t) start_y){
        printf("Start Year is invalid!\n");
        return 0;
    }
    if(end_m<1 || end_m > 12|| end_m != (int64_t) end_m){
        printf("End Month is invalid!\n");
        return 0;
    }
    if(end_y<1 || end_y > 10000|| end_y != (int64_t) end_y){
        printf("End Year is invalid!\n");
        return 0;
    }
    if(annual_return<1 || annual_return > 100|| annual_return != (int64_t) annual_return){
        printf("Rate is invalid!\n");
        return 0;
    }
    if((start_m==end_m&&start_y==end_y) || start_y>end_y){
        printf("The range of start and end date is less than 1 month!\n");
        return 0;
    }


    printf("--- Output ---\n");
    if(start_m>9)printf("%.0LF.%.0LF) %.0LF/%.0LF/%.0LF/0%%",start_y,start_m,initial,initial+earn,earn);
    else printf("%.0LF.0%.0LF) %.0LF/%.0LF/%.0LF/0%%",start_y,start_m,initial,initial+earn,earn);
    printf("\n");
    start_m ++ ;
    for(int64_t i=start_y;i<=end_y;i++){
        while(1){
            if(i==end_y && start_m>=end_m) break;
        if(start_m>12) break;

        earn += (initial+earn) * (0.01*annual_return/12);
        initial += month;
        rate = (earn)/(initial+earn)*100;
        
        if(start_m>9)printf("%ld.%.0LF) ",i,start_m);
        else printf("%ld.0%.0LF) ",i,start_m);

        if(initial/100000>10000000000||(initial+earn)/100000>10000000000||earn/100000>10000000000){
            printf("*/*/*/*/");
        }
        else{
            printf("%ld/%ld/%ld/",(int64_t)initial,(int64_t)(initial+earn),(int64_t)(earn));
        int64_t cont = rate*1000;
        if(cont%10>4){
            cont = cont/10 + 1;
        } else cont = cont/10;
        if(cont%10!=0)printf("%.2LF",rate);
        else if(cont%100!=0) printf("%.1LF",rate);
        else printf("%.0LF",rate);
        }


        
        printf("%%");

        
        printf("\n");
        start_m ++;
        }

        if(i==end_y&&start_m>=end_m) break;
        start_m = 1;
    }
    printf("\n");




}
