#include <iostream>

using namespace std;

void replaceSpace(char *str, int length){
	if(str==NULL || length==0) return;

	int i=0, count = 0;
	while(str[i]!='\0'){
		if(str[i] == ' ') count++;
		i++;
	}
	if(strlen(str)+count*2+1>length) return;

	char *p1 = str+strlen(str);
	char *p2 = str+strlen(str)+count*2;
	while(p1 >= str){
		if(*p1 != ' '){
			*(p2--) = *(p1--);
		}else{
			*(p2--) = '0';
			*(p2--) = '2';
			*(p2--) = '%';
			p1--;
		}
	}
}

void testchap4(){
	char str[21] = " we are happy.";
	replaceSpace(str, sizeof(str));

	cout << str << endl;
}

