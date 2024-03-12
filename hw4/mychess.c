#include "mychess.h"

static int32_t side_ = -1; // 0 red down
static int32_t general_position[2][2];
static int32_t horse_position[2][2];
static int32_t chariot_position[2][2];
static int32_t cannon_position[2][2];
static int32_t soldier_position[5][2];
static int32_t move_count = 0;

int32_t empty_checker(int32_t board[10][9],int32_t target_i,int32_t target_j){

	if(board[target_i][target_j]!=EMPTY) return 0;
	return 1;

}

int32_t black_checker(int32_t board[10][9],int32_t target_i,int32_t target_j){

	if(board[target_i][target_j]>=11 && board[target_i][target_j]<=17) return 1;
	return 0;

}

void debug_mode(int32_t board[10][9]){

	for(int32_t i=9;i>=0;i--){
		for(int32_t j=0;j<9;j++)printf("%2d ",board[i][j]);
			printf("\n");
	}

}

void initial_position(){

	for(int32_t i=0;i<5;i++){
		for(int32_t j=0;j<2;j++){
			if(i<=1){
				general_position[i][j] = -1;
				horse_position[i][j] = -1;
				chariot_position[i][j] = -1;
				cannon_position[i][j] = -1;
			}
			soldier_position[i][j] = -1;
		}
	}


}

int32_t less(int32_t a ,int32_t b){
	return a > b ? b + 1:a + 1;
}
int32_t more(int32_t a,int32_t b){
	return a > b ? a : b;
}

int32_t is_it_check(int32_t board[10][9],int32_t target_i,int32_t target_j){

	if(target_i==general_position[1][0]){

		for(int32_t i = less(target_j,general_position[1][1]);i<more(target_j,general_position[1][1]);i++){
			if(!empty_checker(board,target_i,i)) return 0;
		}
		return 1;		
	}
	else if(target_j==general_position[1][1]){

		for(int32_t i = less(target_i,general_position[1][0]);i<more(target_i,general_position[1][0]);i++){
			if(!empty_checker(board,i,target_j)) return 0;
		}	

		return 1;
	}
	else return 0;


}



int32_t horse_checker(int32_t board[10][9],int32_t target_i,int32_t target_j ){

	if(target_i<0||target_i>9)return 0;
	if(target_j<0||target_j>8)return 0;
	if(empty_checker(board,target_i-1,target_j)){
		if(target_i-2==general_position[1][0]&&target_j-1==general_position[1][1])return 1;
		if(target_i-2==general_position[1][0]&&target_j+1==general_position[1][1])return 1;

	}
	if(empty_checker(board,target_i,target_j-1)){
		if(target_i-1==general_position[1][0]&&target_j-2==general_position[1][1])return 1;
		if(target_i+1==general_position[1][0]&&target_j-2==general_position[1][1])return 1;
	}
	if(empty_checker(board,target_i,target_j+1)){

		if(target_i-1==general_position[1][0]&&target_j+2==general_position[1][1])return 1;
		if(target_i+1==general_position[1][0]&&target_j+2==general_position[1][1])return 1;
	}
	if(empty_checker(board,target_i+1,target_j)){

		if(target_i+2==general_position[1][0]&&target_j-1==general_position[1][1])return 1;
		if(target_i+2==general_position[1][0]&&target_j+1==general_position[1][1])return 1;
	}
	
	


	return 0;

}

int32_t cannon_mate_check(int32_t board[10][9],int32_t target_i,int32_t target_j,int32_t i_or_j){

	int32_t middlething = 0;
	if(!i_or_j){
		middlething = 0;
		for(int32_t i=target_j-1;i>=0;i--){
			if(!empty_checker(board,target_i,i)) middlething += 1;
			if(middlething==2){
				if(target_i==general_position[1][0]&&i==general_position[1][1]) return 1;
			}
		}


		middlething = 0;
		for(int32_t i=target_j+1;i<9;i++){
			if(!empty_checker(board,target_i,i)) middlething += 1;
			if(middlething==2){
				if(target_i==general_position[1][0]&&i==general_position[1][1]) return 1;
			}
		}
		return 0;
	}
	else{
		middlething = 0;
		for(int32_t i=target_i-1;i>=0;i--){
			if(!empty_checker(board,i,target_j)) middlething += 1;
			if(middlething==2){
				if(i==general_position[1][0]&&target_j==general_position[1][1]) return 1;
			}
		}
		middlething = 0;
		for(int32_t i=target_i+1;i<10;i++){
			if(!empty_checker(board,i,target_j)) middlething += 1;
			if(middlething==2){
				if(i==general_position[1][0]&&target_j==general_position[1][1]) return 1;
			}
		}
		return 0;
	}

}

int32_t soldier_mate_check(int32_t board[10][9],int32_t target_i,int32_t target_j){
	if(target_i+1==general_position[1][0]&&target_j==general_position[1][1]) return 1;
	if(target_i==general_position[1][0]&&target_j+1==general_position[1][1]) return 1;
	if(target_i==general_position[1][0]&&target_j-1==general_position[1][1]) return 1;
	if(target_i-1==general_position[1][0]&&target_j==general_position[1][1]) return 1;


	return 0;
}

void mate_check(int32_t board[10][9],int32_t target){

	if(target == RED_SOLDIER){
		for(int32_t i=0;i<5;i++){
			if(soldier_mate_check(board,soldier_position[i][0]-1,soldier_position[i][1])){
				printf("%d) Move Soldier from",++move_count);
				printf(" (%d,%d) to",soldier_position[i][0],soldier_position[i][1]);
				printf(" (%d,%d)\n",soldier_position[i][0]-1,soldier_position[i][1]);
			}
			if(soldier_mate_check(board,soldier_position[i][0],soldier_position[i][1]-1)){
				printf("%d) Move Soldier from",++move_count);
				printf(" (%d,%d) to",soldier_position[i][0],soldier_position[i][1]);
				printf(" (%d,%d)\n",soldier_position[i][0],soldier_position[i][1]-1);
			}
			if(soldier_mate_check(board,soldier_position[i][0],soldier_position[i][1]+1)){
				printf("%d) Move Soldier from",++move_count);
				printf(" (%d,%d) to",soldier_position[i][0],soldier_position[i][1]);
				printf(" (%d,%d)\n",soldier_position[i][0],soldier_position[i][1]+1);
			}
			if(soldier_mate_check(board,soldier_position[i][0]+1,soldier_position[i][1])){
				printf("%d) Move Soldier from",++move_count);
				printf(" (%d,%d) to",soldier_position[i][0],soldier_position[i][1]);
				printf(" (%d,%d)\n",soldier_position[i][0]+1,soldier_position[i][1]);
			}
		}
	}

	else if(target==RED_GENERAL){
		if(general_position[0][1]==3){
			if(general_position[1][1]==4){
				if(!empty_checker(board,general_position[0][1],general_position[1][1]))return;
				if(is_it_check(board,general_position[0][0],general_position[1][1])){
					printf("%d) Move General from (%d,%d) to (%d,%d)\n",++move_count,general_position[0][0],general_position[0][1],general_position[0][0],general_position[1][1]);
				}
			}
		}
		else if(general_position[0][1]==4){
			if(general_position[1][1]==3||general_position[1][1]==5){
				if(!empty_checker(board,general_position[0][1],general_position[1][1]))return;
				if(is_it_check(board,general_position[0][0],general_position[1][1])){
					printf("%d) Move General from (%d,%d) to (%d,%d)\n",++move_count,general_position[0][0],general_position[0][1],general_position[0][0],general_position[1][1]);
				}
			}
		}
		else if(general_position[0][1]==5){
			if(general_position[1][1]==4){
				if(!empty_checker(board,general_position[0][1],general_position[1][1]))return;
				if(is_it_check(board,general_position[0][0],general_position[1][1])){
					printf("%d) Move General from (%d,%d) to (%d,%d)\n",++move_count,general_position[0][0],general_position[0][1],general_position[0][0],general_position[1][1]);
				}
			}
		}
	}

	else if(target==RED_HORSE){
		for(int32_t i=0;i<2;i++){
			if(horse_position[i][0]==-1)return;

			if((empty_checker(board,horse_position[i][0]-1,horse_position[i][1])||black_checker(board,horse_position[i][0]-2,horse_position[i][1]-1))&&horse_checker(board,horse_position[i][0]-2,horse_position[i][1]-1)){
				int32_t a[4] = {horse_position[i][0],horse_position[i][1],horse_position[i][0]-2,horse_position[i][1]-1};
				printf("%d) Move Horse from ",++move_count);
				printf("(%d,%d) to (%d,%d)\n",a[0],a[1],a[2],a[3]);
			}
			if((empty_checker(board,horse_position[i][0]-1,horse_position[i][1])||black_checker(board,horse_position[i][0]-2,horse_position[i][1]+1))&&horse_checker(board,horse_position[i][0]-2,horse_position[i][1]+1)){
int32_t a[4] = {horse_position[i][0],horse_position[i][1],horse_position[i][0]-2,horse_position[i][1]+1};
				printf("%d) Move Horse from ",++move_count);
				printf("(%d,%d) to (%d,%d)\n",a[0],a[1],a[2],a[3]);
			}
			if((empty_checker(board,horse_position[i][0],horse_position[i][1]-1)||black_checker(board,horse_position[i][0]-1,horse_position[i][1]-2))&&horse_checker(board,horse_position[i][0]-1,horse_position[i][1]-2)){
int32_t a[4] = {horse_position[i][0],horse_position[i][1],horse_position[i][0]-1,horse_position[i][1]-2};
				printf("%d) Move Horse from ",++move_count);
				printf("(%d,%d) to (%d,%d)\n",a[0],a[1],a[2],a[3]);
			}
			if((empty_checker(board,horse_position[i][0],horse_position[i][1]+1)||black_checker(board,horse_position[i][0]-1,horse_position[i][1]+2))&&horse_checker(board,horse_position[i][0]-1,horse_position[i][1]+2)){
int32_t a[4] = {horse_position[i][0],horse_position[i][1],horse_position[i][0]-1,horse_position[i][1]+2};
				printf("%d) Move Horse from ",++move_count);
				printf("(%d,%d) to (%d,%d)\n",a[0],a[1],a[2],a[3]);
			}
			if((empty_checker(board,horse_position[i][0],horse_position[i][1]-1)||black_checker(board,horse_position[i][0]+1,horse_position[i][1]-2))&&horse_checker(board,horse_position[i][0]+1,horse_position[i][1]-2)){
int32_t a[4] = {horse_position[i][0],horse_position[i][1],horse_position[i][0]+1,horse_position[i][1]-2};
				printf("%d) Move Horse from ",++move_count);
				printf("(%d,%d) to (%d,%d)\n",a[0],a[1],a[2],a[3]);
			}
			if((empty_checker(board,horse_position[i][0],horse_position[i][1]+1)||black_checker(board,horse_position[i][0]+1,horse_position[i][1]+2))&&horse_checker(board,horse_position[i][0]+1,horse_position[i][1]+2)){
int32_t a[4] = {horse_position[i][0],horse_position[i][1],horse_position[i][0]+1,horse_position[i][1]+2};
				printf("%d) Move Horse from ",++move_count);
				printf("(%d,%d) to (%d,%d)\n",a[0],a[1],a[2],a[3]);
			}
			if((empty_checker(board,horse_position[i][0]+1,horse_position[i][1])||black_checker(board,horse_position[i][0]+2,horse_position[i][1]-1))&&horse_checker(board,horse_position[i][0]+2,horse_position[i][1]-1)){

int32_t a[4] = {horse_position[i][0],horse_position[i][1],horse_position[i][0]+2,horse_position[i][1]-1};
				printf("%d) Move Horse from ",++move_count);
				printf("(%d,%d) to (%d,%d)\n",a[0],a[1],a[2],a[3]);
			}
			if((empty_checker(board,horse_position[i][0]+1,horse_position[i][1])||black_checker(board,horse_position[i][0]+2,horse_position[i][1]+1))&&horse_checker(board,horse_position[i][0]+2,horse_position[i][1]+1)){
int32_t a[4] = {horse_position[i][0],horse_position[i][1],horse_position[i][0]+2,horse_position[i][1]+1};
				printf("%d) Move Horse from ",++move_count);
				printf("(%d,%d) to (%d,%d)\n",a[0],a[1],a[2],a[3]);
			}
		}
	}

	else if(target==RED_CHARIOT){
		for(int32_t i=0;i<2;i++){
			if(chariot_position[i][0]==-1)return;
			for(int32_t j=chariot_position[i][0] - 1;j>=0;j--){
				if(!empty_checker(board,j,chariot_position[i][1])&&!black_checker(board,j,chariot_position[i][1]))break;
				if(is_it_check(board,j,chariot_position[i][1])){
					printf("%d) Move Chariot from",++move_count);
					printf(" (%d,%d) to (%d,%d)\n",chariot_position[i][0],chariot_position[i][1],j,chariot_position[i][1]);
				}
				if(black_checker(board,j,chariot_position[i][1]))break;
				
			}
			for(int32_t j=chariot_position[i][1] - 1;j>=0;j--){
if(!empty_checker(board,chariot_position[i][0],j)&&!black_checker(board,chariot_position[i][0],j))break;
				if(is_it_check(board,chariot_position[i][0],j)){
					printf("%d) Move Chariot from",++move_count);
					printf(" (%d,%d) to (%d,%d)\n",chariot_position[i][0],chariot_position[i][1],chariot_position[i][0],j);
				}
				if(black_checker(board,chariot_position[i][0],j))break;
			}
			for(int32_t j=chariot_position[i][1] + 1;j<9;j++){
if(!empty_checker(board,chariot_position[i][0],j)&&!black_checker(board,chariot_position[i][0],j))break;
				if(is_it_check(board,chariot_position[i][0],j)){
					printf("%d) Move Chariot from",++move_count);
					printf(" (%d,%d) to (%d,%d)\n",chariot_position[i][0],chariot_position[i][1],chariot_position[i][0],j);
				}
				if(black_checker(board,chariot_position[i][0],j))break;
			}
			for(int32_t j=chariot_position[i][0] + 1;j<10;j++){
if(!empty_checker(board,j,chariot_position[i][1])&&!black_checker(board,j,chariot_position[i][1]))break;
				if(is_it_check(board,j,chariot_position[i][1])){
					printf("%d) Move Chariot from",++move_count);
					printf(" (%d,%d) to (%d,%d)\n",chariot_position[i][0],chariot_position[i][1],j,chariot_position[i][1]);
				}
				if(black_checker(board,j,chariot_position[i][1]))break;
				
			}
		}
	}

	else if(target==RED_CANNON){
		for(int32_t i=0;i<2;i++){
			if(cannon_position[i][0]==-1)return;
			int32_t middlething = 0;
			for(int32_t j=cannon_position[i][0] - 1;j>=0;j--){
				if(!empty_checker(board,j,cannon_position[i][1])){
					middlething += 1;
					if(cannon_mate_check(board,j,cannon_position[i][1],0)&&middlething==2&&black_checker(board,j,cannon_position[i][1])){
					printf("%d) Move Cannon from",++move_count);
					printf(" (%d,%d) to (%d,%d)\n",cannon_position[i][0],cannon_position[i][1],j,cannon_position[i][1]);
				}
				}
				if(cannon_mate_check(board,j,cannon_position[i][1],0)&&middlething==0){
					printf("%d) Move Cannon from",++move_count);
					printf(" (%d,%d) to (%d,%d)\n",cannon_position[i][0],cannon_position[i][1],j,cannon_position[i][1]);
				}
				
			}middlething = 0;
			for(int32_t j=cannon_position[i][1] - 1;j>=0;j--){

				if(!empty_checker(board,cannon_position[i][0],j)){middlething++;
if(cannon_mate_check(board,cannon_position[i][0],j,1)&&middlething==2&&black_checker(board,cannon_position[i][0],j)){
					printf("%d) Move Cannon from",++move_count);
					printf(" (%d,%d) to (%d,%d)\n",cannon_position[i][0],cannon_position[i][1],cannon_position[i][0],j);
				}

			}
				if(cannon_mate_check(board,cannon_position[i][0],j,1)&&middlething==0){
					printf("%d) Move Cannon from",++move_count);
					printf(" (%d,%d) to (%d,%d)\n",cannon_position[i][0],cannon_position[i][1],cannon_position[i][0],j);
				}
				
			}middlething = 0;
			for(int32_t j=cannon_position[i][1] + 1;j<9;j++){

				if(!empty_checker(board,cannon_position[i][0],j)){

					middlething ++;
					if(cannon_mate_check(board,cannon_position[i][0],j,1)&&middlething==2&&black_checker(board,cannon_position[i][0],j)){
					printf("%d) Move Cannon from",++move_count);
					printf(" (%d,%d) to (%d,%d)\n",cannon_position[i][0],cannon_position[i][1],cannon_position[i][0],j);
				}
				}
				if(cannon_mate_check(board,cannon_position[i][0],j,1)&&middlething==0){
					printf("%d) Move Cannon from",++move_count);
					printf(" (%d,%d) to (%d,%d)\n",cannon_position[i][0],cannon_position[i][1],cannon_position[i][0],j);
				}
				
			}
			middlething = 0;
			for(int32_t j=cannon_position[i][0] + 1;j<10;j++){
				
				if(!empty_checker(board,j,cannon_position[i][1])){
					middlething++;
					if(cannon_mate_check(board,j,cannon_position[i][1],0)&&middlething==2&&black_checker(board,j,cannon_position[i][1])){
					printf("%d) Move Cannon from",++move_count);
					printf(" (%d,%d) to (%d,%d)\n",cannon_position[i][0],cannon_position[i][1],j,cannon_position[i][1]);
				}
				}
				if(cannon_mate_check(board,j,cannon_position[i][1],0)&&middlething==0){
					printf("%d) Move Cannon from",++move_count);
					printf(" (%d,%d) to (%d,%d)\n",cannon_position[i][0],cannon_position[i][1],j,cannon_position[i][1]);
				}
				
			}
		}
	}

}

int32_t board_valid_check(int32_t board[10][9]){

	int32_t chess_count[18] = {0};
	for(int32_t i=0;i<10;i++){
		for(int32_t j=0;j<9;j++){
			//printf("%d %d\n",i,j);
			if(board[i][j]==RED_GENERAL){
				if(j<3||j>5) return 0;
				if(i>2&&i<7) return 0;
				if(chess_count[1]) return 0;
				chess_count[1] += 1;
				general_position[0][0] = i;
				general_position[0][1] = j;
				if(i>=7){
					if(side_==-1||side_==1) side_ = 1;
					else return 0;
				}
				else{
					if(side_==-1||side_==0) side_ = 0;
					else return 0;
				}
			}
			else if(board[i][j]==BLACK_GENERAL){
				if(j<3||j>5) return 0;
				if(i>2&&i<7) return 0;
				general_position[1][0] = i;
				general_position[1][1] = j;
				if(chess_count[11]) return 0;
				chess_count[11] += 1;
				if(i>=7){
					if(side_==-1||side_==0) side_ = 0;
					else return 0;
				}
				else{
					if(side_==-1||side_==1) side_ = 1;
					else return 0;
				}
			}

		}
	}

	if(side_==-1) return 0;
	//printf("General Success!\n");
	for(int32_t i=0;i<10;i++){
		for(int32_t j=0;j<9;j++){
			//printf("%d %d\n",i,j);
			if(chess_count[1] != 1 || chess_count[11] != 1)return 0;
		for(int32_t k=2;k<=6;k++){
		if(chess_count[10+k]>2 || chess_count[k] > 2)return 0;
		}
		if(chess_count[7] > 5 || chess_count[17] > 5)return 0;
			if(board[i][j] == EMPTY || board[i][j]==RED_GENERAL || board[i][j]==BLACK_GENERAL)continue;
			if(board[i][j]==RED_ADVISOR){
				if(side_==1){
					if(j<3||j>5)return 0;
					if(j==4 && i!=8) return 0;
					if((j==3||j==5)&&(i!=9&&i!=7))return 0;
					chess_count[2] += 1;
				}
				else{
					if(j<3||j>5)return 0;
					if(j==4 && i!=1) return 0;
					if((j==3||j==5)&&(i!=0&&i!=2))return 0;
					chess_count[2] += 1;
				}
			}
			else if(board[i][j]==BLACK_ADVISOR){
				if(side_==0){
					if(j<3||j>5)return 0;
					if(j==4 && i!=8) return 0;
					if((j==3||j==5)&&(i!=9&&i!=7))return 0;
					chess_count[12] += 1;
				}
				else{
					if(j<3||j>5)return 0;
					if(j==4 && i!=1) return 0;
					if((j==3||j==5)&&(i!=0&&i!=2))return 0;
					chess_count[12] += 1;
				}
			}
			else if(board[i][j]==RED_ELEPHANT){
				if(side_==1){
					if(j%2)return 0;
					if(j%4==0&&i!=7)return 0;
					if(j%4==2&&(i!=5&&i!=9))return 0;
					chess_count[3] += 1;
				}
				else{
					if(j%2)return 0;
					if(j%4==0&&i!=2)return 0;
					if(j%4==2&&(i!=0&&i!=4))return 0;
					chess_count[3] += 1;
				}
			}
			else if(board[i][j]==BLACK_ELEPHANT){
				if(side_==0){
					if(j%2)return 0;
					if(j%4==0&&i!=7)return 0;
					if(j%4==2&&(i!=5&&i!=9))return 0;
					chess_count[13] += 1;
				}
				else{
					if(j%2)return 0;
					if(j%4==0&&i!=2)return 0;
					if(j%4==2&&(i!=0&&i!=4))return 0;
					chess_count[13] += 1;
				}
			}
			else if(board[i][j]==RED_SOLDIER){
				if(side_==0){
					if(i<5&&j%2!=0)return 0;
					if(i<3)return 0;
					chess_count[7] += 1;
				}
				else{
					if(i>=5&&j%2!=0)return 0;
					if(i>6)return 0;
					chess_count[7] += 1;
				}
				soldier_position[chess_count[7]-1][0] = i;
				soldier_position[chess_count[7]-1][1] = j;
			}
			else if(board[i][j]==BLACK_SOLDIER){
				if(side_==1){
					if(i<5&&j%2!=0)return 0;
					if(i<3)return 0;
					chess_count[17] += 1;
				}
				else{
					if(i>=5&&j%2!=0)return 0;
					if(i>6)return 0;
					chess_count[17] += 1;
				}
			}

			else if(board[i][j]==RED_HORSE){
				horse_position[chess_count[4]][0] = i;
				horse_position[chess_count[4]][1] = j;
				chess_count[4] += 1;
			}
			else if(board[i][j]==RED_CHARIOT){
				chariot_position[chess_count[5]][0] = i;
				chariot_position[chess_count[5]][1] = j;
				chess_count[5] += 1;
			}
			else if(board[i][j]==RED_CANNON){
				cannon_position[chess_count[6]][0] = i;
				cannon_position[chess_count[6]][1] = j;
				chess_count[6] += 1;
			}
			else if(board[i][j]==BLACK_HORSE) chess_count[14] += 1;
			else if(board[i][j]==BLACK_CHARIOT) chess_count[15] += 1;
			else if(board[i][j]==BLACK_CANNON) chess_count[16] += 1;
			else{
				return 0;
			}
		}
	}
	




	

	return 1;

}

int32_t checkmate( int32_t board[10][9] ){

	initial_position();
	if(!board_valid_check(board))return -1;
	//debug_mode(board);
	mate_check(board,RED_GENERAL);
	mate_check(board,RED_HORSE);
	mate_check(board,RED_CHARIOT);
	mate_check(board,RED_CANNON);
	mate_check(board,RED_SOLDIER);
	return move_count;
}