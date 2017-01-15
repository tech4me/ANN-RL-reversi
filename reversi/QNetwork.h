#pragma once

#include "fann_include\doublefann.h"
#include "fann_include\fann_cpp.h"

class QNetwork
{
private:
    FANN::neural_net nn;
public:
    QNetwork();
    double run(double input[]); // No array size check implemented
};