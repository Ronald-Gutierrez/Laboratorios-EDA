#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

struct Nodo
{
	int dato;
	Nodo *padre;
	Nodo *right;
	Nodo *left;
	int color;
};

typedef Nodo *Nptr;

class RBT
{
private:
	Nptr root;
	Nptr tnull;
	int op_cont;
	void inicializar(Nptr nodo, Nptr padre)
	{
		nodo->dato = 0;
		nodo->padre = padre;
		nodo->right = nullptr;
		nodo->left = nullptr;
		nodo->color = 0;
	}

	void preorder(Nptr nodo)
	{
		if (nodo != tnull)
		{
			cout << nodo->dato << " ";
			preorder(nodo->left);
			preorder(nodo->right);
		}
	}

	void clear(Nptr &nodo)
	{
		if (nodo != tnull)
		{
			clear(nodo->left);
			clear(nodo->right);
			delete nodo;
			nodo = tnull;
		}
	}

	Nptr buscar(Nptr nodo, int x)
	{
		if (nodo == tnull)
		{
			return nodo;
		}
		if (x == nodo->dato)
		{
			this->op_cont++;
			return nodo;
		}
		if (x < nodo->dato)
		{
			this->op_cont++;
			return buscar(nodo->left, x);
		}
		else if (x > nodo->dato)
		{
			this->op_cont++;
			return buscar(nodo->right, x);
		}
	}

	// Balancear despues de insertar
	// 1=rojo, 0=negro
	void balancear(Nptr k)
	{
		Nptr u;
		while (k->padre->color == 1)
		{ // mientras el padre del nuevo nodo es rojo
			if (k->padre == k->padre->padre->right)
			{
				u = k->padre->padre->left;
				if (u->color == 1)
				{
					u->color = 0;
					k->padre->color = 0;
					k->padre->padre->color = 1;
					k = k->padre->padre;
				}
				else
				{
					if (k == k->padre->left)
					{
						k = k->padre;
						rightRotate(k);
					}
					k->padre->color = 0;
					k->padre->padre->color = 1;
					leftRotate(k->padre->padre);
				}
			}
			else
			{
				u = k->padre->padre->right;

				if (u->color == 1)
				{
					u->color = 0;
					k->padre->color = 0;
					k->padre->padre->color = 1;
					k = k->padre->padre;
				}
				else
				{
					if (k == k->padre->right)
					{
						k = k->padre;
						leftRotate(k);
					}
					k->padre->color = 0;
					k->padre->padre->color = 1;
					rightRotate(k->padre->padre);
				}
			}
			if (k == root)
			{
				break;
			}
		}
		root->color = 0; // establece la raiz como negro
	}

	void print(Nptr root, string indent, bool last)
	{
		if (root != tnull)
		{
			cout << indent;
			if (last)
			{
				cout << "R----";
				indent += "   ";
			}
			else
			{
				cout << "L----";
				indent += "|  ";
			}

			string sColor = root->color ? "RED" : "BLACK";
			cout << root->dato << "(" << sColor << ")" << endl;
			print(root->left, indent, false);
			print(root->right, indent, true);
		}
	}

public:
	RBT()
	{
		tnull = new Nodo;
		tnull->color = 0;
		tnull->left = nullptr;
		tnull->right = nullptr;
		root = tnull;
		this->op_cont = 0;
	}
	int getCont()
	{
		return this->op_cont;
	}
	void preorder()
	{
		preorder(this->root);
	}
	void clear()
	{
		this->clear(this->root);
	}
	Nptr buscar(int k)
	{
		return buscar(this->root, k);
	}
	bool isEmpty()
	{
		if (this->root == tnull)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void leftRotate(Nptr a)
	{
		Nptr b = a->right;
		a->right = b->left;
		if (b->left != tnull)
		{
			b->left->padre = a;
		}
		b->padre = a->padre;
		if (a->padre == nullptr)
		{
			this->root = b;
		}
		else if (a == a->padre->left)
		{
			a->padre->left = b;
		}
		else
		{
			a->padre->right = b;
		}
		b->left = a;
		a->padre = b;
	}

	void rightRotate(Nptr a)
	{
		Nptr b = a->left;
		a->left = b->right;
		if (b->right != tnull)
		{
			b->right->padre = a;
		}
		b->padre = a->padre;
		if (a->padre == nullptr)
		{
			this->root = b;
		}
		else if (a == a->padre->right)
		{
			a->padre->right = b;
		}
		else
		{
			a->padre->left = b;
		}
		b->right = a;
		a->padre = b;
	}

	void insert(int x)
	{
		Nptr nodo = new Nodo;
		nodo->padre = nullptr;
		nodo->dato = x;
		nodo->left = tnull;
		nodo->right = tnull;
		nodo->color = 1;

		Nptr b = nullptr;
		Nptr a = this->root;

		while (a != tnull)
		{
			b = a;
			if (nodo->dato < a->dato)
			{
				a = a->left;
			}
			else
			{
				a = a->right;
			}
		}

		nodo->padre = b;
		if (b == nullptr)
		{
			root = nodo;
		}
		else if (nodo->dato < b->dato)
		{
			b->left = nodo;
		}
		else
		{
			b->right = nodo;
		}

		if (nodo->padre == nullptr)
		{
			nodo->color = 0;
			return;
		}

		if (nodo->padre->padre == nullptr)
		{
			return;
		}

		balancear(nodo);
	}

	void print2()
	{
		if (root)
		{
			print(this->root, "", true);
		}
	}
};

int main()
{
	srand(time(NULL));
	RBT A;
	vector<int> numbers;
	int max_numbers = 100000;
	
	int sum = 0;
	for (int j = 0; j < 1; j++)
	{
		for (int i = 0; i < max_numbers; i++)
		{
			int val = rand() % max_numbers;
			A.insert(val);
			numbers.push_back(val);
		}
		int randomIndex = rand() % numbers.size();
		A.buscar(numbers[randomIndex]);
		A.clear();
		numbers.clear();
	}
	int prom = sum / 5;
	cout << "Total operations with " << max_numbers << " elements: " << A.getCont()-1<< endl;
	max_numbers += 200;
	
	return 0;
}