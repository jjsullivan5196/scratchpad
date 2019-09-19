#include <stdlib.h>
#include <stdio.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};

typedef struct node Node;

Node* createNode(int dat) {
	Node* n = calloc(1, sizeof(Node));
	n->data = dat;
	return n;
}

void inorder(Node* n) {
	if(n) {
		if(n->left) {
			inorder(n->left);
		}
		
		printf("%d ", n->data);

		if(n->right) {
			inorder(n->right);
		}
	}
}

Node* createTree() {
	Node* root = createNode(10);
	
	root->right = createNode(30);
	root->left = createNode(20);

	Node* ltree = root->left;
	ltree->right = createNode(40);
	ltree = ltree->right;

	ltree->left = createNode(60);
	ltree->right = createNode(70);

	Node* rtree = root->right;
	rtree->right = createNode(50);

	return root;
}

int main() {
	inorder(createTree());
}
