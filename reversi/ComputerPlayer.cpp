#include "ComputerPlayer.h"
#include <tuple>
#include <cstdlib>
#include <ctime>

ComputerPlayer::ComputerPlayer(ComputerType _type)
    : type(_type)
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

void ComputerPlayer::move(Board & board, bool & game_end)
{
    game_end = false;
    std::vector<std::tuple<int, int, int>> move_list; // First two int (x, y) the last one indicate pices fliped
    for (int i = 0; i < board.get_board_size(); ++i)
    {
        for (int j = 0; j < board.get_board_size(); ++j)
        {
            if (int flip_num = board.check_legal_move(i, j, col))
            {
                move_list.push_back(std::tuple<int, int, int>(i, j, flip_num));
            }
        }
    }

    switch (type)
    {
    case random:
    {
        std::size_t rand_num = std::rand() % move_list.size();
        auto move = move_list.at(rand_num);
        board.make_move(std::get<0>(move), std::get<1>(move), col);
        break;
    }
    case greedy:
    {
        int x;
        int y;
        int max_flip = 0;
        for (auto temp : move_list)
        {
            if (std::get<2>(temp) >= max_flip)
            {
                x = std::get<0>(temp);
                y = std::get<1>(temp);
                max_flip = std::get<2>(temp);
            }
        }
        board.make_move(x, y, col);
        break;
    }
    case qnet:
    {
        break;
    }
    default:
        break;
    }
}