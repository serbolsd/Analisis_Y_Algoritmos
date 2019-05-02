#include <iostream>
#include <chrono>
#include <Windows.h>
#include <string>
#include <sstream>

int fibonacciRecursiva(int n)
{
	if (n < 1)
		return n+1;
	else
		return fibonacciRecursiva(n - 1) + fibonacciRecursiva(n - 2);
		
}
int fibonacciNoRecursiva(int n)
{
	if (n < 1)
		return n+1;
	else 
	{
		int num1 = 0;
		int num2 = 1;
		//n -= 1;
		int sum=0;
		for (int i = 0; i < n; i++)
		{
			sum = num1 + num2;
			num1 = num2;
			num2 = sum;
		}
		return sum;
	}
}

int main()
{
	int num = 1;
	int numresult;
	std::cout << "Introduce un numero MENOR A 1 para SALIR\n\n";
	while (num<0)
	{
		std::cout << "Introduce el número en la secuencia de Fibonacci que quieres calcular: ";
		std::cin >> num;
		if (num <= 0)
			break;
		//le resto dos para que se empieze del numero en la posicion 1 y no en la cero y para que el 1 si este dos veces: 0,1,1,2
		num = num - 2;
		std::cout << ("El numero en la secuencia de Fibonacci es: " + num);
		
		auto start= std::chrono::steady_clock::now();
		numresult = fibonacciNoRecursiva(num);
		auto end= std::chrono::steady_clock::now();

		std::cout << "\nEl valor correspondiente con algoritmo de Fibonnaci NO Recursivo es: " << numresult<< "\nTerminado en\n" << std::chrono::duration_cast<std::chrono::nanoseconds > (end - start).count() << " nano ssegundos!\n";
		std::cout << std::chrono::duration_cast<std::chrono::microseconds> (end - start).count() << " micro segundos!\n";
		std::cout << std::chrono::duration_cast<std::chrono::milliseconds> (end - start).count() << " milisegundos!\n";
		std::cout << std::chrono::duration_cast<std::chrono::seconds> (end - start).count() << " segudos!\n";

		start = std::chrono::steady_clock::now();
		numresult = fibonacciRecursiva(num);
		end = std::chrono::steady_clock::now();
		std::cout << "\nEl valor correspondiente con algoritmo de Fibonnaci Recursivo es: " << numresult << "\nTerminado en\n" << std::chrono::duration_cast<std::chrono::nanoseconds > (end - start).count() << " nano ssegundos!\n";
		std::cout << std::chrono::duration_cast<std::chrono::microseconds> (end - start).count() << " micro segundos!\n";
		std::cout << std::chrono::duration_cast<std::chrono::milliseconds> (end - start).count() << " milisegundos!\n";
		std::cout << std::chrono::duration_cast<std::chrono::seconds> (end - start).count() << " segudos!\n"; 
		std::cout << ("\n------------------------------------------------------\n");
	}
	std::cout << "El programa se cerrara en 5 segundos...\n";
	Sleep(1000);
	std::cout << "4...\n";
	Sleep(1000);
	std::cout << "3...\n";
	Sleep(1000);
	std::cout << "2...\n";
	Sleep(1000);
	std::cout << "1...\n";
	Sleep(1000);
	return 0;
}