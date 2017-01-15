#include "Player.h"
#include <string>


color Player::get_color() const
{
    return col;
}

void Player::init_player(bool _is_black)
{
    if (_is_black)
        col = black;
    else
        col = white;
}