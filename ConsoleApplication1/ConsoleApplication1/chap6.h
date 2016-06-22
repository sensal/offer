#include <iostream>

using namespace std;

typedef struct treeNode{
	int value;
	struct treeNode *left;
	struct treeNode *right;
}TreeNode;

void createNode(TreeNode **root){
	*root = new TreeNode;
	cin >> (*root)->value;
	if((*root)->value == -1) *root = NULL;
	if(*root){
		createNode(&((*root)->left));
		createNode(&((*root)->right));
	}
}

void preorder(TreeNode *root){
	if(root != NULL){
		cout << root->value << " ";
		preorder(root->left);
		preorder(root->right);
	}
}

void preorder_norecursion(TreeNode *root){
	stack<TreeNode*> s;
	TreeNode *p = root;
	while(p!=NULL || !s.empty()){
		while(p != NULL){
			cout << p->value << " ";
			s.push(p);
			p = p->left;
		}
		if(!s.empty()){
			p = s.top();
			s.pop();
			p = p->right;
		}
	}
}


void midorder(TreeNode *root){
	if(root != NULL){
		midorder(root->left);
		cout << root->value << " ";
		midorder(root->right);
	}
}

void midorder_norecursion(TreeNode *root){
	TreeNode *p = root;
	stack<TreeNode*> s;
	while(p!=NULL || !s.empty()){
		while( p != NULL){
			s.push(p);
			p = p->left;
		}
		if(!s.empty()){
			p = s.top();
			s.pop();
			cout << p->value << " ";
			p = p->right;
		}
	}
}


void postorder(TreeNode *root){
	if(root != NULL){
		postorder(root->left);
		postorder(root->right);
		cout << root->value << " ";
	}
}

void postorder_norecursion(TreeNode *root){
	TreeNode *cur, *pre = NULL;
	stack<TreeNode*> s;
	if(root != NULL){
		s.push(root);
	}
	while(!s.empty()){
		cur = s.top();
		if((cur->left==NULL&&cur->right==NULL) || 
			(pre!=NULL)&&(pre==cur->left||pre==cur->right)){
			cout << cur->value << " ";
			s.pop();
			pre = cur;
		}else{
			if(cur->right != NULL)
				s.push(cur->right);
			if(cur->left != NULL)
				s.push(cur->left);
		}
	}
}

void testchap6(){
	TreeNode *root = NULL;
	createNode(&root);

	preorder(root); cout << endl;
	midorder(root);	cout << endl;
	postorder(root); cout << endl;
	cout << endl;

	preorder_norecursion(root); cout << endl;
	midorder_norecursion(root); cout << endl;
	postorder_norecursion(root); cout << endl;

	getchar();
}
