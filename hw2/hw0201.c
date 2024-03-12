#include <stdio.h>
#include <stdint.h>

int32_t main(){

    int32_t n;
    long double ans = 0;
    long double f = 0;
    printf("Please enter n (16-bits unsigned): ");
    scanf("%d",&n);
    if(n<0){
        printf("n is invalid!");
        return 0;
    }
    for(int32_t i=1;i<=n;i++){
         printf("n = %d: %.15LF (%.15LF)\n",i,1+f,f-0.414213562373095);
         f = 1/(2+f);
    }




}
