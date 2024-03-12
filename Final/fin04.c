#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

static int64_t height = 0,width = 0,obstacles = 0,player_alive = 1,bot_left = 3;
static int64_t bot[3][2][2],player[2][2],frame = 1,bomb[2] = {0,0};
static int64_t bomblocation[4][2],bombdirection[4][2],botalive[3] = {1,1,1};
static char **map = NULL;
static char cmd;
void initial_map();
void initial_obstacle();
void initial_player();
void initial_bot();
void map_show();
void player_move();
void muzzle_change_place();
void bot_move();
int64_t touch_obstacle(int64_t x,int64_t y);
int64_t ad_move_touch_obstacle(int64_t x,int64_t y);
int64_t ws_move_touch_obstacle(int64_t x,int64_t y);
int64_t min(int64_t a,int64_t b){return a > b ? b : a;}
int64_t max(int64_t a,int64_t b){return a > b ? a : b;}
void throw_bomb(int64_t pbot,int64_t place);
void bomb_run();
void bombkill_detect();
void bot_bomb();


int main(){

	srand(time(NULL));

	printf("Please input the height of the map: ");
	scanf("%ld",&height);
	printf("Please input the width of the map: ");
	scanf("%ld",&width);
	cmd = getchar();
	obstacles = height * width / 20;

	initial_map();
	initial_obstacle();
	initial_player();
	initial_bot();
	while(player_alive && bot_left){

		map_show();
		printf("Please input the action: ");
		scanf("%s",&cmd);
		
		

		bombkill_detect();
		map[player[0][1]][player[1][1]] = ' ';
		for(int i=0;i<3;i++){
		map[bot[i][0][1]][bot[i][1][1]] = ' ';
		}
		for(int i=0;i<4;i++){
			map[bomblocation[i][0]][bomblocation[i][1]] = ' ';
		}
		frame += 1;
		bomb[0] = bomb[0] == 0 ? 0 : bomb[0] - 1;
		bomb[1] = bomb[1] == 0 ? 0 : bomb[1] - 1;
		

		
		bomb_run();
		if(bomb[1]==0){
			bot_bomb();		}
			bombkill_detect();
		player_move();
		bot_move();
		bombkill_detect();
		
		muzzle_change_place(frame);
		

	}}
		
	
void bombkill_detect(){

	for(int i=0;i<4;i++){
		if(map[bomblocation[i][0]][bomblocation[i][1]]=='P'){
			player_alive = 0;
			printf("You Dead!\n");
		}
	}
	for(int i=0;i<4;i++){
		if(map[bomblocation[i][0]][bomblocation[i][1]]=='C'){
			bot_left -= 1;
			for(int j=0;j<3;j++){
				if(bot[j][0][0]==bomblocation[i][0] && bot[j][1][0] == bomblocation[i][1]){
					botalive[j] = 0;
					bot[j][0][0] = 99999;
					bot[j][1][0] = 99999;
				}
			}
		}
	}

}




void bomb_run(){

	for(int i=0;i<2;i++){
		if(bomb[i]==0) continue;
		else{
			if(!i){
				bomblocation[i][0] += bombdirection[i][0];
				bomblocation[i][1] += bombdirection[i][1];
				if(bomblocation[i][0]>=0&&bomblocation[i][0]<height-1&&bomblocation[i][1]<width-1&&bomblocation[i][1]>=0){
			map[bomblocation[i][0]][bomblocation[i][1]] = 'o';
		}
		else{
			bombdirection[i][0] *= -1;
			bombdirection[i][1] *= -1;
			bomblocation[i][0] += bombdirection[i][0];
			bomblocation[i][1] += bombdirection[i][1];
			bomblocation[i][0] += bombdirection[i][0];
			bomblocation[i][1] += bombdirection[i][1];
			map[bomblocation[i][0]][bomblocation[i][1]] = 'o';

			}
		}
		
		else{
			for(int j=0;j<3;j++){
			
				bomblocation[i+j][0] += bombdirection[i+j][0];
				bomblocation[i+j][1] += bombdirection[i+j][1];
				if(bomblocation[i+j][0]>=0&&bomblocation[i+j][0]<height-1&&bomblocation[i+j][1]<width-1&&bomblocation[i+j][1]>=0){
			map[bomblocation[i+j][0]][bomblocation[i+j][1]] = 'o';
		}
		else{
			bombdirection[i+j][0] *= -1;
			bombdirection[i+j][1] *= -1;
			bomblocation[i+j][0] += bombdirection[i+j][0];
			bomblocation[i+j][1] += bombdirection[i+j][1];
			bomblocation[i+j][0] += bombdirection[i+j][0];
			bomblocation[i+j][1] += bombdirection[i+j][1];
			map[bomblocation[i+j][0]][bomblocation[i+j][1]] = 'o';

			}
		
			}
		}}

	}

}

void bot_bomb(){

	throw_bomb(frame%8,1);
}

void throw_bomb(int64_t pbot,int64_t place){

	if(place==0){
		if(pbot==0){
			bomblocation[0][0] = player[0][0]-2;
			bomblocation[0][1] = player[1][0];
			bombdirection[0][0] = -1;
			bombdirection[0][1] = 0;

		}
		if(pbot==1){
			bomblocation[0][1] = player[1][0] + 2;
			bomblocation[0][0] = player[0][0] -2;
			bombdirection[0][0] = -1;
			bombdirection[0][1] = +1;
		}
		if(pbot==2){
			bomblocation[0][1] = player[1][0] + 2;
			bomblocation[0][0] = player[0][0] ;
			bombdirection[0][0] = 0;
			bombdirection[0][1] = 1;
		}
		if(pbot==3){
			bomblocation[0][1] = player[1][0] + 2;
			bomblocation[0][0] = player[0][0] +2;
			bombdirection[0][0] = 1;
			bombdirection[0][1] = 1;
		}
		if(pbot==4){
			bomblocation[0][1] = player[1][0] ;
			bomblocation[0][0] = player[0][0] +2;
			bombdirection[0][0] = 1;
			bombdirection[0][1] = 0;
		}
		if(pbot==5){
			bomblocation[0][1] = player[1][0] - 2;
			bomblocation[0][0] = player[0][0] +2;
			bombdirection[0][0] = 1;
			bombdirection[0][1] = -1;
		}
		if(pbot==6){
			bomblocation[0][1] = player[1][0] - 2;
			bomblocation[0][0] = player[0][0] ;
			bombdirection[0][0] = 0;
			bombdirection[0][1] = -1;
		}
		if(pbot==7){
			bomblocation[0][1] = player[1][0] - 2;
			bomblocation[0][0] = player[0][0] -2;
			bombdirection[0][0] = -1;
			bombdirection[0][1] = -1;
		}







		bomb[0] = 10;
		if(bomblocation[0][0]>=0&&bomblocation[0][0]<height-1&&bomblocation[0][1]<width-1&&bomblocation[0][1]>=0){
			map[bomblocation[0][0]][bomblocation[0][1]] = 'o';
		}
		else{
			int i = 0;
			bombdirection[i][0] *= -1;
			bombdirection[i][1] *= -1;
			bomblocation[i][0] += bombdirection[i][0];
			bomblocation[i][1] += bombdirection[i][1];
			bomblocation[i][0] += bombdirection[i][0];
			bomblocation[i][1] += bombdirection[i][1];
			map[bomblocation[i][0]][bomblocation[i][1]] = 'o';

			
		}
		
	}
	else{
		for(int i=0;i<3;i++){
			if(botalive[i]==0) continue;
			if(pbot==0){
			bomblocation[i+1][0] = bot[i][0][0]-2;
			bomblocation[i+1][1] = bot[i][1][0];
			bombdirection[i+1][0] = -1;
			bombdirection[i+1][1] = 0;

		}
		if(pbot==1){
			bomblocation[i+1][1] = bot[i][1][0] + 2;
			bomblocation[i+1][0] = bot[i][0][0] -2;
			bombdirection[i+1][0] = -1;
			bombdirection[i+1][1] = +1;
		}
		if(pbot==2){
			bomblocation[i+1][1] = bot[i][1][0] + 2;
			bomblocation[i+1][0] = bot[i][0][0] ;
			bombdirection[i+1][0] = 0;
			bombdirection[i+1][1] = 1;
		}
		if(pbot==3){
			bomblocation[i+1][1] = bot[i][1][0] + 2;
			bomblocation[i+1][0] = bot[i][0][0] +2;
			bombdirection[i+1][0] = 1;
			bombdirection[i+1][1] = 1;
		}
		if(pbot==4){
			bomblocation[i+1][1] = bot[i][1][0] ;
			bomblocation[i+1][0] = bot[i][0][0] +2;
			bombdirection[i+1][0] = 1;
			bombdirection[i+1][1] = 0;
		}
		if(pbot==5){
			bomblocation[i+1][1] = bot[i][1][0] - 2;
			bomblocation[i+1][0] = bot[i][0][0] +2;
			bombdirection[i+1][0] = 1;
			bombdirection[i+1][1] = -1;
		}
		if(pbot==6){
			bomblocation[i+1][1] = bot[i][1][0] - 2;
			bomblocation[i+1][0] = bot[i][0][0] ;
			bombdirection[i+1][0] = 0;
			bombdirection[i+1][1] = -1;
		}
		if(pbot==7){
			bomblocation[i+1][1] = bot[i][1][0] - 2;
			bomblocation[i+1][0] = bot[i][0][0] +2;
			bombdirection[i+1][0] = +1;
			bombdirection[i+1][1] = -1;
		}







		bomb[1] = 10;
		if(bomblocation[i+1][0]>=0&&bomblocation[i+1][0]<height-1&&bomblocation[i+1][1]<width-1&&bomblocation[i+1][1]>=0){
			map[bomblocation[i+1][0]][bomblocation[i+1][1]] = 'o';
		}
		}
		
	
	}

}

void muzzle_change_place(){
		
	if(frame%8==0){
		player[1][1] = player[1][0];
		player[0][1] = player[0][0]-1;
		for(int i=0;i<3;i++){
			bot[i][0][1] = bot[i][0][0]-1;
			bot[i][1][1] = bot[i][1][0];
		}}
	if(frame%8==1){
		player[1][1] = player[1][0] + 1;
		player[0][1] = player[0][0] -1;
	for(int i=0;i<3;i++){
			bot[i][0][1] = bot[i][0][0]-1;
			bot[i][1][1] = bot[i][1][0]+1;
		}}
	if(frame%8==2){
		player[1][1] = player[1][0] +1;
		player[0][1]  = player[0][0];
	for(int i=0;i<3;i++){
			bot[i][0][1] = bot[i][0][0];
			bot[i][1][1] = bot[i][1][0]+1;
		}}
	if(frame%8==3){
		player[1][1] = player[1][0] + 1;
		player[0][1]  = player[0][0] +1;
	for(int i=0;i<3;i++){
			bot[i][0][1] = bot[i][0][0]+1;
			bot[i][1][1] = bot[i][1][0]+1;
		}}
	if(frame%8==4){
		player[1][1] = player[1][0];
		player[0][1]  = player[0][0]+1;
	for(int i=0;i<3;i++){
			bot[i][0][1] = bot[i][0][0]+1;
			bot[i][1][1] = bot[i][1][0];
		}}
	if(frame%8==5){
		player[1][1] = player[1][0]-1;
		player[0][1]  = player[0][0]+1;
	for(int i=0;i<3;i++){
			bot[i][0][1] = bot[i][0][0]+1;
			bot[i][1][1] = bot[i][1][0]-1;
		}}
	if(frame%8==6){
		player[1][1] = player[1][0]-1;
		player[0][1] = player[0][0];
	for(int i=0;i<3;i++){
			bot[i][0][1] = bot[i][0][0];
			bot[i][1][1] = bot[i][1][0]-1;
		}}
	if(frame%8==7){
		player[1][1] = player[1][0]-1;
		player[0][1]  = player[0][0]-1;
	for(int i=0;i<3;i++){
			bot[i][0][1] = bot[i][0][0]-1;
			bot[i][1][1] = bot[i][1][0]-1;
		}}



	map[player[0][1]][player[1][1]] = 'I';
	for(int i=0;i<3;i++){
		map[bot[i][0][1]][bot[i][1][1]] = 'I';
		}

}

void bot_move(){


	for(int i=0;i<3;i++){
		if(botalive[i]==0) continue;
		int c = rand()%4;
		if(c==0){
		if(ws_move_touch_obstacle(bot[i][0][0]-1,bot[i][1][0])) continue;
			bot[i][0][0] -= 1;
			map[bot[i][0][0]][bot[i][1][0]] = 'C';
			map[bot[i][0][0]+1][bot[i][1][0]] = ' ';
	}
	if(c==1){
		if(ws_move_touch_obstacle(bot[i][0][0]+1,bot[i][1][0])) continue;
			bot[i][0][0] += 1;
			map[bot[i][0][0]][bot[i][1][0]] = 'C';
			map[bot[i][0][0]-1][bot[i][1][0]] = ' ';
	}
	if(c==2){
		if(ws_move_touch_obstacle(bot[i][0][0],bot[i][1][0]+1)) continue;
			bot[i][1][0] += 1;
			map[bot[i][0][0]][bot[i][1][0]] = 'C';
			map[bot[i][0][0]][bot[i][1][0]-1] = ' ';
	}
	if(c==3){
		if(ws_move_touch_obstacle(bot[i][0][0],bot[i][1][0]-1)) continue;
			bot[i][1][0] -= 1;
			map[bot[i][0][0]][bot[i][1][0]] = 'C';
			map[bot[i][0][0]][bot[i][1][0]+1] = ' ';
	}
	}

}

void player_move(){

	if(cmd=='W'||cmd=='w'){
			if(ws_move_touch_obstacle(player[0][0]-1,player[1][0])) return;
			player[0][0] -= 1;
			map[player[0][0]][player[1][0]] = 'P';
			map[player[0][0]+1][player[1][0]] = ' ';
		}
	if(cmd=='S'||cmd=='s'){
			if(ws_move_touch_obstacle(player[0][0]+1,player[1][0])) return;
			player[0][0] += 1;
			map[player[0][0]][player[1][0]] = 'P';
			map[player[0][0]-1][player[1][0]] = ' ';
		}
	if(cmd=='D'||cmd=='d'){
			if(ad_move_touch_obstacle(player[0][0],player[1][0]+1)) return;
			player[1][0] += 1;
			map[player[0][0]][player[1][0]] = 'P';
			map[player[0][0]][player[1][0]-1] = ' ';
		}
	if(cmd=='A'||cmd=='a'){
			if(ad_move_touch_obstacle(player[0][0],player[1][0]-1)) return;
			player[1][0] -= 1;
			map[player[0][0]][player[1][0]] = 'P';
			map[player[0][0]][player[1][0]+1] = ' ';
		}
	if(cmd=='Q'||cmd=='q'){
		if(!bomb[0]) throw_bomb((frame)%8,0);
	}

}

int64_t ad_move_touch_obstacle(int64_t x,int64_t y){

	if(map[x][y]!=' '&&map[x][y]!='I')return 1;
	if(y==0)return 1;
	if(y==width-1)return 1;
	if(x<=0) return 1;
	if(x>=height - 1) return 1;
	return 0;

}

int64_t ws_move_touch_obstacle(int64_t x,int64_t y){

	if(map[x][y]!=' '&&map[x][y]!='I')return 1;
	if(x<=0) return 1;
	if(x>=height - 1) return 1;
	if(y==0)return 1;
	if(y==width-1)return 1;
	return 0;

}

void map_show(){

	int64_t map_x = 0,map_y = 0;
	if(player[0][0] <= 9) map_x = 1;
	else map_x = player[0][0] - 9;

	if(player[1][0] <= 29)map_y = 1;
	//else if(player[1] + 29 >=width)map_y = width - 58;
	else map_y = player[1][0] - 29;
	for(int i=-2;i<min(map_y+58,width-1)-map_y;i++)printf("-");
	printf("\n");

	for(int i=map_x;i<min(map_x + 18,height-1);i++){
		printf("|");
		for(int j=map_y;j<min(map_y+58,width-1);j++){
			printf("%c",map[i][j]);
		}
		printf("|");
		if(i==min(map_x + 18,height-1)-5){
			printf("Enemie cooldown: %ld",bomb[1]);
		}
		if(i==min(map_x + 18,height-1)-4){
			printf("Enemies left: %ld",bot_left);
		}
		if(i==min(map_x + 18,height-1)-3){
			printf("Player X: %ld",player[0][0]);
		}
		else if(i==min(map_x + 18,height-1)-2){
			printf("Player Y: %ld",player[1][0]);
		}
		else if(i==min(map_x + 18,height-1)-1){
			printf("Bomb Cooldown: %ld",bomb[0]);
		}
		printf("\n");
	}
	for(int i=-2;i<min(map_y+58,width-1)-map_y;i++)printf("-");
		printf("\n");


}

void initial_map(){


	map = malloc(height*sizeof(char*));
	for(int64_t i=0;i<height;i++){
		map[i] = malloc(width);
		map[i][0] = '|';
		map[i][width-1] = '|';
		for(int j=1;j<width-1;j++)map[i][j] = ' ';
	}
	for(int64_t i=0;i<width;i++){
		map[0][i] = '-';
		map[height-1][i] = '-';
	}
	//printf("!!!");

}

void initial_obstacle(){

	for(int64_t i=0;i<obstacles;i++){
		int64_t x = rand()%height,y = rand()%width;
		while(map[x][y]!=' '){
			x = rand()%height;
			y = rand()%width;
		}
		map[x][y] = 'R';


	}


}

void initial_player(){

	int64_t x = rand()%height,y = rand()%width;
	while(map[x][y]!=' '||map[x+1][y]!=' '||x+1==height){
		x = rand()%height;
		y = rand()%width;
	}
		map[x][y] = 'I';
		map[x+1][y] = 'P';
		player[0][0] = x+1;
		player[1][0] = y;
		player[0][1] = x;
		player[1][1] = y;


}

void initial_bot(){

	for(int i=0;i<3;i++){
		int64_t x = rand()%height,y = rand()%width;
	while(map[x][y]!=' '||map[x+1][y]!=' '||x+1==height){
		x = rand()%height;
		y = rand()%width;
	}
		map[x][y] = 'I';
		map[x+1][y] = 'C';
		bot[i][0][0] = x+1;
		bot[i][1][0] = y;
		bot[i][0][1] = x;
		bot[i][1][1] = y;
	}



}