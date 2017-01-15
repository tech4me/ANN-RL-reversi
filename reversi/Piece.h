#pragma once
#include <vector>
#include <iostream>

enum color
{
    black,
    white,
    empty
};

class Piece
{
private:
    color piece_color;
    int location_x;
    int location_y;
    std::vector<Piece *> surround_piece;

public:
    Piece(int _location_x, int _loaction_y, color _piece_color = empty);

    inline color get_color() const
    {
        return piece_color;
    }

    inline void set_color(color col)
    {
        piece_color = col;
    }

    inline std::vector<Piece *> & get_surround()
    {
        return surround_piece;
    }

    inline const std::vector<Piece *> & c_get_surround() const
    {
        return surround_piece;
    }
    // Setup the pointers between pieces to speed up future calculation
    void setup_link(std::vector<Piece>& board, int board_size);
};

inline color opposite_color(color in)
{
    if (in == black)
        return white;
    else
        return black;
}
std::ostream& operator<<(std::ostream& out, color in);