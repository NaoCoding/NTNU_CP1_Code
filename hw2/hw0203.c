#include <stdio.h>
#include <stdint.h>


int main(){

    int32_t s0 = 1,s1 =0,s2 =0,s3 =0,s4 = 0,s5=0,s6=0;
    int32_t n0=0,n1=0,n2=0,n3=0,n4=0,n5=0,n6=0;

    while(1){
        int32_t conc;
        printf("Please enter an integer: ");
        scanf("%d",&conc);
        if(conc == 0) break;
        else{
            if(s0==1){
                if(conc%2==0)  n3 = 1;
                else{
                    n1 = 1;
                    n2 = 1;
                }
            }
            if(s1==1){
                if(conc%2==0) n4 = 1;
                else n2 = 1;
            }
            if(s2==1){
                if(conc%2==0) n5=1;
                else n3 = 1;
            }
            if(s3==1){
                if(conc%2==0) n0=1;
                else n5 = 1;
            }
            if(s4==1){
                if(conc%2==0){
                    n2 = 1;
                    n6 = 1;
                }
                else n5 = 1;
            }
            if(s5==1){
                if(conc%2==0) n0=1;
                else n6 = 1;
            }
            if(s6==1){
                if(conc%2==0) n1=1;
                else n6 = 1;
            }
        }
        s0 = n0;
        s1 = n1;
        s2 = n2;
        s3 = n3;
        s4 = n4;
        s5 = n5;
        s6 = n6;
        n0 = 0;
        n1 = 0;
        n2 = 0;
        n3 = 0;
        n4 = 0;
        n5 = 0;
        n6 = 0;

    }
    printf("Possible States: ");
    int32_t first = 1;
    if(s0==1){
        printf("S0");
        first =0;
    }
    if(s1==1){
        if(first){
            printf("S1");
            first = 0;
        }
        else printf(", S1");
    }
    if(s2==1){
        if(first){
            printf("S2");
            first = 0;
        }
        else printf(", S2");
    }
    if(s3==1){
        if(first){
            printf("S3");
            first = 0;
        }
        else printf(", S3");
    }
    if(s4==1){
        if(first){
            printf("S4");
            first = 0;
        }
        else printf(", S4");
    }
    if(s5==1){
        if(first){
            printf("S5");
            first = 0;
        }
        else printf(", S5");
    }
    if(s6==1){
        if(first){
            printf("S6");
            first = 0;
        }
        else printf(", S6");
    }


}
