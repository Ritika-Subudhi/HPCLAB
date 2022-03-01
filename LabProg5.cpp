// LabProg5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<omp.h>
#include<math.h>
using namespace std;

int main() {
	int i, n, student_details[500];
	cout << "Enter the number of students: ";
	cin >> n;
	srand(time(0));
	for (i = 0; i < n; i++) {
		/*index = > student ID
			element at index i = > CGPA(Range of 1 - 10) */
			student_details[i] = (rand() % 10) + 1;
	}

	cout << "\tStudent details: " << endl;
	cout << "--------------------------------" << endl;
	cout << "\tID\t|\tCGPA\t" << endl;
	for (i = 0; i < n; i++) {
		cout << "\t" << i + 1 << "\t|\t" << student_details[i] << "\t" << endl;
	}
	cout << "--------------------------------" << endl;

	int max_val = student_details[0];
#pragma omp parallel for
	for (i = 0; i < n; i++) {
#pragma omp critical
		max_val = max_val > student_details[i] ? max_val : student_details[i];
	}
	cout << "Student(s) receiving the gold medals are:" << endl;
	for (i = 0; i < n; i++) {
		if (student_details[i] == max_val) {
			cout << i + 1 << endl;
		}
	}
	return 0;
}
