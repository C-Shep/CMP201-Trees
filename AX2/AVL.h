// CMP201.2022/23 Assessed Exercise 2 header file
// Date:   November 2022
// Author: William Kavanagh

#pragma once
class AVL
{
public:
	int data;
	AVL* left;
	AVL* right;
	int height;
	
	AVL(int n)
	{
		data = n;
		left = nullptr;
		right = nullptr;
		height = 1;
	}

	void preOrder(AVL* r);
	void inOrder(AVL* r);
	int getBalance(AVL* r);
	int getHeight(AVL* r);
	AVL* insertNode(AVL* r, int key);
	AVL* deleteNode(AVL* r, int key);
	AVL* leftRotate(AVL* r);
	AVL* rightRotate(AVL* r);
	int max(int a, int b);
	int main();
};

