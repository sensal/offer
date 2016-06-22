#include <iostream>
using namespace std;

typedef struct BinaryTreeNode18{
	int m_nValue;
	struct BinaryTreeNode18 *m_pLeft;
	struct BinaryTreeNode18 *m_pRight;
}BinaryTreeNode18;

bool check(BinaryTreeNode18 *root, BinaryTreeNode18 *child){
	if(root==NULL && child==NULL) return true;
	if(root==NULL || child==NULL) return false;
	if(root->m_nValue == child->m_nValue){
		bool left = check(root->m_pLeft, child->m_pLeft);
		if(left) return true;
		bool right = check(root->m_pRight, child->m_pRight);
		if(right) return true;
	}
	return false;
}

bool findChild(BinaryTreeNode18 *root, BinaryTreeNode18 *child){
	if(root==NULL && child==NULL) return true;
	if(root==NULL || child==NULL) return false;
	if(root->m_nValue == child->m_nValue){
		return check(root, child);
	}
	bool left = findChild(root->m_pLeft, child);
	if(left) return true;
	bool right = findChild(root->m_pRight, child);
	if(right) return true;
}

void createNode(BinaryTreeNode18 **root){
	*root = new BinaryTreeNode18;
	cin >> (*root)->m_nValue;
	if((*root)->m_nValue == -1) *root = NULL;
	if(*root){
		createNode(&((*root)->m_pLeft));
		createNode(&((*root)->m_pRight));
	}
}
void testchap18(){
	BinaryTreeNode18 *root = NULL, *child = NULL;
	createNode(&root);
	createNode(&child);
	cout << findChild(root, child) << endl;
	getchar();
}
