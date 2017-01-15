#include "HumanPlayer.h"
#include <string>

void HumanPlayer::move(Board & board, bool & game_end)
{
    std::string input;
    std::cout << "Enter move for colour ";
    if (col == black)
        std::cout << 'B';
    else if (col == white)
        std::cout << 'W';
    std::cout << "(RowCol) :";
    std::cin >> input;
    auto it = input.cbegin();
    int x = *(it++) - 'a';
    int y = *(it++) - 'a';
    char z = *it;
    color input_col;
    if (z == 'B')
        input_col = black;
    else if (z == 'W')
        input_col = white;
    if ((input_col == black && col != black) || (input_col == white && col != white))
        game_end = true;
    if (board.position_on_board(x, y))
    {
        if (!board.check_legal_move(x, y, col))
            game_end = true;
    }
    else
        game_end = true;
    if (game_end)
    {
        std::cout << "Invalid move." << std::endl;
        std::cout << (opposite_color(col) == black) ? 'B' : 'W';
        std::cout << " player wins." << std::endl;
    }
    else
        board.make_move(x, y, col);
}