#ifndef TOOLS_H_
#define TOOLS_H_

#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include "Eigen/Dense"


using Eigen::MatrixXd;
using Eigen::VectorXd;


extern
double normalize(const double a);
extern
VectorXd calculate_RMSE(
    const std::vector<VectorXd>& estimations,
    const std::vector<VectorXd>& ground_truths);


#endif /* TOOLS_H_ */
