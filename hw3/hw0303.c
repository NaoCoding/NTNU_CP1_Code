#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

int16_t minus_end = 1;
void BinaryForm(int64_t target, int32_t binary_now){
    if(binary_now==32){
        printf("%d\n",abs(target));
        return ;
    }
    if(binary_now==1){
        printf("%d",!(target>=0));
        BinaryForm(target,2);
    }
    else{
        if(target>=0)printf("%ld",abs(target)/(int64_t)pow(2,32-binary_now));
        else{
            if(abs(target)==(int64_t)pow(2,32-binary_now)&&minus_end){
                printf("%ld",abs(target)/(int64_t)pow(2,32-binary_now));
                minus_end = 0;
            }
            else{
                printf("%d",!(abs(target)/(int64_t)pow(2,32-binary_now)));
            }
        }

            if(!(binary_now%8)) printf(" ");
            int64_t next = target%(int64_t)pow(2,32-binary_now);
            BinaryForm(next,binary_now+1);

    }


}

int main(){

printf("Please enter the number: ");
long double target;
scanf("%LF",&target);
if(target!=(int64_t)target){
    printf("Enter number is out of range or not integer!\n");
    return 0;
}
if(target>2147483647||target<-2147483648){
    printf("Enter number is out of range or not integer!\n");
    return 0;
}

BinaryForm((int64_t)target,1);



}
