#include <iostream>
using namespace std;

bool invalidFlag = false;

double Power(double base, int exponent){
	if((base-0.0<0.0000001&&base-0.0>-0.0000001) && exponent<0){
		invalidFlag = true;
		return 0.0;
	}

	int absexponent = (exponent>0) ? exponent : (-exponent);
	double result = 1.0;
	if(absexponent > 1){
		result = base;
	}
	for(int i=absexponent; i>1; i=i>>1){
		result *= result;
	}
	if((absexponent&0x1) == 1){
		result *= base;
	}

	if(exponent < 0)
		result = 1.0/result;

	return result;
}


void testchap11(){
	double result =  Power(0, 0);
	if(invalidFlag)
		cout << "invild input" << endl;
	else
		cout << result << endl;
}
