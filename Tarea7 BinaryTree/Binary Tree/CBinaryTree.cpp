#include "CBinaryTree.h"



CBinaryTree::CBinaryTree()
{
}


CBinaryTree::~CBinaryTree()
{
	free (m_root);
}

void CBinaryTree::find(int item, node **param, node **location)
{
	node *ptr, *ptrsave;
	if (m_root == nullptr)
	{
		*location = nullptr;
		*param = nullptr;
		return;
	}
	if (item == m_root->info)
	{
		*location = m_root;
		*param = nullptr;
		return;
	}
	if (item < m_root->info)
		ptr = m_root->left;
	else
		ptr = m_root->right;
	ptrsave = m_root;
	while (ptr != nullptr)
	{
		if (item == ptr->info)
		{
			*location = ptr;
			*param = ptrsave;
			return;
		}
		ptrsave = ptr;
		if (item < ptr->info)
			ptr = ptr->left;
		else
			ptr = ptr->right;
	}
	*location = nullptr;
	*param = ptrsave;
}

void CBinaryTree::insert(node *tree, node *newnode)
{
	if (m_root == nullptr)
	{
		m_root = new node;
		m_root->info = newnode->info;
		m_root->left = nullptr;
		m_root->right = nullptr;
		cout << "Se agregado el padre" << endl;
		return;
	}
	if (tree->info == newnode->info)
	{
		cout << "Elemento ya existente" << endl;
		return;
	}
	if (tree->info > newnode->info)
	{
		if (tree->left != nullptr)
		{
			insert(tree->left, newnode);
		}
		else
		{
			tree->left = newnode;
			(tree->left)->left = nullptr;
			(tree->left)->right = nullptr;
			cout << "Se añadio el nodo a la izquierda" << endl;
			return;
		}
	}
	else
	{
		if (tree->right != nullptr)
		{
			insert(tree->right, newnode);
		}
		else
		{
			tree->right = newnode;
			(tree->right)->left = nullptr;
			(tree->right)->right = nullptr;
			cout << "Se añadio el nodo a la derecha" << endl;
			return;
		}
	}
}

void CBinaryTree::Delete(int item)
{
	node *parent, *location;
	if (m_root == nullptr)
	{
		cout << "Tree vacio" << endl;
		return;
	}
	find(item, &parent, &location);
	if (location == nullptr)
	{
		cout << "No existe ese elemento" << endl;
		return;
	}
	if (location->left == nullptr && location->right == nullptr)
		case1(parent, location);
	if (location->left != nullptr && location->right == nullptr)
		case2(parent, location);
	if (location->left == nullptr && location->right != nullptr)
		case2(parent, location);
	if (location->left != nullptr && location->right != nullptr)
		case3(parent, location);
	free(location);
	cout << "El elemeneto : " <<item<<" se a borrado con exito"<< endl;
}

void CBinaryTree::case1(node *parent, node *location)
{
	if (parent == nullptr)
	{
		m_root = nullptr;
	}
	else
	{
		if (location == parent->left)
			parent->left = nullptr;
		else
			parent->right = nullptr;
	}
}

void CBinaryTree::case2(node *parent, node *location)
{

	node *child;
	if (location->left != nullptr)
		child = location->left;
	else
		child = location->right;
	if (location == nullptr)
	{
		m_root = child;
	}
	else
	{
		if (location == parent->left)
			parent->left = child;
		else
			parent->right = child;
	}
}

void CBinaryTree::case3(node *parent, node *location)
{
	node *ptr, *ptrsave, *suc, *parsuc;
	ptrsave = location;
	ptr = location->right;
	while (ptr->left != nullptr)
	{
		ptrsave = ptr;
		ptr = ptr->left;
	}
	suc = ptr;
	parsuc = ptrsave;
	if (suc->left == nullptr && suc->right == nullptr)
		case1(parsuc, suc);
	else
		case2(parsuc, suc);
	if (parent == nullptr)
	{
		m_root = suc;
	}
	else
	{
		if (location == parent->left)
			parent->left = suc;
		else
			parent->right = suc;
	}
	suc->left = location->left;
	suc->right = location->right;
}

void CBinaryTree::preorder(node *)
{
}



void CBinaryTree::inorder(node *ptr)
{
	if (m_root == NULL)
	{
		cout << "Tree vacio" << endl;
		return;
	}
	if (ptr != NULL)
	{
		inorder(ptr->left);
		cout << ptr->info << "  ";
		inorder(ptr->right);
	}
}

void CBinaryTree::postorder(node *)
{
}

void CBinaryTree::draw(node * ptr, int level)
{
	int i;
	if (ptr != nullptr)
	{
		draw(ptr->right, level + 1);
		cout << endl;
		if (ptr == m_root)
			cout << "m_root->:  ";
		else
		{
			for (i = 0; i < level; i++)
				cout << "       ";
		}
		cout << ptr->info;
		draw(ptr->left, level + 1);
	}
}
