#include <iostream>
using namespace std;
typedef int Info;
struct Node
{
	Node* left,
		* right;
	Info info;
	char ch;
};

Node* CreateTree(int nodeCount);
void PrintTree(Node* root, int level);
Info PostfixOrder(Node* root,Info& min)
{
	if (root != NULL)
	{
		PostfixOrder(root->left,min);
		PostfixOrder(root->right,min);
		if (root->info < min)
			min = root->info;
	}
	return min;
}

int main()
{
	int N,min=9999999999;
	cout << "Enter nodes count: "; cin >> N;
	Node* root = CreateTree(N);
	cout << endl;
	PrintTree(root, 0);
	cout << "Postfix search: ";
	cout<<endl<<PostfixOrder(root,min); cout << endl;
	return 0;
}
Node* CreateTree(int nodeCount)
{
	if (nodeCount == 0)
		return NULL;
	else
	{
		Node* newNode = new Node;

		cout << " Enter node value: ";
		cin >> newNode->info;
		cout << " Enter node symbol: ";
		cin >> newNode->ch;

		int leftCount = nodeCount / 2;
		int rightCount = nodeCount - leftCount - 1;
		newNode->left = CreateTree(leftCount);
		newNode->right = CreateTree(rightCount);
		return newNode;
	}
}
void PrintTree(Node* root, int level)
{
	if (root != NULL)
	{
		PrintTree(root->right, level + 1);
		for (int i = 1; i <= level; i++)
			cout << " ";
		cout << root->info;
		cout << root->ch << endl;
		PrintTree(root->left, level + 1);
	}
}
Node* FindMin(Node* root)
{
	if (root->left != NULL)
		return FindMin(root->left);
	else
		return root;
}