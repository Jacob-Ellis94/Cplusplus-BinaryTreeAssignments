#pragma once
#include <iostream>
using namespace std;

// This class contains many of the generic operations found in a BST data structure. 
// This particular code took inspiration from an example found at: https://gist.github.com/harish-r/a7df7ce576dda35c9660
// The general structure shares some similarities, but of course this has been re-purposed and adapted to meet the aim of this assignment. 


class BST
{
	struct Node // Standard BST node structure. 
	{
		string word;
		int count;
		Node* Left;
		Node* Right;
	};
	Node* root;


	Node* Insert(string wordIn, int count, Node* node) // Insertion with contained recursion elements. 
	{
		if (node == nullptr)
		{
			node = new Node;
			node->word = wordIn;
			node->Left = node->Right = nullptr;
			node->count = count;
		}
		else if (wordIn < node->word)
		{
			node->Left = Insert(wordIn, count, node->Left);
		}
		else if (wordIn > node->word)
		{
			node->Right = Insert(wordIn, count, node->Right);
		}
		return node;
	}

	void inorder(Node* node) // This traverses the tree in order, and prints out the contents. 
	{
		if (node == nullptr)
			return;
		inorder(node->Left);
		cout <<"\t\t\t\t\t"<< node->word << "\t\t\t" << node->count << endl;
		inorder(node->Right);
	}
public:
	BST()
	{
		root = nullptr;
	}

	Node* clearData(Node* node) // To clean up all data in tree, if necesary. Used within the destructor. 
	{
		if (node == nullptr)
			return nullptr;
		clearData(node->Left);
		clearData(node->Right);
		delete node;
		return nullptr;
	}

	~BST()
	{
		root = clearData(root);
	}

	void Insert(string x, int count) //Insert a new node into the tree (calling on private function).
	{
		root = Insert(x, count, root);
	}


	void Results()// This provides the preceeding text before calling the private function 'inorder' which then regurgitates the data within the BST.
	{
		cout << "\t\t\t\t\t *****<< The results >> ***** " << endl << endl;
		cout << "\t\t\t\t\tWord:\t\t\tCount:" << endl << endl;
		inorder(root);
		cout << endl;
	}
};






