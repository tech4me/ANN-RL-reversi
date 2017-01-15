#include "Piece.h"

Piece::Piece(int _location_x, int _loaction_y, color _piece_color)
    : location_x(_location_x)
    , location_y(_loaction_y)
    , piece_color(_piece_color)
{

}

void Piece::setup_link(std::vector<Piece>& board, int board_size)
{
    auto it = board.begin();
    it += (location_x + location_y * board_size);// Set it to the location
    if ((location_x == 0) && ((location_y != 0) && (location_y != board_size - 1)))
    {
        surround_piece.push_back(nullptr);
        surround_piece.push_back(&*(it - board_size));
        surround_piece.push_back(&*(it - board_size + 1));
        surround_piece.push_back(nullptr);
        surround_piece.push_back(&*(it + 1));
        surround_piece.push_back(nullptr);
        surround_piece.push_back(&*(it + board_size));
        surround_piece.push_back(&*(it + board_size + 1));
    }
    else if ((location_x == board_size - 1) && ((location_y != 0) && (location_y != board_size - 1)))
    {
        surround_piece.push_back(&*(it - board_size - 1));
        surround_piece.push_back(&*(it - board_size));
        surround_piece.push_back(nullptr);
        surround_piece.push_back(&*(it - 1));
        surround_piece.push_back(nullptr);
        surround_piece.push_back(&*(it + board_size - 1));
        surround_piece.push_back(&*(it + board_size));
        surround_piece.push_back(nullptr);
    }
    else if ((location_y == 0) && ((location_x != 0) && (location_x != board_size - 1)))
    {
        surround_piece.push_back(nullptr);
        surround_piece.push_back(nullptr);
        surround_piece.push_back(nullptr);
        surround_piece.push_back(&*(it - 1));
        surround_piece.push_back(&*(it + 1));
        surround_piece.push_back(&*(it + board_size - 1));
        surround_piece.push_back(&*(it + board_size));
        surround_piece.push_back(&*(it + board_size + 1));
    }
    else if ((location_y == board_size - 1) && ((location_x != 0) && (location_x != board_size - 1)))
    {
        surround_piece.push_back(&*(it - board_size - 1));
        surround_piece.push_back(&*(it - board_size));
        surround_piece.push_back(&*(it - board_size + 1));
        surround_piece.push_back(&*(it - 1));
        surround_piece.push_back(&*(it + 1));
        surround_piece.push_back(nullptr);
        surround_piece.push_back(nullptr);
        surround_piece.push_back(nullptr);
    }
    else if ((location_x == 0) && (location_y == 0))
    {
        surround_piece.push_back(nullptr);
        surround_piece.push_back(nullptr);
        surround_piece.push_back(nullptr);
        surround_piece.push_back(nullptr);
        surround_piece.push_back(&*(it + 1));
        surround_piece.push_back(nullptr);
        surround_piece.push_back(&*(it + board_size));
        surround_piece.push_back(&*(it + (board_size + 1)));
    }
    else if ((location_x == 0) && (location_y == board_size - 1))
    {
        surround_piece.push_back(nullptr);
        surround_piece.push_back(&*(it - board_size));
        surround_piece.push_back(&*(it - board_size + 1));
        surround_piece.push_back(nullptr);
        surround_piece.push_back(&*(it + 1));
        surround_piece.push_back(nullptr);
        surround_piece.push_back(nullptr);
        surround_piece.push_back(nullptr);
    }
    else if ((location_x == board_size - 1) && (location_y == 0))
    {
        surround_piece.push_back(nullptr);
        surround_piece.push_back(nullptr);
        surround_piece.push_back(nullptr);
        surround_piece.push_back(&*(it - 1));
        surround_piece.push_back(nullptr);
        surround_piece.push_back(&*(it + board_size - 1));
        surround_piece.push_back(&*(it + board_size));
        surround_piece.push_back(nullptr);
    }
    else if ((location_x == board_size - 1) && (location_y == board_size - 1))
    {
        surround_piece.push_back(&*(it - board_size - 1));
        surround_piece.push_back(&*(it - board_size));
        surround_piece.push_back(nullptr);
        surround_piece.push_back(&*(it - 1));
        surround_piece.push_back(nullptr);
        surround_piece.push_back(nullptr);
        surround_piece.push_back(nullptr);
        surround_piece.push_back(nullptr);
    }
    else
    {
        surround_piece.push_back(&*(it - board_size - 1));
        surround_piece.push_back(&*(it - board_size));
        surround_piece.push_back(&*(it - board_size + 1));
        surround_piece.push_back(&*(it - 1));
        surround_piece.push_back(&*(it + 1));
        surround_piece.push_back(&*(it + board_size - 1));
        surround_piece.push_back(&*(it + board_size));
        surround_piece.push_back(&*(it + board_size + 1));
    }
}

std::ostream& operator<<(std::ostream& out, color in)
{
    if (in == black)
    {
        return out << 'B';
    }
    else if (in == white)
    {
        return out << 'W';
    }
    else
    {
        return out << 'U';
    }
}