#ifndef OPTION_MODEL
#define OPTION_MODEL

class OptionModel {
public:
    
    OptionModel();
    virtual ~OptionModel();

    virtual double callOptionVal(double spotPrice, double strikePrice, double exipiration, double riskFreeInterestRate,
                                double volatility, double dividendYeild) const = 0;
    virtual double callOptionDelta(double spotPrice, double strikePrice, double exipiration, double riskFreeInterestRate,
                                double volatility, double dividendYeild) const;
    virtual double callOptionVega(double spotPrice, double strikePrice, double exipiration, double riskFreeInterestRate,
                                double volatility, double dividendYeild) const;
    virtual double callOptionTheta(double spotPrice, double strikePrice, double exipiration, double riskFreeInterestRate,
                                double volatility, double dividendYeild) const;
   virtual double callOptionGamma(double spotPrice, double strikePrice, double exipiration, double riskFreeInterestRate,
                                double volatility, double dividendYeild) const;
    virtual double callOptionRho(double spotPrice, double strikePrice, double exipiration, double riskFreeInterestRate,
                                double volatility, double dividendYeild) const ;

    virtual double putOptionVal(double spotPrice, double strikePrice, double exipiration, double riskFreeInterestRate,
                           double volatility, double dividendYeild) const = 0;
    virtual double putOptionDelta(double spotPrice, double strikePrice, double exipiration, double riskFreeInterestRate,
                           double volatility, double dividendYeild) const;
    virtual double putOptionVega(double spotPrice, double strikePrice, double exipiration, double riskFreeInterestRate,
                           double volatility, double dividendYeild) const;
    virtual double putOptionTheta(double spotPrice, double strikePrice, double exipiration, double riskFreeInterestRate,
                           double volatility, double dividendYeild) const;
    virtual double putOptionGamma(double spotPrice, double strikePrice, double exipiration, double riskFreeInterestRate,
                           double volatility, double dividendYeild) const;
    virtual double putOptionRho(double spotPrice, double strikePrice, double exipiration, double riskFreeInterestRate,
                           double volatility, double dividendYeild) const;
};

class OptionFunctions {
protected:
    const OptionModel& model;

public:
    OptionFunctions(OptionModel& model);
    virtual ~OptionFunctions();


    inline virtual double value(double spotPrice, double strikePrice, double expiration, double riskFreeInterestRate, 
                                double volatility, double dividendYeild) const = 0;
    inline virtual double delta(double spotPrice, double strikePrice, double expiration, double riskFreeInterestRate, 
                                double volatility, double dividendYeild) const = 0;       
    inline virtual double vega(double spotPrice, double strikePrice, double expiration, double riskFreeInterestRate, 
                                double volatility, double dividendYeild) const = 0;
    inline virtual double theta(double spotPrice, double strikePrice, double expiration, double riskFreeInterestRate, 
                                double volatility, double dividendYeild) const = 0;
    inline virtual double gamma(double spotPrice, double strikePrice, double expiration, double riskFreeInterestRate, 
                                double volatility, double dividendYeild) const = 0;
    inline virtual double rho(double spotPrice, double strikePrice, double expiration, double riskFreeInterestRate, 
                                double volatility, double dividendYeild) const = 0;
    
    double impliedInterestRate(double optionval, double spotprice, double strikeprice, double expiration, double volatility,
                                double dividendYeild) const;
    double impliedVolatility(double optionval, double spotprice, double strikeprice, double expiration, double volatility,
                                double dividendYeild) const;
};

class CallOption : public OptionFunctions {
public:
    CallOption(OptionModel& model);
    virtual ~CallOption();

    inline virtual double value(double spotPrice, double strikePrice, double expiration, double riskFreeInterestRate, 
                                double volatility, double dividendYeild) const override;
    inline virtual double delta(double spotPrice, double strikePrice, double expiration, double riskFreeInterestRate, 
                                double volatility, double dividendYeild) const override;       
    inline virtual double vega(double spotPrice, double strikePrice, double expiration, double riskFreeInterestRate, 
                                double volatility, double dividendYeild) const override;
    inline virtual double theta(double spotPrice, double strikePrice, double expiration, double riskFreeInterestRate, 
                                double volatility, double dividendYeild) const override;
    inline virtual double gamma(double spotPrice, double strikePrice, double expiration, double riskFreeInterestRate, 
                                double volatility, double dividendYeild) const override;
    inline virtual double rho(double spotPrice, double strikePrice, double expiration, double riskFreeInterestRate, 
                                double volatility, double dividendYeild) const override;
};

class PutOption : public OptionFunctions {
public: 
    PutOption(OptionModel& model);
    virtual ~PutOption();

    inline virtual double value(double spotPrice, double strikePrice, double expiration, double riskFreeInterestRate, 
                                double volatility, double dividendYeild) const override;
    inline virtual double delta(double spotPrice, double strikePrice, double expiration, double riskFreeInterestRate, 
                                double volatility, double dividendYeild) const override;       
    inline virtual double vega(double spotPrice, double strikePrice, double expiration, double riskFreeInterestRate, 
                                double volatility, double dividendYeild) const override;
    inline virtual double theta(double spotPrice, double strikePrice, double expiration, double riskFreeInterestRate, 
                                double volatility, double dividendYeild) const override;
    inline virtual double gamma(double spotPrice, double strikePrice, double expiration, double riskFreeInterestRate, 
                                double volatility, double dividendYeild) const override;
    inline virtual double rho(double spotPrice, double strikePrice, double expiration, double riskFreeInterestRate, 
                                double volatility, double dividendYeild) const override;
};




#endif