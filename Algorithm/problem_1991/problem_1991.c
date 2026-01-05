#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct TreeNode {
	char value;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

void preorder(TreeNode* node) {
	if (node == NULL)
		return;
	printf("%c", node->value);
	preorder(node->left);
	preorder(node->right);
}

void inorder(TreeNode* node) {
	if (node == NULL)
		return;
	preorder(node->left);
	printf("%c", node->value);
	preorder(node->right);
}

void postorder(TreeNode* node) {
	if (node == NULL)
		return;
	preorder(node->left);
	preorder(node->right);
	printf("%c", node->value);
}

int main() {
	int n;
	scanf("%d", &n);
	TreeNode node[26];

	for (int i = 0;i < 26;i++) {
		node[i].value = (char)('A' + i);
		node[i].left = NULL;
		node[i].right = NULL;
	}

	for (int i = 0; i < n; i++) {
		char parent, left, right;
		scanf(" %c %c %c", &parent, &left, &right);

		TreeNode* p = &node[parent - 'A'];
		p->left = (left == '.') ? NULL : &node[left - 'A'];
		p->right = (right == '.') ? NULL : &node[right - 'A'];
	}
	TreeNode* root = &node[0];

	preorder(root); putchar('\n');
	inorder(root); putchar('\n');
	postorder(root); putchar('\n');

	return 0;
}