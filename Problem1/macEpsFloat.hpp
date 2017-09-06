#ifndef MAC_EPS_FLOAT_HPP
#define MAC_EPS_FLOAT_HPP


class MacEpsFloat
{

public:

	int precision(int n);
	float errorFloat();

private:
	float e = 1.0; //error
	float x = 1.0; //variable
	float y = 0.0; //variable
	float error = 0.0;
	int prec = 0;
};




#endif
