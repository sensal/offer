#include <iostream>
using namespace std;

void printNumber(char *number){
	int i=0;
	while(number[i]=='0') i++;
	for(;number[i]!='\0';i++){
		cout << number[i];
	}
	cout << " ";
}

void printNext(char *number, int length, int index){
	if(index == length-1){
		printNumber(number);
		return;
	}

	for(int i=0; i<10; i++){
		number[index+1] = i + '0';
		printNext(number, length, index+1);
	}
}

void print(int n){
	char *number = new char[n+1];
	memset(number, '0', n);
	number[n] = '\0';
	for(int i=0; i<10; i++){
		number[0] = i + '0';
		printNext(number, n, 0);
	}
}

void testchap12(){
	print(3);
	cout << "done";
}
