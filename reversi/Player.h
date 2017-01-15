#pragma once

#include "Piece.h"
#include "Board.h"

class Player
{
protected:
    color col;
    virtual ~Player() {};
public:
    color get_color() const;
    void init_player(bool _is_black);
    virtual void move(Board & board, bool & game_end) = 0;
};