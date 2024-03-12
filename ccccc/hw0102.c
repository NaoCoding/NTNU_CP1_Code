#include <stdio.h>
#include <stdint.h>


int main(){

    int32_t n,m;
    printf("Please enter the first  number: ");
    scanf("%d",&n);
    if(n<0||n>99){
        printf("Wrong input, your input must between 0 ~ 99.\n");
        return 0;
    }
    printf("Please enter the second number: ");
    scanf("%d",&m);

    if(!(n<0||n>99|m<0||m>99)){
        int32_t sum = n*m;
    if(sum>999){
        if(n>9)printf("      %d %d\n",n/10,n%10);
        else printf("        %d\n",n);
        if(m>9)printf("*)    %d %d\n",m/10,m%10);
        else printf("*)      %d\n",m);
        printf("---------\n");
        int32_t up1 = 0, up2 =0, up3 = n*(m%10);
        up2 = up3/10;
        up3 = up3%10;
        up1 = up2/10;
        up2 = up2%10;
        if(up1>0) printf("    %d %d %d",up1,up2,up3);
        else if(up2>0) printf("      %d %d",up2,up3);
        else printf("        %d",up3);
        printf("\n");
        up3 = n*(m/10);
        up2 = up3/10;
        up3 = up3%10;
        up1 = up2/10;
        up2 = up2%10;
        if(up1>0) printf("  %d %d %d  ",up1,up2,up3);
        else if(up2>0) printf("    %d %d  ",up2,up3);
        else printf("      %d  ",up3);
        printf("\n---------\n");
        up3 = sum/10;
        sum = sum%10;
        up2 = up3/10;
        up3 = up3%10;
        up1 = up2/10;
        up2 = up2%10;
        if(up1>0) printf("  %d %d %d %d",up1,up2,up3,sum);
        else if(up2>0) printf("    %d %d %d",up2,up3,sum);
        else if(up3>0)printf("      %d %d",up3,sum);
        else printf("%d",sum);

            }
        else if(sum>99){
            if(n>9)printf("    %d %d\n",n/10,n%10);
        else printf("      %d\n",n);
        if(m>9)printf("*)  %d %d\n",m/10,m%10);
        else printf("*)    %d\n",m);
        printf("-------\n");
        if(m>9){
            int32_t up1 = 0, up2 =0, up3 = n*(m%10);
        up2 = up3/10;
        up3 = up3%10;
        up1 = up2/10;
        up2 = up2%10;
        if(up1>0) printf("  %d %d %d",up1,up2,up3);
        else if(up2>0) printf("    %d %d",up2,up3);
        else printf("      %d",up3);
        printf("\n");
        up3 = n*(m/10);
        up2 = up3/10;
        up3 = up3%10;
        up1 = up2/10;
        up2 = up2%10;
        if(up2>0) printf("  %d %d  ",up2,up3);
        else printf("    %d  ",up3);
        printf("\n-------\n");
        }
        int32_t up3 = sum/10;
        sum = sum%10;
        int32_t up2 = up3/10;
        up3 = up3%10;
        int32_t up1 = up2/10;
        up2 = up2%10;
        if(up2>0) printf("  %d %d %d",up2,up3,sum);
        else if(up3>0)printf("    %d %d",up3,sum);
        else printf("%d",sum);
        }
        else if((sum>9||n>9||m>9)){
            if(n>9)printf("  %d %d\n",n/10,n%10);
        else printf("    %d\n",n);
        if(m>9)printf("*)%d %d\n",m/10,m%10);
        else printf("*)  %d\n",m);
        printf("-----\n");
        if(m>9&&n>0){
            int32_t up1 = 0, up2 =0, up3 = n*(m%10);
        up2 = up3/10;
        up3 = up3%10;
        up1 = up2/10;
        up2 = up2%10;
        if(up2>0) printf("  %d %d",up2,up3);
        else printf("    %d",up3);
        printf("\n");
        up3 = n*(m/10);
        up2 = up3/10;
        up3 = up3%10;
        up1 = up2/10;
        up2 = up2%10;
        if(up2>0) printf("%d %d  ",up2,up3);
        else printf("  %d  ",up3);
        printf("\n-----\n");
        }
        int32_t up3 = sum/10;
        sum = sum%10;
        int32_t up2 = up3/10;
        up3 = up3%10;
        int32_t up1 = up2/10;
        up2 = up2%10;
        if(up3>0)printf("  %d %d",up3,sum);
        else printf("    %d",sum);
        }
        else{
            printf("  %d\n",n);
            printf("*)%d\n",m);
            printf("---\n");
            printf("  %d",n*m);
        }
        printf("\n");
    }
    else printf("Wrong input, your input must between 0 ~ 99.\n");

    return 0;
}



