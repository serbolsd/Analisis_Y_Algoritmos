#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include <cmath>
#include <algorithm>

using namespace std;
std::vector<int> acendente(int n);
std::vector <std::vector <int>> hashTable;
std::vector <std::vector <int>> hashTable2;
std::vector <std::vector <int>> hashTable3;
int hashMul(int key, int consta);
int hashDiv(int key, int consta);
int hashUn(int key, int value, int consta,int numKeys);
void imprimirVector(std::vector<int> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << ',';
	}
	std::cout << '\n';

}
int main()
{

	std::vector<int> vec;
	vec = acendente(100);
	int bucketNum=7;
	hashTable.resize(bucketNum);
	hashTable2.resize(bucketNum);
	hashTable3.resize(bucketNum);
	for (int i = 0; i < vec.size(); i++)
	{
		hashMul(vec[i],bucketNum);
		hashDiv(vec[i], bucketNum);
		hashUn(i,vec[i],bucketNum, vec.size());

	}
	for (int i = 0; i < hashTable3.size(); i++)
	{
		imprimirVector(hashTable3[i]);

	}
	return 0;
}

std::vector<int> acendente(int n)
{

	std::cout << "el vector acendente generado es el siguiente\n";
	std::vector<int> vec;
	for (int i = 0; i < n; i++)
	{
		vec.push_back(i + 1);
		std::cout << i + 1 << ',';
	}
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	return vec;
}

int hashMul(int key, int consta)
{
	int cons = consta;
	key = (key ^ cons) ^ (key >> cons);
	key = key * cons;
	int numtab = key % consta;
	hashTable[numtab].push_back(key);
	return key;
}
int hashDiv(int key, int consta)
{
	int cons = consta;
	key = (key ^ cons) ^ (key >> cons);
	key = key / cons;
	int numtab = key % consta;
	hashTable2[numtab].push_back(key);
	return key;
}
int hashUn(int key,int value, int consta, int numkeys)
{
	float constante = consta;
	float a = (1 / constante);
	int genKey = a * key;
	int newKey = genKey % consta;
	if (newKey> consta-1)
	{
		cout << "checaño: " << newKey << "\n";
		return 0;
	}
	hashTable3[newKey].push_back(value);
	return 0;
}