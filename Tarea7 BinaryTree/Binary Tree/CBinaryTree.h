#pragma once
#include <iostream>
using namespace std;
struct node
{
	int info;
	struct node *left= nullptr;
	struct node *right= nullptr;
};
class CBinaryTree
{
public:
	CBinaryTree();
	~CBinaryTree();
	void find(int item, node **parent, node **location);
	void insert(node *tree, node *newnode);
	void Delete(int item);
	void case1(node *parent, node *location);
	void case2(node *parent, node *location);
	void case3(node *parent, node *location);
	void preorder(node *);
	void inorder(node *ptr);
	void postorder(node *);
	void draw(node *ptr, int level);
	node *m_root=nullptr;
};

