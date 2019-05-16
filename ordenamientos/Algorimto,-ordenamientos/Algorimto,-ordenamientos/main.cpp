#include <iostream>
#include <chrono>
#include <vector>
#include <random>
 
std::vector<int> acendente(int n);
std::vector<int> descendente(int n);
std::vector<int> random(int n);
std::vector<int> ordenamientobubble(std::vector<int> vec);
std::vector<int> insertion(std::vector<int> vec);

void imprimirVector(std::vector<int> vec);

int main()
{
	while (1)
	{

//		auto start = std::chrono::steady_clock::now();
//		auto end = std::chrono::steady_clock::now();
		std::vector<int> vec;
		int n;
		std::cout<<"ingrese la cantidad de numeros 'n' que tendra el vector\n";
		std::cin >> n;
		std::cout << "\n";
		vec	= acendente(n);

		auto start = std::chrono::steady_clock::now();
		vec = ordenamientobubble(vec);
		auto end = std::chrono::steady_clock::now();
		std::cout << "El ordenamiento bubble es:\n";
		imprimirVector(vec);
		std::cout << "\nEl ordenamiento buuble ha terminado en\n" << std::chrono::duration_cast<std::chrono::nanoseconds > (end - start).count() << " nano ssegundos!\n";
		std::cout << std::chrono::duration_cast<std::chrono::microseconds> (end - start).count() << " micro segundos!\n";
		std::cout << std::chrono::duration_cast<std::chrono::milliseconds> (end - start).count() << " milisegundos!\n";
		std::cout << std::chrono::duration_cast<std::chrono::seconds> (end - start).count() << " segudos!\n";
		
		std::cout << "\n";
		vec = descendente(n);
		start = std::chrono::steady_clock::now();
		vec = ordenamientobubble(vec);
		end = std::chrono::steady_clock::now();
		std::cout << "El ordenamiento bubble es:\n";
		imprimirVector(vec);
		std::cout << "\nEl ordenamiento buuble ha terminado en\n" << std::chrono::duration_cast<std::chrono::nanoseconds > (end - start).count() << " nano ssegundos!\n";
		std::cout << std::chrono::duration_cast<std::chrono::microseconds> (end - start).count() << " micro segundos!\n";
		std::cout << std::chrono::duration_cast<std::chrono::milliseconds> (end - start).count() << " milisegundos!\n";
		std::cout << std::chrono::duration_cast<std::chrono::seconds> (end - start).count() << " segudos!\n";
		
		/*std::cout << "\n";
		vec = random(n);
		start = std::chrono::steady_clock::now();
		vec = ordenamientobubble(vec);
		end = std::chrono::steady_clock::now();
		std::cout << "El ordenamiento bubble es:\n";
		imprimirVector(vec);
		std::cout << "\nEl ordenamiento buuble ha terminado en\n" << std::chrono::duration_cast<std::chrono::nanoseconds > (end - start).count() << " nano ssegundos!\n";
		std::cout << std::chrono::duration_cast<std::chrono::microseconds> (end - start).count() << " micro segundos!\n";
		std::cout << std::chrono::duration_cast<std::chrono::milliseconds> (end - start).count() << " milisegundos!\n";
		std::cout << std::chrono::duration_cast<std::chrono::seconds> (end - start).count() << " segudos!\n";*/

		vec = acendente(n);
		start = std::chrono::steady_clock::now();
		vec = insertion(vec);
		end = std::chrono::steady_clock::now();
		std::cout << "El ordenamiento insertion es:\n";
		imprimirVector(vec);
		std::cout << "\nEl ordenamiento Insertion ha terminado en\n" << std::chrono::duration_cast<std::chrono::nanoseconds > (end - start).count() << " nano ssegundos!\n";
		std::cout << std::chrono::duration_cast<std::chrono::microseconds> (end - start).count() << " micro segundos!\n";
		std::cout << std::chrono::duration_cast<std::chrono::milliseconds> (end - start).count() << " milisegundos!\n";
		std::cout << std::chrono::duration_cast<std::chrono::seconds> (end - start).count() << " segudos!\n";


		vec = descendente(n);
		start = std::chrono::steady_clock::now();
		vec = insertion(vec);
		end = std::chrono::steady_clock::now();
		std::cout << "El ordenamiento insertion es:\n";
		imprimirVector(vec);
		std::cout << "\nEl ordenamiento Insertion ha terminado en\n" << std::chrono::duration_cast<std::chrono::nanoseconds > (end - start).count() << " nano ssegundos!\n";
		std::cout << std::chrono::duration_cast<std::chrono::microseconds> (end - start).count() << " micro segundos!\n";
		std::cout << std::chrono::duration_cast<std::chrono::milliseconds> (end - start).count() << " milisegundos!\n";
		std::cout << std::chrono::duration_cast<std::chrono::seconds> (end - start).count() << " segudos!\n";
	}


	std::cin.ignore();
	std::cin.get();
	return 0;
}

std::vector<int> acendente(int n)
{
	std::cout << "el vector acendente generado es el siguiente\n";
	std::vector<int> vec;
	for (int i = 0; i < n; i++)
	{
		vec.push_back(i + 1);
		std::cout << i + 1<<',';
	}
	std::cout <<"\n";
	return vec;
}
std::vector<int> descendente(int n)
{
	std::cout << "el vector descendente generado es el siguiente\n";
	std::vector<int> vec;
	for (int i = n; i > 0; i--)
	{
		vec.push_back(i);
		std::cout << i<<',';
	}
	std::cout << "\n";
	return vec;
}
std::vector<int> random(int n)
{
	std::cout << "el vector random generado es el siguiente\n";
	std::vector<int> vec;
	for (int i = 0; i < n; i++)
	{
		vec.push_back( (std::rand() % n)+1);
		std::cout << vec[i]<<',';
	}
	std::cout << "\n";
	return vec;
}
std::vector<int> ordenamientobubble(std::vector<int> vec)
{
	for (int i = 1; i < vec.size(); i++)
	{
		for (int j= 0; j < vec.size()-i; j++)
		{	
			if (vec[j]>vec[j+1])
			{
				int num = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = num;
			}
		}
	}
	return vec;
}
void imprimirVector(std::vector<int> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << ',';
	}
		std::cout<< '\n';

}
std::vector<int> insertion(std::vector<int> vec)
{
	int j;
	int actual;
	int size = 1;
	for (int i = 0; i < vec.size(); i++) {
		actual = vec[i];
		for (j = i; j > 0 && vec[j - 1] > actual; j--) {
			vec[j] = vec[j - 1];
		}
		vec[j] = actual;
		size++;
	}
	return vec;
}