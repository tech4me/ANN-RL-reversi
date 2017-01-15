#pragma once
#include "Board.h"
#include "Piece.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "QNetwork.h"

enum GameResult
{
    draw_game,
    p1_win_game,
    p2_win_game
};

class Game
{
private:
    bool is_p1_black;
    Board board;
    ComputerPlayer p1;
    ComputerPlayer p2;

    void print_game_status(GameState state);
    GameResult game_loop();

public:
    Game(int board_size, bool is_default_piece_order, bool p1_black);
    void run();
};