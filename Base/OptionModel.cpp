#include "OptionModel.h"
#include <limits>

double OptionModel::callOptionVal(double spotPrice, double strikePrice, double exipiration, double riskFreeInterestRate,
                                double volatility, double dividendYeild) const {

}
double OptionModel::callOptionDelta(double spotPrice, double strikePrice, double exipiration, double riskFreeInterestRate,
                                double volatility, double dividendYeild) const {
            return (
                this->callOptionVal(spotPrice + __FLT_EPSILON__, strikePrice, exipiration, riskFreeInterestRate, volatility, dividendYeild) -
                this->callOptionVal(spotPrice - __FLT_EPSILON__, strikePrice, exipiration, riskFreeInterestRate, volatility, dividendYeild)
            ) / (2.0 * __FLT_EPSILON__);
            
}
double OptionModel::callOptionVega(double spotPrice, double strikePrice, double exipiration, double riskFreeInterestRate,
                                double volatility, double dividendYeild) const {
            return (
                this->callOptionVal(spotPrice, strikePrice, exipiration, riskFreeInterestRate, volatility + __FLT_EPSILON__, dividendYeild) -
                this->callOptionVal(spotPrice, strikePrice, exipiration, riskFreeInterestRate, volatility - __FLT_EPSILON__, dividendYeild)
            ) / (2.0 * __FLT_EPSILON__);
}
double OptionModel::callOptionTheta(double spotPrice, double strikePrice, double exipiration, double riskFreeInterestRate,
                                double volatility, double dividendYeild) const {
            return (
                this->callOptionVal(spotPrice, strikePrice, exipiration + __FLT_EPSILON__, riskFreeInterestRate, volatility, dividendYeild) -
                this->callOptionVal(spotPrice, strikePrice, exipiration - __FLT_EPSILON__, riskFreeInterestRate, volatility, dividendYeild)
            ) / (2.0 * __FLT_EPSILON__);
}
double OptionModel::callOptionRho(double spotPrice, double strikePrice, double exipiration, double riskFreeInterestRate,
                                double volatility, double dividendYeild) const {
            return (
                this->callOptionVal(spotPrice, strikePrice, exipiration, riskFreeInterestRate + __FLT_EPSILON__, volatility, dividendYeild) -
                this->callOptionVal(spotPrice, strikePrice, exipiration, riskFreeInterestRate - __FLT_EPSILON__, volatility, dividendYeild)
            ) / (2.0 * __FLT_EPSILON__);
}



double OptionModel::putOptionVal(double spotPrice, double strikePrice, double exipiration, double riskFreeInterestRate,
                           double volatility, double dividendYeild) const {
        return (
                this->putOptionVal(spotPrice + __FLT_EPSILON__, strikePrice, exipiration, riskFreeInterestRate, volatility, dividendYeild) -
                this->putOptionVal(spotPrice - __FLT_EPSILON__, strikePrice, exipiration, riskFreeInterestRate, volatility, dividendYeild)
            ) / (2.0 * __FLT_EPSILON__);
}
double OptionModel::putOptionDelta(double spotPrice, double strikePrice, double exipiration, double riskFreeInterestRate,
                           double volatility, double dividendYeild) const {
        return (
                this->putOptionVal(spotPrice, strikePrice, exipiration, riskFreeInterestRate, volatility + __FLT_EPSILON__, dividendYeild) -
                this->putOptionVal(spotPrice, strikePrice, exipiration, riskFreeInterestRate, volatility - __FLT_EPSILON__, dividendYeild)
            ) / (2.0 * __FLT_EPSILON__);                    
}
double OptionModel::putOptionVega(double spotPrice, double strikePrice, double exipiration, double riskFreeInterestRate,
                           double volatility, double dividendYeild) const {
        return (
                this->putOptionVal(spotPrice, strikePrice, exipiration + __FLT_EPSILON__, riskFreeInterestRate, volatility, dividendYeild) -
                this->putOptionVal(spotPrice, strikePrice, exipiration - __FLT_EPSILON__, riskFreeInterestRate, volatility, dividendYeild)
            ) / (2.0 * __FLT_EPSILON__);            
}
double OptionModel::putOptionTheta(double spotPrice, double strikePrice, double exipiration, double riskFreeInterestRate,
                           double volatility, double dividendYeild) const {
        return (
                this->putOptionVal(spotPrice, strikePrice, exipiration + __FLT_EPSILON__, riskFreeInterestRate, volatility, dividendYeild) -
                this->putOptionVal(spotPrice, strikePrice, exipiration - __FLT_EPSILON__, riskFreeInterestRate, volatility, dividendYeild)
            ) / (2.0 * __FLT_EPSILON__);                
}
double OptionModel::putOptionRho(double spotPrice, double strikePrice, double exipiration, double riskFreeInterestRate,
                           double volatility, double dividendYeild) const {
        return (
                this->putOptionVal(spotPrice, strikePrice, exipiration, riskFreeInterestRate + __FLT_EPSILON__, volatility, dividendYeild) -
                this->putOptionVal(spotPrice, strikePrice, exipiration, riskFreeInterestRate - __FLT_EPSILON__, volatility, dividendYeild)
            ) / (2.0 * __FLT_EPSILON__);                    
}

OptionFunctions::OptionFunctions(OptionModel& _model) : model(_model) {}
OptionFunctions::~OptionFunctions() {}


double OptionFunctions::impliedInterestRate(double _optionValue, double _spotPrice, double _strikePrice, double expiration, double volatility, double dividendYeild) 
const {
    double impliedInterestRate = 0.0;
    
}

int main() {

}