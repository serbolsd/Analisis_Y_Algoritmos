#include <chrono>
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;
void lcs(string X, string Y, int m, int n);
void metodoBruto();
vector<string> obtenerSubsecuencias(string secuencia,int  numero);
string compararSubsecuencias(vector<string> subsecuencias1, vector<string> subsecuencias2);
void readArchive(string& X,string& Y,int &m,int &n);
struct DYNAMIC
{
	string str;
	int integer;
};

int main()
{
	string secuencia1 = "TTCGCATCGGGTTG";// #Primera secuencia
	string secuencia2 = "TGACCGTGTGTCACG"; //#Segunda secuencia
	vector<string> subsecuencias1 = obtenerSubsecuencias(secuencia1, 1); //#Obtiene todas las subsecuencias de la secuencia 1
	vector<string> subsecuencias2 = obtenerSubsecuencias(secuencia2, 2); //#Obtiene todas las subsecuencias de la secuencia 2
		
	string lcssw = compararSubsecuencias(subsecuencias1, subsecuencias2);// #Comparara una por una todas las subsecuencias de la secuencia 1 y 2
	cout<<("---BRUTE FORCE---")<<endl;
	cout<<"La subsecuencia mas larga comun de " << secuencia1 << " y de " << secuencia2 << " es " << lcssw.c_str();

	//printf("\nTerminado en " + str(time.time() - start) + " segundos!\n\n")

	return 0;
	int m, n;
	string X, Y;
	readArchive(X,Y,m,n);
	//X = "TTCGCATCGGGTTG"; //#Primera secuencia;
	//Y = "TGACCGTGTGTCACG"; //#Segunda secuencia
	//m = X.size();
	//n = Y.size();
	auto start = std::chrono::system_clock::now();
	lcs(X, Y, m, n);
	auto end = std::chrono::system_clock::now();

	std::chrono::duration<float, std::milli> duration = end - start;

	std::cout << duration.count() << "mls" << endl;
	
	return 0;
}

void lcs(string X, string Y, int m, int n)
{
	DYNAMIC **L;
	L = new DYNAMIC*[m + 1];
	for (size_t i = 0; i < m + 1; i++)
	{
		L[i] = new DYNAMIC[n + 1];
	}

	//# Construye L[m + 1][n + 1]
	//# Este L[i][j] contiene el tamaño de la LCS de X[0..i - 1] y Y[0..j - 1]
	for (size_t i = 0; i < m + 1; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			if (i == 0 || j == 0)
			{
				L[i][j].integer = 0;
			}
			else if (X[i - 1] == Y[j - 1])
			{
				L[i][j].integer = L[i - 1][j - 1].integer + 1;
			}
			else
			{
				L[i][j].integer = max(L[i - 1][j].integer, L[i][j - 1].integer);
			}

		}
	}
	int index = L[m][n].integer;
	char *lcss = new char[index + 1];
	for (size_t i = 0; i < index + 1; i++)
	{
		lcss[i] = '\0';
	}
	lcss[index] = '\0';


	//# Empezando desde la derecha hasta abajo llendo hacia la esquina uno por uno
	//# de los caracteres guardados en lcs
	int i = m;
	int j = n;
	while (i > 0 && j > 0)
	{
		//# Si el caracter en x y en y es el mismo, quiere decir que está en la LCS
		if (X[i - 1] == Y[j - 1])
		{
			lcss[index - 1] = X[i - 1];
			i -= 1;
			j -= 1;
			index -= 1;

		}
		else if (L[i - 1][j].integer > L[i][j - 1].integer)
		{
			
			//# Si no es el mismo, entonces encuentra el mas largo de dos
			//# y va en la direccion del valor mas grande
			i -= 1;
		}
		else
		{ 
			j -= 1;
		}
	}
				
	cout<<"La subsecuencia mas larga comun de " << X << " y de " << Y << " es " << " "<< lcss;
	for (size_t i = 0; i < m + 1; i++)
	{
		//delete L[i] ;
	}
	delete L;
	delete lcss;
}

vector<string> obtenerSubsecuencias(string secuencia, int numero)
{
	//# El numero de subsecuencias es(2 * *n - 1)
	int n = secuencia.size();
	int	numerodesubsecuencias = 2^n;
	//#Creamos un arreglo de arreglos de caracteres para guardar todas las subsecuencias
	vector<string> subsecuencias;
	string subsecuencia;
	for (int i = 0; i < numerodesubsecuencias; i++)
	{
		//#Arreglo para guardar una por una la secuencia
		for (int j = 0; j < n; j++)
		{
			if (i && (1 << j))
			{
				//#Inserta caracter por caracter en la subsecuencia a insertar
				subsecuencia+=secuencia[j];
			}
		}
		//#Inserta la subsecuencia hecha a toda la lista de las subsecuencias
		subsecuencias.push_back(subsecuencia);
	}
				
	//#Devuelve todas las subsecuencias posibles
	return subsecuencias;
}

string compararSubsecuencias(vector<string> subsecuencias1, vector<string> subsecuencias2)
{
	string lcs="";
	for (size_t i = 0; i < subsecuencias1.size(); i++)
	{
		for (size_t j = 0; j < subsecuencias2.size(); j++)
		{
			if (subsecuencias1[i] == subsecuencias2[j])
			{
				if (lcs.size() < subsecuencias1[i].size())
				{
					lcs += subsecuencias1[i];
				}
			}
		}
	}
	return	lcs;
}

void readArchive(string& X, string& Y, int &m, int &n)
{
	char cadena[128];
	ifstream fe("cadena1.txt");

	while (!fe.eof()) {
		fe >> cadena;
		X += cadena;
		//cout << cadena << endl;
	}
	fe.close();

	ifstream fe2("cadena2.txt");

	while (!fe2.eof()) {
		fe2 >> cadena;
		Y += cadena;
		//cout << cadena << endl;
	}
	fe2.close();
	m = X.size();
	n = Y.size();
}
