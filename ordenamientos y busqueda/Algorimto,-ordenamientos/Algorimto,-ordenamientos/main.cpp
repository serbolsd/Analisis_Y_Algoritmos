#include <iostream>
#include <chrono>
#include <vector>
#include <random>
 
std::vector<int> acendente(int n);
std::vector<int> descendente(int n);
std::vector<int> random(int n);
std::vector<int> ordenamientobubble(std::vector<int> vec);
std::vector<int> insertion(std::vector<int> vec);
std::vector<int> Merge(std::vector<int> left, std::vector<int> right);
std::vector<int> MergeSort(std::vector<int> vec);
int partition(std::vector<int> &vec, int min, int max);
void quickSort(std::vector<int>& vec, int min, int max);
int linearSearch(std::vector<int> vec,int value);

int binarySearch(std::vector<int> vec, int lefth, int right, int value);

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

int linearSearch(std::vector<int> vec, int value)
{

	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == value)
		{
			return i;
		}
	}
	return -1;
}

int binarySearch(std::vector<int> vec, int lefht, int right, int value)
{
	if (right >= lefht) {
		int mid = lefht + (right - lefht) / 2;

		// If the element is present at the middle 
		// itself 
		if (vec[mid] == value)
			return mid;

		// If element is smaller than mid, then 
		// it can only be present in left subarray 
		if (vec[mid] > value)
			return binarySearch(vec, lefht, mid - 1, value);

		// Else the element can only be present 
		// in right subarray 
		return binarySearch(vec, mid + 1, right, value);
	}

	// We reach here when element is not 
	// present in array 
	return -1;
}

std::vector<int> Merge(std::vector<int> left, std::vector<int> right)
{
	std::vector<int> result;
	while (left.size() > 0 || right.size() > 0)
	{
		if (left.size() > 0 && right.size() > 0)
		{
			if (left[0] <= right[0])
			{
				result.push_back(left[0]);
				left.erase(left.begin());
			}
			else
			{
				result.push_back(right[0]);
				right.erase(right.begin());
			}
		}
		else if (left.size() > 0)
		{
			for (int i = 0; i < left.size(); i++)
				result.push_back(left[i]);
			break;
		}
		else if (right.size() > 0)
		{
			for (int i = 0; i < right.size(); i++)
				result.push_back(right[i]);
			break;
		}
	}
	return result;
}

std::vector<int> MergeSort(std::vector<int> vec)
{
	if (vec.size() <= 1)
		return vec;

	std::vector<int> left, right, result;
	int middle = ((int)vec.size() + 1) / 2;

	for (int i = 0; i < middle; i++) {
		left.push_back(vec[i]);
	}

	for (int i = middle; i < (int)vec.size(); i++) {
		right.push_back(vec[i]);
	}

	left = MergeSort(left);
	right = MergeSort(right);
	result = Merge(left, right);

	return result;
}

int partition(std::vector<int> &vec, int min, int max)
{
	int pivot = vec[max];    // pivot 
	int i = (min - 1);  // Index of smaller element 

	for (int j = min; j <= max - 1; j++)
	{
		
		if (vec[j] <= pivot)
		{
			i++;   
			int swap = vec[i];
			vec[i] = vec[j];
			vec[j] = swap;
		}
	}
	int swap = vec[i + 1];
	vec[i + 1] = vec[max];
	vec[max] = swap;
	return (i + 1);
}

void quickSort(std::vector<int>& vec, int min, int max)
{
	if (min < max)
	{
		int mid = partition(vec, min, max);

		quickSort(vec, min, mid - 1);
		quickSort(vec, mid + 1, max);
	}
}