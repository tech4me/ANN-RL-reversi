#include "Board.h"
#include <iostream>


Board::Board(int _size, bool _is_default_piece_order)
    : size(_size)
    , is_default_piece_order(_is_default_piece_order)
{

}

void Board::init()
{
    for (int j = 0; j < size; ++j)
    {
        for (int i = 0; i < size; ++i)
        {
            if (is_default_piece_order)
            {
                if ((i == size / 2 - 1) && (j == size / 2 - 1))
                {
                    board.push_back(Piece(i, j, black));
                }
                else if ((i == size / 2 - 1) && (j == size / 2))
                {
                    board.push_back(Piece(i, j, white));
                }
                else if ((i == size / 2) && (j == size / 2 - 1))
                {
                    board.push_back(Piece(i, j, white));
                }
                else if ((i == size / 2) && (j == size / 2))
                {
                    board.push_back(Piece(i, j, black));
                }
                else
                {
                    board.push_back(Piece(i, j));
                }
            }
            else
            {
                if ((i == size / 2 - 1) && (j == size / 2 - 1))
                {
                    board.push_back(Piece(i, j, white));
                }
                else if ((i == size / 2 - 1) && (j == size / 2))
                {
                    board.push_back(Piece(i, j, black));
                }
                else if ((i == size / 2) && (j == size / 2 - 1))
                {
                    board.push_back(Piece(i, j, black));
                }
                else if ((i == size / 2) && (j == size / 2))
                {
                    board.push_back(Piece(i, j, white));
                }
                else
                {
                    board.push_back(Piece(i, j));
                }
            }
        }
    }
    // Link all the pieces for quicker access
    for (auto& temp : board)
    {
        temp.setup_link(board, size);
    }
}

void Board::print_board() const
{
    std::cout << "  ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << static_cast<char>('a' + i);
    }
    std::cout << std::endl;
    for (int i = 0; i < size; ++i)
    {
        std::cout << static_cast<char>('a' + i) << " ";
        for (int j = 0; j < size; ++j)
        {
            std::cout << board.at(j + i * size).get_color();
        }
        std::cout << std::endl;
    }
}

GameState Board::check_game_end(bool & game_end, bool is_p1_black, color col) const
{
    game_end = false;
    int counter_B = 0, counter_W = 0, counter_C = 0, counter_OC = 0;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            counter_C += check_legal_move(i, j, col);
            counter_OC += check_legal_move(i, j, opposite_color(col));
            if (board.at(j + i * size).get_color() == black)
                ++counter_B;
            else if (board.at(j + i * size).get_color() == white)
                ++counter_W;
        }
    }
    if ((counter_B + counter_W == size * size) || (counter_C == 0 && counter_OC == 0))
    {
        game_end = true;
        if (counter_B == counter_W)
            return draw;
            //std::cout << "Draw!" << std::endl;
        else if (counter_B > counter_W)
        {
            if (is_p1_black)
                return p1_win;
            else
                return p2_win;
        }
            //std::cout << "B player wins." << std::endl;
        else if (counter_B < counter_W)
        {
            if (is_p1_black)
                return p2_win;
            else
                return p1_win;
        }
            //std::cout << "W player wins." << std::endl;
    }
    else if (counter_C == 0)
    {
        if (col == black)
        {
            if (is_p1_black)
                return p1_no_move;
            else
                return p2_no_move;
        }
            //std::cout << "B";
        else if (col == white)
        {
            if (is_p1_black)
                return p2_no_move;
            else
                return p1_no_move;
        }
            //std::cout << "W";
        //std::cout << " player has no valid move." << std::endl;
    }
    else
        return active;
}

void Board::make_move(int x, int y, color col)
{
    color opposite_col = opposite_color(col);
    int counter = 0;
    for (int i = 0; i < 8; ++i)
    {
        Piece * temp = board.at(x + y * size).c_get_surround().at(i);
        while (temp != nullptr)
        {
            if (temp->get_color() == opposite_col)
            {
                ++counter;
                temp = temp->c_get_surround().at(i);
            }
            else if ((temp->get_color() == col) && (counter < 1))
                break;
            else if ((temp->get_color() == col) && (counter >= 1))
            {
                board.at(x + y * size).set_color(col);
                Piece * col_temp = board.at(x + y * size).c_get_surround().at(i);
                for (int j = 0; j < counter; ++j)
                {
                    col_temp->set_color(col);
                    col_temp = col_temp->c_get_surround().at(i);
                }
                break;
            }
            else if (temp->get_color() == empty)
                break;
        }
        counter = 0;
    }
}

void Board::reset_board()
{
    for (int j = 0; j < size; ++j)
    {
        for (int i = 0; i < size; ++i)
        {
            if (is_default_piece_order)
            {
                if ((i == size / 2 - 1) && (j == size / 2 - 1))
                {
                    board.at(j + i * size).set_color(black);
                }
                else if ((i == size / 2 - 1) && (j == size / 2))
                {
                    board.at(j + i * size).set_color(white);
                }
                else if ((i == size / 2) && (j == size / 2 - 1))
                {
                    board.at(j + i * size).set_color(white);
                }
                else if ((i == size / 2) && (j == size / 2))
                {
                    board.at(j + i * size).set_color(black);
                }
                else
                {
                    board.at(j + i * size).set_color(empty);
                }
            }
            else
            {
                if ((i == size / 2 - 1) && (j == size / 2 - 1))
                {
                    board.at(j + i * size).set_color(white);
                }
                else if ((i == size / 2 - 1) && (j == size / 2))
                {
                    board.at(j + i * size).set_color(black);
                }
                else if ((i == size / 2) && (j == size / 2 - 1))
                {
                    board.at(j + i * size).set_color(black);
                }
                else if ((i == size / 2) && (j == size / 2))
                {
                    board.at(j + i * size).set_color(white);
                }
                else
                {
                    board.at(j + i * size).set_color(empty);
                }
            }
        }
    }
}