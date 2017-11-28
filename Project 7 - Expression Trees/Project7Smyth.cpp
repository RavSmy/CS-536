// CS 536, PROJECT 7, Ravela Smyth  

#include <iostream> 
#include <string>
#include <stack>
#include <fstream>

using namespace std;

struct BTNode {
	char item;
	BTNode *right;
	BTNode *left;
};

BTNode* makeArithmeticExpressionTree(string postfix);
void postOrderPrint(BTNode*root);

int main() {

	string e; 

	/*FILE INPUT*/
	ifstream file;
	file.open("file2.txt");

	while (getline(file, e)) {
		cout << e << " ---- ";
		postOrderPrint(makeArithmeticExpressionTree(e));
		cout << "\n";
	}
	file.close();

};


BTNode* makeArithmeticExpressionTree(string postfix) {
	stack<BTNode*> expr;
	BTNode* z;
	for (int i = 0; i < postfix.length(); i++) {
		if (postfix[i] != ' ') {
			z = (BTNode*)malloc(sizeof(char) + (2 * sizeof(char*)));
			z->item = postfix[i];
			z->left = NULL; z->right = NULL;
			if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/') {
				z->right = expr.top();
				expr.pop();
				z->left = expr.top();
				expr.pop();
			}
			expr.push(z);
		}
	}
	return z;
};

void postOrderPrint(BTNode*root) {
	if (root->left != NULL) postOrderPrint(root->left); 
	if (root->right != NULL)  postOrderPrint(root->right); 
	cout << root->item;
}

