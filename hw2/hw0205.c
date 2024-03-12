#include <stdio.h>
#include <stdint.h>
int32_t width, height, side_width ,num , length;

void printf_space(int32_t n){

    for(int32_t i=0;i<n;i++) printf(" ");
}

void printf_node(){

    printf("*");
    for(int i=0;i<side_width;i++) printf("-");
    printf("*");

}

void output_node(int32_t nodes, int32_t between){

    int32_t left_space = (width - nodes*length - (nodes-1)*between)/2;
    printf_space(left_space);
    for(int32_t i=0;i<nodes;i++){
        printf_node();
        if(i<nodes-1) printf_space(between);
    }
    printf_space(left_space);
    printf("\n");
}

void prinft_exceed_node(int32_t between){

    printf("*");
    printf_space(between);
    for(int32_t i=0;i<num-1;i++){
        printf_node();
        printf_space(between);
    }
    printf("*");
    printf("\n");


}

void output_side(int32_t sides,int32_t between,int32_t cont_between,int32_t direction){

    int32_t left_space = (width - (sides*2 + between*sides + cont_between*(sides-1)))/2;
    printf_space(left_space);
    for(int32_t i=0;i<sides;i++){
        if(direction){
            printf("/");
            printf_space(between);
            printf("\\");
        }
        else{
           printf("\\");
            printf_space(between);
            printf("/");
        }
        if(i<sides-1) printf_space(cont_between);
    }
    printf("\n");

}

int main(){

    printf("Please input the length: ");
    scanf("%d",&length);
    if(length<3){
        printf("The length is invalid!\n");
        return 0;
    }
    printf("Please input the number of layer: ");
    scanf("%d",&num);
    if(num<1){
        printf("The number of layer is invalid!\n");
        return 0;
    }

    side_width = length - 2;
    width = 4*num + (3+(num-1)*4)*side_width;
    height = (2+(num-1)*4)*side_width + (3+(num-1)*4);

    if(width>80){
        printf("The Width is larger than 80, which is invalid!\n");
        return 0;
    }
    //printf("%d %d",width,height);

    int32_t mid_height = (height-1)/2;
    int32_t exceed_node = 0,direction = 1;

    for(int32_t i=0;i<height;i++){
        
        int32_t t = i;
        if(i>height/2 - 1){
            t = height - i ; 
        }

        if(i%(side_width+1)==0){
            if(t/(side_width+1)+1<=num)output_node(t/(side_width+1)+1,length+2*side_width);
            else{
                if(!direction) direction = 1;
            else direction = 0;
                if(!exceed_node){
                    prinft_exceed_node(length+2*side_width);
                    exceed_node = 1;
                }
                else{
                    output_node(num,length+2*side_width);
                    exceed_node = 0;
                }

            }
        }
        else{

            // node , in_node, out_node, direction 
            if(t == height - i) t -= 1;
            int32_t fnode = t/(side_width+1)+1;
            int32_t in_node;
            int32_t out_node;
            if(direction) in_node = length + 2*((i-1)%(side_width+1));
            else in_node = length + 2*(side_width-i%(side_width+1));
            if(fnode>num) fnode = num;

            if(direction) out_node = length + 2*(side_width-i%(side_width+1));
            else out_node = length + 2*((i-1)%(side_width+1));

            output_side(fnode,in_node,out_node,direction);
            
            }


    }
    



}

