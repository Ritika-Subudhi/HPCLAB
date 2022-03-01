// Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*Given an n*n matrix A and a vector X of length n, their product Y = A*X.
Write a program to implement multiplication using OpenMP parallel directives.*/
#include<iostream>
#include<omp.h>
using namespace std;

int main() {
	int n, i, j, threads;
	cout << "Enter the dimensions: ";
	cin >> n;
	int A[100][100], X[100];

	cout << "Enter the matrix elements:\n";
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> A[i][j];
		}
	}

	cout << "Enter the elements of the vector: ";
	for (i = 0; i < n; i++) {
		cin >> X[i];
	}

	omp_set_num_threads(2);
#pragma omp parallel for num_threads(4)
	for (j = 0; j < n; j++) {
		int total = 0;
		for (i = 0; i < n; i++) {
#pragma omp critical 
			{
				total += A[i][j] * X[i];
			}
		}
		cout << total << " ";
		threads = omp_get_num_threads();
	}
	cout << endl;
	cout << "Number of threads = " << threads << endl;
	return 0;
}
