// floatIncrement.cpp: определяет точку входа для консольного приложения.
//


#include "stdafx.h"
#include <vector>
#include <time.h>
#include <iostream>
#include <thread>
#include <atomic>


#pragma optimize("",off);

int main()
{
	std::atomic<float> a{0};
	std::thread t([&]() {
		for (size_t i = 0; i < 20000; i++)
		{
			float current = a.load(); 
		float next;
		do {
			next = current + 1;
		}
		while (!a.compare_exchange_weak(current, next))
			;
		}
	});
	for (size_t i = 0; i < 30000; i++)
	{
		float current = a.load(); 
		float next;
		do {
			next = current + 1;
		}
		while (!a.compare_exchange_weak(current, next))
			;
	}

	t.join();


	std::cout << a << "\n";
	system("pause");
	return 0;
}

