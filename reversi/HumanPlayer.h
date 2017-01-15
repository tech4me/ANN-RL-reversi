#pragma once

#include "Player.h"

class HumanPlayer : public Player
{
public:
    virtual ~HumanPlayer() {};
    virtual void move(Board & board, bool & game_end);
};