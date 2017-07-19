#pragma once
#include "Exception.h"

template<class T, class U>
class BinaryTree
{


private:
	class TreeNode
	{
	public:


		T key;
		U value;

		TreeNode *left;
		TreeNode *right;
		TreeNode()
		{
			left = nullptr;
			right = nullptr;
		};

		TreeNode(T newkey, U newValue)
		{
			key = newkey;
			value = newValue;
			left = nullptr;
			right = nullptr;
		};
		~TreeNode() { value = 0; key = 0; };

	};

	//Private Functions 
	int leafNum = 0;
	TreeNode * Root;

	/*
	inserts an object with a number unique to that object into a binary tree 
	@param keynum the number unique to the object
	@param valuenum the object 
	@param leaf treeNode 
	no returns
	*/
	void InsertTree(T keyNum, U valueNum, TreeNode *leaf)
	{
		if (keyNum < leaf->key)
		{
			if (leaf->left != nullptr)

			{
				InsertTree(keyNum, valueNum, leaf->left);
			}
			else
			{
				leaf->left = new TreeNode(keyNum, valueNum);
				leaf->left->key = keyNum;
				leaf->left->value = valueNum;
				leaf->left->left = nullptr;
				leaf->left->right = nullptr;
				leafNum++;
			}
		}

		else if (keyNum >= leaf->key)
		{
			if (leaf->right != nullptr)
			{
				InsertTree(keyNum, valueNum, leaf->right);
			}
			else
			{
				leaf->right = new TreeNode(keyNum, valueNum);
				leaf->right->key = keyNum;
				leaf->right->value = valueNum;
				leaf->right->left = nullptr;
				leaf->right->right = nullptr;
				leafNum++;
			}
		}



	}

	/*
	inserts an object with a number unique to that object into a binary tree
	@param keynum the number unique to the object
	@param leaf treeNode
	returns the object attached to keyNum
	*/
	U SearchTree(T keyNum, TreeNode *leaf)
	{
		if (leaf != nullptr)
		{
			if (keyNum == leaf->key)
			{
				return leaf->value;
			}
			else if (keyNum < leaf->key)
			{
				return SearchTree(keyNum, leaf->left);
			}
			else if (keyNum < 0 || keyNum > leafNum)
			{
				exceptTHROW("Key doesn't exist");
			}
			else  
			{
				return SearchTree(keyNum, leaf->right);

			}

			
		}

		return NULL;

	}

	/*
	Deletes tree
	@param leaf treeNode
	no returns
	*/
	void DestroyTree(TreeNode *leaf)
	{
		if (getLeafNum() < 0 )
		{
			exceptTHROW("Destroying tree that doesn't exist");
		}
		if (leaf != nullptr)
		{
			DestroyTree(leaf->left);
			DestroyTree(leaf->right);
			delete leaf;
			Root = nullptr;
			leafNum--;
		}
	}


public:

	/*
	gets how many elements in the tree
	returns the number of elements in the tree
	*/
	int	getLeafNum()
	{
		return leafNum;
	}

	BinaryTree()
	{
		Root = nullptr;
	}

	/*
	public function for inserting into the tree
	@param keyNum the number unique to the object 
	@param valueNum object being inserted into the tree
	no returns
	*/
	void insert(T KeyNum, U valueNum)

	{
	
		if (Root != nullptr)
		{
			InsertTree(KeyNum, valueNum, Root);
		}
		else
		{
			Root = new TreeNode(KeyNum, valueNum);
			Root->value = valueNum;
			Root->key = KeyNum;
			Root->left = nullptr;
			Root->right = nullptr;
			leafNum++;

			if (KeyNum < 0)
			{
				exceptTHROW("Trying to insert out of trees boundries");
			}
		}

		
	};

	/*
	public function for searching the tree
	@param keyNum the number unique to the object
	returns object with the keynum attached to it
	*/
	U Search(T keyNum)
	{
		if (keyNum < 0 || keyNum > leafNum)
		{
			exceptTHROW("Trying to search out of trees boundries");
		}
		return SearchTree(keyNum, Root);
	}

	void deleteTree()
	{

		DestroyTree(Root);
	}

	/*
	[] operator overload for searching a key in the tree
	@param keyNum the number unique to the object
	returns object with the keynum attached to it
	*/
	U operator [] (T newKey)
	{
		if (newKey < 0 || newKey > leafNum)
		{
			exceptTHROW("Trying to search out of trees boundries");
		}
		return SearchTree(newKey, Root);
	}

};

