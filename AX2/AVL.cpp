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
	if (r == nullptr)
	{
		return 0;
	}

	return getHeight(r->left) - getHeight(r->right);
}

int AVL::getHeight(AVL* r)
{
	if (r == nullptr)
	{
		return 0;
	}
	else {
		return r->height;
	}	
	return 0;
}

AVL* AVL::insertNode(AVL* r, int key)
{
	if (r == nullptr)
	{
		r = new AVL(key);//if theres nothing here, make something here
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
	else if(r->data > key){
		r->left = insertNode(r->left, key);
	}
	else {// is a coconut a fruit? i guess its a nut right? but how many nuts have milk in them? is it really milk or is it like just a funny coloured water? god this is so stupid
		return r; //this is the coconut
	}
	
	//update the height to the highest part of the tree. (longest?? (deepest?? (furthest??)))
	r->height = 1 + max(getHeight(r->left), getHeight(r->right));

	int balance = getBalance(r);

	// Left Left Case
	if (balance > 1 && key < r->left->data)
		return rightRotate(r);

	// Right Right Case
	if (balance < -1 && key > r->right->data)
		return leftRotate(r);

	// Left Right Case
	if (balance > 1 && key > r->left->data)
	{
		r->left = leftRotate(r->left);
		return rightRotate(r);
	}

	// Right Left Case
	if (balance < -1 && key < r->right->data)
	{
		r->right = rightRotate(r->right);
		return leftRotate(r);
	}

	// return the (unchanged) node pointer
	return r;
}

AVL* AVL::deleteNode(AVL* r, int key)
{
	//AVL* temp;

	if (r == nullptr)
	{
		return r;
	}

	if (key > r->data)//miss, target is larger than node data, move right
	{
		r->right = deleteNode(r->right, key);
	}
	else if (key < r->data) //miss, target is smaller than node data, move left
	{
		r->left = deleteNode(r->left, key);
	}
	else //HIT!! //if(r->data == key)
	{
		if (r->right == nullptr || r->left == nullptr)
		{
			AVL* temp = r->left ? r->left : r->right;

			if (temp == nullptr)
			{
				temp = r;
				r = nullptr;
			}
			else {
				*r = *temp;
				free(temp);
			}


		}
		else {

			AVL* temp = r;
			AVL* current = temp->right;

			while (current->left != NULL)
			{
				current = current->left;
			}

			temp = current;

			r->data = temp->data;

			r->right = deleteNode(r->right, temp->data);
		}
	}

	if (r == nullptr)
	{
		return r;
	}

	r->height = 1 + max(getHeight(r->left), getHeight(r->right));

	int balance = getBalance(r);

	// Left Left Case
	if (balance > 1 && getBalance(r->left) >= 0)
	{
		return rightRotate(r);
	}		

	// Right Right Case
	if (balance < -1 && getBalance(r->right) <= 0)
	{
		return leftRotate(r);
	}		

	// Left Right Case
	if (balance > 1 && getBalance(r->left) < 0)
	{
		r->left = leftRotate(r->left);
		return rightRotate(r);
	}

	// Right Left Case 
	if (balance < -1 && getBalance(r->right) > 0)
	{
		r->right = rightRotate(r->right);
		return leftRotate(r);
	}

	return r;
}

AVL* AVL::leftRotate(AVL* r)
{
	AVL* newRoot = r->right;
	AVL* subtreeToTransplant = newRoot->left;

	newRoot->left = r;
	r->right = subtreeToTransplant;

	// Update heights
	r->height = max(getHeight(r->left), getHeight(r->right) + 1);

	newRoot->height = max(getHeight(r->left), getHeight(r->right) + 1);

	// Return new root
	return newRoot;
}

AVL* AVL::rightRotate(AVL* r)
{
	AVL* newRoot = r->left;
	AVL* subtreeToTransplant = newRoot->right;

	newRoot->right = r;
	r->left = subtreeToTransplant;


	// Update heights
	r->height = max(getHeight(r->left), getHeight(r->right) + 1);

	newRoot->height = max(getHeight(r->left), getHeight(r->right) + 1);

	// Return new root
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
	AVL* tree = new AVL(3);

	for (int i = 1; i <= 10; ++i)
	{
		tree = tree->insertNode(tree, i);
	}

	tree = tree->deleteNode(tree, 4);

	tree->inOrder(tree);

	std::cout << "Root: " << tree->data;
}