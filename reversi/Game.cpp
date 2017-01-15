#include "Game.h"
#include <iostream>

Game::Game(int board_size, bool is_default_piece_order, bool p1_black)
    : is_p1_black(p1_black)
    , board(board_size, is_default_piece_order)
    , p1(random)
    , p2(greedy)
{
    board.init();
    p1.init_player(p1_black);
    p2.init_player(!p1_black);
}

void Game::print_game_status(GameState state)
{
    switch (state)
    {
        case p1_no_move:
        {
            if (is_p1_black)
                std::cout << "B player has no valid move." << std::endl;
            else
                std::cout << "W player has no valid move." << std::endl;
            break;
        }
        case p2_no_move:
        {
            if (is_p1_black)
                std::cout << "W player has no valid move." << std::endl;
            else
                std::cout << "B player has no valid move." << std::endl;
            break;
        }
        case draw:
        {
            std::cout << "Draw!" << std::endl;
            break;
        }
        case p1_win:
        {
            if (is_p1_black)
                std::cout << "B player wins." << std::endl;
            else
                std::cout << "W player wins." << std::endl;
            break;
        }
        case p2_win:
        {
            if (is_p1_black)
                std::cout << "W player wins." << std::endl;
            else
                std::cout << "B player wins." << std::endl;
            break;
        }
    }
}

GameResult Game::game_loop()
{
    bool game_end = false;
    GameState state;
    // Game loop
    while (1)
    {
        if (is_p1_black)
        {
            state = board.check_game_end(game_end, is_p1_black, p1.get_color());
            //print_game_status(state);
            if (!game_end && state != p1_no_move)
            {
                p1.move(board, game_end);
                //board.print_board();
            }
            else
            {
                if (state == draw)
                    return draw_game;
                else if (state == p1_win)
                    return p1_win_game;
                else if (state == p2_win)
                    return p2_win_game;
            }
            state = board.check_game_end(game_end, is_p1_black, p2.get_color());
            //print_game_status(state);
            if (!game_end && state != p2_no_move)
            {
                p2.move(board, game_end);
                //board.print_board();
            }
            else
            {
                if (state == draw)
                    return draw_game;
                else if (state == p1_win)
                    return p1_win_game;
                else if (state == p2_win)
                    return p2_win_game;
            }
        }
        else
        {
            state = board.check_game_end(game_end, is_p1_black, p2.get_color());
            //print_game_status(state);
            if (!game_end && state != p2_no_move)
            {
                p2.move(board, game_end);
                //board.print_board();
            }
            else
            {
                if (state == draw)
                    return draw_game;
                else if (state == p1_win)
                    return p1_win_game;
                else if (state == p2_win)
                    return p2_win_game;
            }
            state = board.check_game_end(game_end, is_p1_black, p1.get_color());
            //print_game_status(state);
            if (!game_end && state != p1_no_move)
            {
                p1.move(board, game_end);
                //board.print_board();
            }
            else
            {
                if (state == draw)
                    return draw_game;
                else if (state == p1_win)
                    return p1_win_game;
                else if (state == p2_win)
                    return p2_win_game;
            }
        }
    }
}

void Game::run()
{
    int game_num = 0;
    do
    {
        int p1 = 0, p2 = 0;
        std::cin >> game_num;
        for (int i = 0; i < game_num; ++i)
        {
            GameResult temp = game_loop();
            if (temp == draw_game)
                ;
            else if (temp == p1_win_game)
                ++p1;
            else if (temp == p2_win_game)
                ++p2;
            //board.print_board();
            board.reset_board();
            //board.print_board();
        }
        std::cout << "P1 win rate: " << static_cast<float>(p1) / game_num << std::endl;
        std::cout << "P2 win rate: " << static_cast<float>(p2) / game_num << std::endl;
    } while (1);
}