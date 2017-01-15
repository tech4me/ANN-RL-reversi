#include "Game.h"

#define BOARD_SIZE 8
#define IS_DEFAULT_PIECE_ORDER 1
#define PLAYER1_IS_BLACK 1

int main()
{
    Game game(BOARD_SIZE, IS_DEFAULT_PIECE_ORDER, PLAYER1_IS_BLACK);
    game.run();
    return 0;
}