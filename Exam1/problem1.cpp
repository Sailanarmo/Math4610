#include <boost/math/tools/minima.hpp>
#include <iostream>


int main()
{
	int bits = std::numeric_limits<double>::digits;
	
	const boost::uintmax_t maxit = 4000.0;
	boost::uintmax_t it = maxit;
	
	std::pair<double,double> r = boost::math::tools::brent_find_minima([](double x){return std::sin(x);}, -10.0,10.0, bits, it);
	std::pair<double,double> y = boost::math::tools::brent_find_minima([](double x){return std::sin(-x)/x;}, -10.0,10.0, bits, it);
	
	std::cout << "x at minimum = " << r.first << ", f(" << r.first << ") = " << r.second << " after " << it << " iterations. " << std::endl;	
	std::cout << "y at minimum = " << y.first << ", f(" << y.first << ") = " << y.second << " after " << it << " iterations. " << std::endl;	

}
