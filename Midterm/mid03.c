#include <stdio.h>
#include <stdint.h>

//static int patterns[5] = {1,32,65,9,78};
static int patterns_done[3] = {0,0,0};
static int sevens = 0;
static int fives = 0;
static int rule[3] = {0,0,0};
static int triple_six = 0;
static int front_four = 0;

int main(){

	int32_t last_cmd = -1,last_last_cmd = -2;
	for(;;){

		int32_t cmd;
		printf("Please input the digit: ");
		scanf("%d",&cmd);
		

		if(cmd==-1) break;
		if(cmd==1){
			if(!patterns_done[0]) patterns_done[0] = 1;

		}
		else if(cmd==2){
			if(last_cmd==3){
				if(!patterns_done[0]) patterns_done[0] = 1;
			}
		}
		else if(cmd==3){
			if(fives==1) rule[1] = 1;
		}

		else if(cmd==4){

			front_four = 1;
		}
		else if(cmd==5){
			if(fives==1) fives =0;
			else fives=1;
			if(last_cmd==6&&patterns_done[0]){
				patterns_done[1] = 1;
			}
		}
		else if(cmd==6){

			if(last_last_cmd==last_cmd&&last_cmd==6){
				if(front_four = 1){
					triple_six = 1;
				}
			}
		}
		else if(cmd==7){
			sevens = 1;

		}
		else if(cmd==8){
			if(last_cmd==7&&patterns_done[1]){
				patterns_done[2] = 1;
				rule[0] = 1;
			}
			if(triple_six) rule[2] = 1;
		}
		else if(cmd==9){
			if(patterns_done[1]){
				patterns_done[2] = 1;
				rule[0] = 1;
			}
		}


		last_cmd = cmd;
		last_last_cmd = last_cmd;

	}
	if(rule[0]==0) printf("Rule1 ");
	if(!rule[1]) printf("Rule2 ");
	if(!rule[2]) printf("Rule3 ");
	if(rule[0]&&rule[1]&&rule[2]) printf("SUCCESS!\n");
	else{
		printf("not follow!\n");
	}


}