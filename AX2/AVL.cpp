#include "AVL.h"
#include <iostream>

void AVL::preOrder(AVL* r)
{
	if (r == nullptr)
	{
		return;
	}

	std::cout << r->data << " ";
	preOrder(r->left);
	preOrder(r->right);
}

void AVL::inOrder(AVL* r)
{
	if (r == nullptr)
	{
		return;
	}

	inOrder(r->left);
	std::cout << r->data << " ";
	inOrder(r->right);
}

int AVL::getBalance(AVL* r)
{ 
	int leftHeight, rightHeight, shungite;
	r->right


	return 0;
}

int AVL::getHeight(AVL* r)
{
	if (r == nullptr)
	{
		return 0;
	}
	else {
		return max(getHeight(r->right), getHeight(r->left) + 1);
	}
	return 0;
}

AVL* AVL::insertNode(AVL* r, int key)
{
	if (r == nullptr)
	{
		r = new AVL(key);
		return r;
	}

	if (r->data == key)
	{
		return r; // no dupes
	}

	if (r->data < key)
	{
		r->right = insertNode(r->right, key);
	}
	else {
		r->left = insertNode(r->left, key);
	}

	return r; //this is the coconut
}

AVL* AVL::deleteNode(AVL* r, int key)
{
	return r;
}

AVL* AVL::leftRotate(AVL* r)
{
	AVL* newRoot = r->right;
	AVL* subtreeToTransplant = newRoot->left;

	newRoot->left = r;
	r->right = subtreeToTransplant;

	//update height of root (1+max...)
	//update height of NR (1+max...)

	return newRoot;
}

AVL* AVL::rightRotate(AVL* r)
{
	AVL* newRoot = r->left;
	AVL* subtreeToTransplant = newRoot->right;

	newRoot->right = r;
	r->left = subtreeToTransplant;

	//update height of root (1+max...)
	//update height of NR (1+max...)

	return newRoot;
}

int AVL::max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else {
		return b;
	}

	return 0;
}

int main()
{
	AVL* tree = new AVL(5);

	for (int i = 1; i <= 10; ++i)
	{
		tree = tree->insertNode(tree, i);
	}

	tree->inOrder(tree);
}