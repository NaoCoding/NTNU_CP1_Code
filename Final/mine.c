#include "mine.h"

static int32_t rowsize = 16,colsize = 30;

int32_t check_surrounding(int32_t board[rowsize][colsize], int32_t row, int32_t col){

	int32_t count = 0;
	if(board[row][col]>=0) return board[row][col];
	if(row-1 >= 0) count += board[row-1][col] == -2 ? 1:0;
	if(row-1 >= 0 && col - 1 >= 0) count += board[row-1][col-1] == -2 ? 1:0;
	if(row-1 >=0 && col + 1 < colsize) count += board[row-1][col+1] == -2 ? 1:0;
	if(col - 1 >=0) count += board[row][col-1] == -2 ? 1:0;
	if(col + 1 < colsize) count += board[row][col+1] == -2 ? 1:0;
	if(row+1 < rowsize) count += board[row+1][col] == -2 ? 1:0;
	if(row+1 < rowsize && col - 1 >= 0) count += board[row+1][col-1] == -2 ? 1:0;
	if(row+1 < rowsize && col + 1 < colsize) count += board[row+1][col+1] == -2 ? 1:0;
	if(count){
		if(board[row][col]==count) return 0;
		else if(board[row][col]>=0&&count != board[row][col]) return -1;
		board[row][col] = count;
	}
	else{
		board[row][col] = 0;
		if(row-1 >= 0) check_surrounding(board,row-1,col);
		if(row-1 >= 0 && col - 1 >= 0) check_surrounding(board,row-1,col-1);
		if(row-1 >=0 && col + 1 < colsize) check_surrounding(board,row-1,col+1);
		if(col - 1 >=0) check_surrounding(board,row,col-1);
		if(col + 1 < colsize) check_surrounding(board,row,col+1);
		if(row+1 < rowsize) check_surrounding(board,row+1,col);
		if(row+1 < rowsize && col - 1 >= 0) check_surrounding(board,row+1,col-1);
		if(row+1 < rowsize && col + 1 < colsize) check_surrounding(board,row+1,col+1);
	}
	return 0;

}

int32_t hit( int32_t board[rowsize][colsize], int32_t row, int32_t col ){

	if(board[row][col]>8) return -1;
	if(row>=rowsize||col>=colsize||row<0||col<0) return -1;
	if(board[row][col] == -2) return 1;
	if(check_surrounding(board,row,col)==-1) return -1;


	return 0;

}