#include <stdint.h>
#include <stdio.h>

#define EMPTY (0)
#define RED_GENERAL (1)
#define RED_ADVISOR (2)
#define RED_ELEPHANT (3)
#define RED_HORSE (4)
#define RED_CHARIOT (5)
#define RED_CANNON (6)
#define RED_SOLDIER (7)
#define BLACK_GENERAL (11)
#define BLACK_ADVISOR (12)
#define BLACK_ELEPHANT (13)
#define BLACK_HORSE (14)
#define BLACK_CHARIOT (15)
#define BLACK_CANNON (16)
#define BLACK_SOLDIER (17)

// Return -1 if the board is invalid;
// otherwise , print all red side possible move to checkmate the

// Note the print should follow the piece order.
int32_t checkmate( int32_t board[10][9] );