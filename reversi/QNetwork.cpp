#include "QNetwork.h"
#include <iostream>

QNetwork::QNetwork()
{
    // Bug in create_standard so have to use create_standard_array
    unsigned int layers[] = {10, 6, 1 };
    nn.create_standard_array(3, layers);
    nn.set_learning_rate(0.7f);
    nn.set_activation_function_hidden(FANN::SIGMOID_SYMMETRIC);
    nn.set_activation_function_output(FANN::LINEAR);
    nn.randomize_weights(-1.0, 1.0);
    nn.print_connections();
    double test[] = {0, 0, 0, 1, 5, -2, 3, 1, 2, 5 };
    std::cout << *nn.run(test) << std::endl;
}

double QNetwork::run(double input[])
{
    return *nn.run(input);
}