#pragma once

#include "QNetwork.h"
#include "Board.h"

class Agent
{
private:
    QNetwork nn;
    double alpha; // Learning Rate
    double gamma; // Discount Factor
public:
    Agent();
    void epochs(Board & board, std::vector<std::tuple<int, int, int>> move_list);
};