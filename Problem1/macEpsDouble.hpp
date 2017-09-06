#ifndef MAC_EPS_DOUBLE_HPP
#define MAC_EPS_DOUBLE_HPP


class MacEpsDouble
{

public:

	int precision(int n);
	double errorDouble();

private:
	double e = 1.0; //error
	double x = 1.0; //variable
	double y = 1.0; //variable
	double error = 0.0;
	int prec = 0;
};




#endif
