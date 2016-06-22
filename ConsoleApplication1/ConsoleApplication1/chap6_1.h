#include <iostream>
using namespace std;

typedef struct BinaryTreeNode{
	int data;
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;
}BinaryTree;

BinaryTree *constructCore(int *startPreorder, int *endPreorder,
						  int *startInorder, int *endInorder){
	int rootValue = *startPreorder;
	BinaryTree *root = new BinaryTree;
	root->data = rootValue;

	int index = 0;
	while((*(startInorder+index)!=*startPreorder) && index<=endPreorder-startPreorder){
		index++;
	}
	if(*(startInorder+index)!=*startPreorder)
		throw exception("Invild input");

	if(index == 0)
		root->left = NULL;
	else
		root->left = constructCore(startPreorder+1, startPreorder+index, startInorder, startInorder+index-1);

	if(index == endInorder-startInorder)
		root->right = NULL;
	else
		root->right = constructCore(startPreorder+index+1, endPreorder, startInorder+index+1, endInorder);

	return root;
}

BinaryTree *construct(int *preorder, int *inorder, int length){
	if(preorder==NULL || inorder==NULL || length==0){
		return NULL;
	}
	try{
		return constructCore(preorder, preorder+length-1, inorder, inorder+length-1);
	}
	catch(exception){
		cout << "invild input" << endl;
		getchar();
		exit(1);
	}

}

void postorder(BinaryTree *root){
	if(root != NULL){
		postorder(root->left);
		postorder(root->right);
		cout << root->data << " ";
	}
}

void testchap6_1(){
	int preorder[] = {1,2,4,7,3,5,6,8};
	int inorder[] = {4,7,2,1,5,3,8,6};
	
	BinaryTree *root = construct(preorder, inorder, sizeof(preorder)/sizeof(int));
	
	postorder(root); cout << endl;
}
