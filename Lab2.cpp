// Lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<malloc.h>
#include<omp.h>
using namespace std;

int main() {
	int sec, items, * all_items, total = 0, i, j, threads;
	cout << "Enter the number of sections: ";
	cin >> sec;
	cout << "Enter the number of items: ";
	cin >> items;
	all_items = (int*)malloc(sec * items * sizeof(int));
	cout << "Enter the items: " << endl;
	for (i = 0; i < sec; i++) {
		cout << "Section " << i + 1 << endl;
		for (j = 0; j < items; j++) {
			cin >> all_items[i * items + j];
		}
	}
	omp_set_num_threads(2);
#pragma omp parallel for num_threads(4)
	for (i = 0; i < sec; i++) {
		for (j = 0; j < items; j++) {
#pragma omp critical
			{
				total += all_items[i * items + j];
			}
		}
		threads = omp_get_num_threads();
	}
	cout << "Total cost = Rs." << total << "/-" << endl;
	cout << "Number of threads = " << threads << endl;
	return 0;
}