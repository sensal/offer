#include<iostream>
using namespace std;

typedef struct listNode16{
	int m_nKey;
	struct listNode16 *m_pNext;
}ListNode16;

ListNode16* reverseList(ListNode16 *pHead){
	if(pHead == NULL) return NULL;
	if(pHead->m_pNext == NULL) return pHead;

	ListNode16 *cur = pHead->m_pNext, *pre = pHead, *next = cur->m_pNext;
	pHead->m_pNext = NULL;
	while(cur != NULL){
		cur->m_pNext = pre;
		pre = cur;
		cur = next;
		if(next != NULL)
			next = next->m_pNext;
		else break;
	}

	return pre;
}

void createList(ListNode16 **pHead){
	int data = 0;
	ListNode16 *pre = NULL;
	cin >> data;
	if(data != -1){
		(*pHead) = new ListNode16;
		pre = *pHead;
		(*pHead)->m_nKey = data;
		(*pHead)->m_pNext = NULL;
	}
	while((*pHead)){
		cin >> data;
		if(data == -1) break;
		ListNode16 *p = new ListNode16;
		p->m_nKey = data;
		p->m_pNext = NULL;
		pre->m_pNext = p;
		pre = p;
	}
}


void testchap16(){
	ListNode16 *pHead = NULL;
	createList(&pHead);

	ListNode16 *p = reverseList(pHead);
	while(p!=NULL){
		cout << p->m_nKey << " ";
		p = p->m_pNext;
	}
	cout << endl;
	getchar();
}
