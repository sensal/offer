#include <iostream>
#include <stack>
using namespace std;

typedef struct node{
	int value;
	struct node *next;
}listNode;

void createList(listNode **pHead){
	if(*pHead == NULL){
		listNode *p = new listNode;
		p->value = 0;
		p->next = NULL;
		*pHead = p;
	}

	listNode *p1 = *pHead;
	for(int i=1; i<10; i++){
		listNode *p = new listNode;
		p->value = i;
		p->next = NULL;
		p1->next = p;
		p1 = p;
	}
}

void printListReversingly(listNode *pHead){
	stack<listNode*> stackList;
	listNode *p = pHead;
	while(p != NULL){
		stackList.push(p);
		p = p->next;
	}
	
	while(!stackList.empty()){
		cout << stackList.top()->value << " ";
		stackList.pop();
	}
	cout << endl;
}

void testchap5(){
	listNode *pHead = NULL;
	createList(&pHead);
	printListReversingly(pHead);
}