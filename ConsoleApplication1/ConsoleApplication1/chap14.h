#include <iostream>
using namespace std;

void reorder(int *num, int length, bool (*func)(int)){
	int *pBegin = num, *pEnd = num+length-1;
	while(pEnd > pBegin){
		while(pBegin<pEnd && (!func(*pBegin))) pBegin++;
		while(pBegin<pEnd && (func(*pEnd))) pEnd--;
		if(pBegin<pEnd){
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}

bool isEven(int n){
	if((n&0x1) == 0) return true;
	return false;
}

void testchap14(){
	int num[] = {2,4,3,8,1,3,5,7};
	reorder(num, 8, isEven);
	for(int i=0; i<8; i++){
		cout << num[i] << " ";
	}
	cout << endl;
}
