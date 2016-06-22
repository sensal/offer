#include <iostream>
#include <string>
using namespace std;

string add_s(string num1, string num2){
	string result;
	int i=num1.size()-1, j=num2.size()-1, carry=0;
	if((num1[0]!='-'&&num2[0]!='-') || (num1[0]=='-'&&num2[0]=='-')){
		for(; i>=0||j>=0||carry; i--,j--){
			int da = (i>=0 && num1[i]!='-') ? (num1[i]-'0') : 0;
			int db = (j>=0 && num2[j]!='-') ? (num2[j]-'0') : 0;
			int s = da + db + carry;
			result.push_back(s%10 + '0');
			carry = s/10;
		}
		if(num1[0]=='-'&&num2[0]=='-') result.push_back('-');
	}else{

	}

	reverse(result.begin(), result.end());
	return result;
}


void testchap12_1(){
	string num1, num2;
	cin >> num1 >> num2;
	string result = add_s(num1, num2);
	cout << result << endl;
	getchar();
}
