#include <iostream>
using namespace std;

typedef struct listNode17{
	int m_nKey;
	struct listNode17 *m_pNext;
}ListNode17;

void createList(ListNode17 **pHead){
	int data = 0;
	ListNode17 *pre = NULL;
	cin >> data;
	if(data != -1){
		(*pHead) = new ListNode17;
		pre = *pHead;
		(*pHead)->m_nKey = data;
		(*pHead)->m_pNext = NULL;
	}
	while((*pHead)){
		cin >> data;
		if(data == -1) break;
		ListNode17 *p = new ListNode17;
		p->m_nKey = data;
		p->m_pNext = NULL;
		pre->m_pNext = p;
		pre = p;
	}
}

ListNode17* mergeList(ListNode17 *pHead1, ListNode17 *pHead2){
	if(pHead1 == NULL)
		return pHead2;
	else if(pHead2 == NULL)
		return pHead1;

	ListNode17 *pHead = NULL;
	if(pHead1->m_nKey >= pHead2->m_nKey){
		pHead = pHead2;
		pHead2 = pHead2->m_pNext;
	}else{
		pHead = pHead1;
		pHead1 = pHead1->m_pNext;
	}

	ListNode17 *cur = pHead;
	while(pHead1!=NULL && pHead2!=NULL){
		if(pHead1->m_nKey >= pHead2->m_nKey){
			cur->m_pNext = pHead2;
			pHead2 = pHead2->m_pNext;
		}else{
			cur->m_pNext = pHead1;
			pHead1 = pHead1->m_pNext;
		}
		cur = cur->m_pNext;
	}
	if(pHead1 == NULL) cur->m_pNext = pHead2;
	if(pHead2 == NULL) cur->m_pNext = pHead1;

	return pHead;
}


void testchap17(){
	ListNode17 *pHead1=NULL, *pHead2=NULL;
	createList(&pHead1);
	createList(&pHead2);

	ListNode17 *pHead=NULL;
	pHead = mergeList(pHead1, pHead2);
	while(pHead!=NULL){
		cout << pHead->m_nKey << " ";
		pHead = pHead->m_pNext;
	}
	cout << endl;
	getchar();
}
