#include "fusionukf.h"


FusionUKF::FusionUKF()
{
    this->initialized = false;
}

void FusionUKF::initialize(const DataPoint& aiqData)
{
    this->x = aiqData.get_state();
    this->P = MatrixXd::Identity(NX, NX);
    this->timestamp = aiqData.get_timestamp();
    this->initialized = true;
}

void FusionUKF::update(const DataPoint& aiqData)
{
    VectorXd predicted_z;
    MatrixXd S, sigma_x, sigma_z;

    // get the time difference in seconds
    double dt = (aiqData.get_timestamp() - this->timestamp) / 1.0e6;
    // STATE PREDICTION
    // get predicted state and covariance of predicted state, predicted sigma points in state space
    this->statePredictor.process(this->x, this->P, dt);
    this->x = this->statePredictor.getx();
    this->P = this->statePredictor.getP();
    sigma_x = this->statePredictor.get_sigma();

    // MEASUREMENT PREDICTION
    // get predicted measurement, covariance of predicted measurement, predicted sigma points in measurement space
    this->measurementPredictor.process(sigma_x, aiqData.get_type());
    predicted_z = this->measurementPredictor.getz();
    S = this->measurementPredictor.getS();
    sigma_z = this->measurementPredictor.get_sigma();

    // STATE UPDATE
    // updated the state and covariance of state... also get the nis
    this->stateUpdater.process(this->x, predicted_z, aiqData.get(), S, this->P, sigma_x, sigma_z);
    this->x = this->stateUpdater.getx();
    this->P = this->stateUpdater.getP();
    this->nis = this->stateUpdater.get_nis();

    // update timestamp
    this->timestamp = aiqData.get_timestamp();
}

void FusionUKF::process(const DataPoint& aiqData)
{
    this->initialized ? this->update(aiqData) : this->initialize(aiqData);
}

VectorXd FusionUKF::get() const
{
    return this->x;
}

double FusionUKF::get_nis() const
{
    return this->nis;
}
