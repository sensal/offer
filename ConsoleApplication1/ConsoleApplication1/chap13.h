#include <iostream>
using namespace std;

typedef struct listNode0{
	int data;
	struct listNode0 *next;
}listNode1;

void deleteNode(listNode1 *pHead, listNode1 *toDeletedNode){
	if(toDeletedNode->next != NULL){
		listNode0 *temp = toDeletedNode->next;
		toDeletedNode->data = toDeletedNode->next->data;
		toDeletedNode->next = toDeletedNode->next->next;
		delete temp;
		temp = NULL;
	}else if(pHead == toDeletedNode){
		pHead->next = NULL;
		delete toDeletedNode;
		toDeletedNode = NULL;
	}else{
		listNode0 *p = pHead;
		while(p->next != toDeletedNode){
			p = p->next;
		}
		p->next = NULL;
		delete toDeletedNode;
		toDeletedNode = NULL;
	}
}

void testchap13(){
	int data = 0;
	listNode0 *pHead = new listNode0, *pre = pHead;
	cin >> data;
	pHead->data = data;
	pHead->next = NULL;
	while(data != -1){
		listNode0 *p = new listNode0;
		cin >> data;
		p->data = data;
		p->next = NULL;
		pre->next = p;
		pre = p;
	}

	deleteNode(pHead, pHead->next->next);

	listNode0 *q = pHead;
	while(q != NULL){
		cout << q->data << " ";
		q = q->next;
	}
	cout << endl;
	getchar();
}
