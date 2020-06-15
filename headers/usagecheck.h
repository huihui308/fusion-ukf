#ifndef USAGECHECK_H_
#define USAGECHECK_H_

#include <vector>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include "datapoint.h"
#include "Eigen/Dense"


using namespace std;
using std::vector;
using Eigen::MatrixXd;
using Eigen::VectorXd;


void check_arguments(int argc, char* argv[]);
void check_files(ifstream& in_file, string& in_nams, ofstream& out_file, string& out_name);
void print_UKF_data(const VectorXd &RMSE, const vector<VectorXd> &estimations,
    const vector<VectorXd> &ground_truths, const vector<DataPoint> &all_sensor_data);

#endif /* USAGECHECK_H_ */
