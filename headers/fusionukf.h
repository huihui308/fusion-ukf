#ifndef FUSIONUKF_H_
#define FUSIONUKF_H_

#include "settings.h"
#include "datapoint.h"
#include "Eigen/Dense"
#include "stateupdater.h"
#include "statepredictor.h"
#include "measurementpredictor.h"


using Eigen::MatrixXd;
using Eigen::VectorXd;


class FusionUKF{

  private:
    bool initialized;
    long long timestamp;
    double nis;
    VectorXd x = VectorXd(NX);
    MatrixXd P = MatrixXd(NX, NX);
    StatePredictor statePredictor;
    MeasurementPredictor measurementPredictor;
    StateUpdater stateUpdater;

    //PRIVATE FUNCTIONS
    void initialize(const DataPoint& data);
    void update(const DataPoint& data);

  public:
    FusionUKF();
    void process(const DataPoint& data);
    VectorXd get() const;
    double get_nis() const;
};

#endif //FUSIONUKF_H_
