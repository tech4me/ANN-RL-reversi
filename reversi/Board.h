#pragma once
#include <vector>
#include "Piece.h"

enum GameState
{
    active,
    p1_no_move,
    p2_no_move,
    p1_win,
    p2_win,
    draw
};

class Board
{
private:
    int size;
    bool is_default_piece_order;
    std::vector<Piece> board;

public:
    Board(int _size, bool _is_default_piece_order);
    void init();
    void print_board() const;
    GameState check_game_end(bool & game_end, bool is_p1_black, color col) const;
    void make_move(int x, int y, color col);
    void reset_board();

    inline int get_board_size() const
    {
        return size;
    }

    inline bool position_on_board(int position_x, int position_y) const
    {
        if ((position_x >= 0) && (position_x <= size - 1) && (position_y >= 0) && (position_y <= size - 1))
            return true;
        else
            return false;
    }
    
    inline int check_legal_move(int position_x, int position_y, color col) const
    {
        if (!position_on_board(position_x, position_y))
            return false;
        else if (board.at(position_x + position_y * size).get_color() != empty)
            return false;
        color opposite_col = opposite_color(col);
        int total_count = 0, counter = 0;
        for (int i = 0; i < 8; ++i)
        {
            Piece * temp = board.at(position_x + position_y * size).c_get_surround().at(i);
            while (temp != nullptr)
            {
                if (temp->get_color() == opposite_col)
                {
                    ++counter;
                    temp = temp->c_get_surround().at(i);
                }
                else if ((temp->get_color() == col) && (counter < 1))
                {
                    break;
                }
                else if ((temp->get_color() == col) && (counter >= 1))
                {
                    total_count += counter;
                    break;
                }
                else if (temp->get_color() == empty)
                {
                    break;
                }
            }
            counter = 0;
        }
        return total_count;
    }
};