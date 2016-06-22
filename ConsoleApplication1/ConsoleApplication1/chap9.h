#include <iostream>

using namespace std;

long long fib(int n){
	int fib[2] = {0, 1};
	if(n<2)
		return fib[n];

	long long fibone = 0;
	long long fibtwo = 1;
	long long fibsum = 0;
	for(int i=2; i<=n; i++){
		fibsum = fibone + fibtwo;
		fibone = fibtwo;
		fibtwo = fibsum;
	}

	return fibsum;
}


void testchap9(){
	cout << fib(100) << endl;
}
