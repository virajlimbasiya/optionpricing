#pragma once
class vanilla_option
{
public:
	vanilla_option();
	vanilla_option(const double& _k, const double& _r, const double& _t, const double& _s, const double& _sigma);
	vanilla_option(const vanilla_option& rhs);
	vanilla_option& operator=(const vanilla_option& rhs);
	double getk()const;
	double getr()const;
	double gett()const;
	double gets()const;
	double getsigma()const;
	double getCallOptionPrice()const;
	double getPutOptionPrice()const;
private:
	void init();	
	void copy(const vanilla_option& rhs);
	double k; 
	double r;
	double t;
	double s;
	double sigma;
};

