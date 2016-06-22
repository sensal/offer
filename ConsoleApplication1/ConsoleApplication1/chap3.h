#include <iostream>

using namespace std;

bool findNumber(int *data, int rows, int columns, int value){
	int i, j;
	if(data==NULL || rows<0 || columns<0)
		return false;
	for(i=0, j=columns-1; i<rows, j>=0;){
		if(*(data + i*columns + j) < value){
			i++;
		}else if(*(data + i*columns + j) > value){
			j--;
		}else{
			return true;
		}
	}

	return false;
}


void testchap3(){
	int data[] = {1,2,3,4,5,6,7,8,9};
	cout << findNumber(data, 3, 3, 0) << endl;
}