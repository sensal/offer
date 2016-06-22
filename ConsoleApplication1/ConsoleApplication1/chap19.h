#include <iostream>
using namespace std;

typedef struct BinaryTreeNode19{
	int m_nValue;
	struct BinaryTreeNode19 *m_pLeft;
	struct BinaryTreeNode19 *m_pRight;
}BinaryTreeNode19;

void createNode(BinaryTreeNode19 **root){
	*root = new BinaryTreeNode19;
	cin >> (*root)->m_nValue;
	if((*root)->m_nValue == -1) *root = NULL;
	if(*root){
		createNode(&((*root)->m_pLeft));
		createNode(&((*root)->m_pRight));
	}
}

void createMirror(BinaryTreeNode19 *root, BinaryTreeNode19 **mirror){
	if(root==NULL) return;

	(*mirror) = new BinaryTreeNode19;
	(*mirror)->m_nValue = root->m_nValue;

	(*mirror)->m_pLeft = root->m_pRight;
	createMirror(root->m_pRight, &(*mirror)->m_pLeft);
	(*mirror)->m_pRight = root->m_pLeft;
	createMirror(root->m_pLeft, &(*mirror)->m_pRight);
}

void createMirror_norecursion(BinaryTreeNode19 *root){
	stack<BinaryTreeNode19*> s;
	while(!s.empty() || root!=NULL){
		while(root!=NULL){
			BinaryTreeNode19 *temp = root->m_pLeft;
			root->m_pLeft = root->m_pRight;
			root->m_pRight = temp;

			s.push(root);
			root = root->m_pLeft;
		}
		if(!s.empty()){
			root = s.top();
			s.pop();
			root = root->m_pRight;
		}
	}
}

void print(BinaryTreeNode19 *root){
	if(root!=NULL){
		cout << root->m_nValue << " ";
		print(root->m_pLeft);
		print(root->m_pRight	);
	}

}


void testchap19(){
	BinaryTreeNode19 *root, *mirror=NULL;
	createNode(&root);
	//createMirror(root, &mirror);
	createMirror_norecursion(root);

	print(root);

	stack<BinaryTreeNode19*> s;
	while(!s.empty() || mirror!=NULL){
		while(mirror!=NULL){
			cout << mirror->m_nValue << " ";
			s.push(mirror);
			mirror = mirror->m_pLeft;
		}
		if(!s.empty()){
			mirror = s.top();
			s.pop();
			mirror = mirror->m_pRight;
		}
	}

	getchar();
}
