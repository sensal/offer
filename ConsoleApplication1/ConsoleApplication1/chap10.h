#include <iostream>
using namespace std;

int numberof1(int n){
	int count = 0;
	while(n){
		count++;
		n = (n-1)&n;
	}
	return count;
}

void testchap10(){
	cout << numberof1(-1) << endl;
}
