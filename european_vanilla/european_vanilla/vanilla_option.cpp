#include "vanilla_option.h"
#include <cmath>

double vanilla_option::getk() const{
	return k;
}

double vanilla_option::getr() const{
	return r;
}

double vanilla_option::gett() const{
	return t;
}

double vanilla_option::gets() const{
	return s;
}

double vanilla_option::getsigma() const{
	return sigma;
}

void vanilla_option :: init() {
	k = 100.0;
	r = 0.05;
	t = 1.0;
	s = 100.0;
	sigma = 0.2; 
}

void vanilla_option::copy(const vanilla_option& rhs) {
	k = rhs.getk();
	r = rhs.getr();
	t = rhs.gett();
	s = rhs.gets();
	sigma = rhs.getsigma();
}

vanilla_option::vanilla_option() { init(); }

vanilla_option::vanilla_option( const double& _k, const double& _r, const double& _t, const double& _s, const double& _sigma) {
	k = _k;
	r = _r;
	t = _t;
	s = _s;
	sigma = _sigma;
}

vanilla_option::vanilla_option(const vanilla_option& rhs) {
	copy(rhs);
}

double vanilla_option::getCallOptionPrice()const {
	double sigma_sqrt = sigma * sqrt(t);
	double d_1 = (log(s / k) + (r + sigma * sigma * 0.5) * t) / sigma_sqrt;
	double d_2 = d_1 - sigma_sqrt;
	return s * erfc(-d_1 / sqrt(2))/2 - k * exp(-r * t) * erfc(-d_2 / sqrt(2))/2;
}

double vanilla_option::getPutOptionPrice()const {
	double sigma_sqrt = sigma * sqrt(t);
	double d_1 = (log(s / k) + (r + sigma * sigma * 0.5) * t) / sigma_sqrt;
	double d_2 = d_1 - sigma_sqrt;
	return -s * erfc(d_1 / sqrt(2)) / 2 + k * exp(-r * t) * erfc(d_2 / sqrt(2)) / 2;
}