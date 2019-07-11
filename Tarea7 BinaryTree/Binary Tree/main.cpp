
# include <iostream>
# include <cstdlib>
#include "CBinaryTree.h"
using namespace std;
/*
 * Node Declaration
 */
//struct node
//{
//	int info;
//	struct node *left;
//	struct node *right;
//}*m_root;

/*
 * Class Declaration
 */

int main()
{
	int opcion, num;
	CBinaryTree tree;
	node *temp;
	bool salir = false;
	while (!salir)
	{
		cout << endl;
		cout << "1.Insertion " << endl;
		cout << "2.Delete" << endl;
		cout << "3.Inorder" << endl;
		cout << "4.Draw" << endl;
		cout << "5.Quit" << endl;
		cout << "opcion : ";
		cin >> opcion;
		system("cls");
		if (opcion==1)
		{
			temp = new node;
			cout << "Numero a insertar : ";
			cin >> temp->info;
			tree.insert(tree.m_root, temp);
		}
		else if (opcion == 2)
		{
			if (tree.m_root == nullptr)
			{
				cout << "El arbol esta vacio, no hay nada que borrar" << endl;
				continue;
			}
			cout << "Numero a borrar : ";
			cin >> num;
			tree.Delete(num);
		}
		else if (opcion == 3)
		{
			cout << "Inorder:" << endl;
			tree.inorder(tree.m_root);
			cout << endl;
		}
		else if (opcion == 4)
		{
			cout << "Dibujo:" << endl;
			tree.draw(tree.m_root, 1);
			cout << endl;
		}
		else if (opcion == 1)
		{
			salir = true;
		}
		else
		{

			cout << "Esa no es una opcion" << endl;
		}
		
	}
	return 0;
}
