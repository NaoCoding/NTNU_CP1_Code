#include <stdio.h>
#include <stdint.h>

int main(){


    double x1,x2,y1,y2;
    printf("Please enter the point A (x,y): ");
    scanf("%lf,%lf",&x1,&y1);
    printf("Please enter the point B (x,y): ");
    scanf("%lf,%lf",&x2,&y2);

    double m = (y1-y2)/(x1-x2);
    double y = y2-(m*x2) , x = y/m;
    if(x<0) x = -1 * x;
    if(y<0) y = -1 * y;
    double area = x*y/2.00;
    // printf("%f %f %f",x,y,m);
    if(area>0&&m!=0)printf("Area: %.2lf\n",area);
    else printf("Area: 0\n");
    return 0;
}

