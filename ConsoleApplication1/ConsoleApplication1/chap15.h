#include <iostream>
using namespace std;

typedef struct ListNode{
	int value;
	struct ListNode *next;
}ListNode;

ListNode* findLastNNode(ListNode *pHead, int n){
	int count = 0;
	ListNode *pBehind = NULL, *pPre = pHead;
	while(count<n && pPre!=NULL){
		count++;
		pPre = pPre->next;
	}
	if(count==n){
		pBehind = pHead;
	}else{
		throw exception("");
	}

	while(count==n && pPre!=NULL){
		pBehind = pBehind->next;
		pPre = pPre->next;
	}

	return pBehind;
}

void testchap15(){
	int data = 0;
	ListNode *pHead = NULL, *pre = NULL;
	cin >> data;
	if(data != -1){
		pHead = new ListNode;
		pre = pHead;
		pHead->value = data;
		pHead->next = NULL;
	}
	while(pHead){
		cin >> data;
		if(data == -1) break;
		ListNode *p = new ListNode;
		p->value = data;
		p->next = NULL;
		pre->next = p;
		pre = p;
	}
	try{
		cout << findLastNNode(pHead, 3)->value << endl;
	}catch(exception){
		cout << "list is to short" << endl;
	}

	getchar();
}
