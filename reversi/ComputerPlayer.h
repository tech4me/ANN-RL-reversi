#pragma once

#include "Player.h"

enum ComputerType 
{
    random,
    greedy,
    qnet
};

class ComputerPlayer : public Player
{
private:
    ComputerType type;
public:
    ComputerPlayer(ComputerType _type);
    virtual ~ComputerPlayer() {};
    virtual void move(Board & board, bool & game_end);
};