#include <iostream>
using namespace std;

class CMyString{
public:
	CMyString(){m_pData = NULL;}
	CMyString(char *pData){
		m_pData = new char[strlen(pData) + 1];
		strcpy(m_pData, pData);
	}
	CMyString(const CMyString& str);
	CMyString& operator=(const CMyString& other){
		if(this == &other)
			return *this;

		delete []m_pData;//删除数组或指针指向的内容
		m_pData = NULL;

		m_pData = new char[strlen(other.m_pData) + 1];//申请空间
		strcpy(m_pData, other.m_pData);
		return *this;
	}
	void print(){cout << m_pData << endl;}
	~CMyString(void){delete []m_pData;}

private:
	char *m_pData;
};

void testchap1(){
	CMyString str = "hello world";
	CMyString str1, str2;
	str2 = str1 = str;
	str1.print();
	str2.print();
}