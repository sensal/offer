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

		delete []m_pData;//ɾ�������ָ��ָ�������
		m_pData = NULL;

		m_pData = new char[strlen(other.m_pData) + 1];//����ռ�
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