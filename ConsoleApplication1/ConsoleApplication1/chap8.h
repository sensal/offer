#include <iostream>
using namespace std;

int min(int data[], int start, int end){
	int mid;
	while(end > start){
		mid = (start + end)/2;
		if(data[mid] >= data[end]){
			start = mid;
		}else if(data[mid] <= data[start]){
			end = mid;
		}else if(data[mid]==data[start]&&data[mid]==data[end]){
			int res = data[start];
			for(int i=start; i<end; i++){
				if(res > data[i])
					res = data[i];
			}
			return res;
		}else{
			return data[start];
		}
	}
	return data[start];
}

void testchap8(){
	int data[]={3,3,3,3,1,2};
	cout << min(data, 0, sizeof(data)/sizeof(int)-1);
}
