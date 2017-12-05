// Ravela Smyth, CS536, LabTest2

#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* left = nullptr;
	Node* right = nullptr;
};

bool equal(Node* r1, Node* r2); 
int find_max(Node* r);

int main()
{
	//TREE 1
	Node tree11, tree12, tree13, tree14, tree15, tree16, tree17;
	tree11.data = 1; tree12.data = 2; tree13.data = 3; tree14.data = 4; tree15.data = 5; tree16.data = 6; tree17.data = 7;
	tree11.left = &tree12; tree11.right = &tree13;
	tree12.left = &tree14; tree12.right = &tree17;
	tree13.left = &tree16; tree13.right = &tree15;



	// TREE 2
	Node tree21, tree29, tree23, tree25, tree26, tree255;
	tree21.data = 1; tree29.data = 9; tree23.data = 3; tree26.data = 6; tree25.data = 5; tree255.data = 5;
	tree21.left = &tree29; tree21.right = &tree23;
	tree29.right = &tree25;
	tree23.left = &tree26; tree23.right = &tree255;


	//TEST
	cout << "equal(nullptr, nullptr): " << equal(nullptr, nullptr);
	cout << "\nequal(nullptr, root1): " << equal(nullptr, &tree11);
	cout << "\nequal(root1, root1): " << equal(&tree11, &tree11);
	cout << "\nequal(root1, root2): " << equal(&tree11, &tree21);
	cout << "\nequal(root1, root2->left): " << equal(&tree11, tree21.left);
	cout << "\nequal(root1->right, root2->right): " << equal(tree11.right, tree21.right);
	cout << "\nfindmax(nullptr): " << find_max(nullptr);
	cout << "\nfindmax(&tree11): " << find_max(&tree11);
	cout << "\nfindmax(&tree21): " << find_max(&tree21) << "\n";
}

bool equal(Node* r1, Node* r2) {
	if (r1 == NULL && r2 == NULL) return true;
	if (r1 != NULL && r2 != NULL) return ( r1->data == r2->data && equal(r1->left, r2->left) && equal(r1->right, r2->right) );
	return false; 
}

int find_max(Node* r) {

	if (r == nullptr) return -1;

	int data = r->data; int ldata = find_max(r->left); int rdata = find_max(r->right);

	if (ldata> data) data = ldata;
	if (rdata > data) data = rdata;
	return data;

}
