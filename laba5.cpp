#include <iostream>
#include <math.h>
#define five 5
using namespace std;
/*
 66   21  -3   -1  90
 1    74  -2   80  -1
10   30  20 -50  91
 2     4    5   81   0
33   69  -5   51  24


 */

class Vector {
private:
	int array[5];
public:
	friend void InputMatrix(Vector matrix[]) {
		for (int line = 0; line < five; ++line) {
			for (int column = 0; column < five; ++column) {
				cin >> matrix[column].array[line];
			}
		}

	}

	void Sort(int start, int last) {
		if (start < last) {
			int mean = (start + last) / 2;
			Sort(start, mean);
			Sort(mean + 1, last);
			merge(start, mean, last);
		}
	}
	friend void sum(Vector matrix[])
	{
		int ryad, stovp, mj = 1;
		double F = 0, f;
		for (ryad = 0; ryad < five; ryad++)
		{
			for (stovp = 0; stovp < five; stovp++)
			{
				mj *= matrix[stovp].array[ryad];
				f = pow(mj, 1 / stovp);
				F += f/ryad;
			}
			cout << "F =" << F << endl;
		}
		
	}


	friend void OutMatrix(Vector matrix[])
	{
		for (int line = 0; line < five; line++)
		{
			for (int column = 0; column < five; ++column) {
				cout << matrix[column].array[line] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	void merge(int start, int mean, int last) {
		int n[5];
		int line = start, column = mean + 1, a = 0;

		while (line <= mean && column <= last) {
			if (this->array[line] <= this->array[column]) {
				n[a] = this->array[line];
				a++;
				line++;
			}
			else {
				n[a] = this->array[column];
				a++;
				column++;
			}
		}

		while (line <= mean) {
			n[a] = this->array[line];
			a++;
			line++;
		}

		while (column <= last) {
			n[a] = this->array[column];
			a++;
			column++;
		}
		for (line = start; line <= last; line++) {
			this->array[line] = n[line - start];
		}
	}
};


int main()
{
	Vector Matrix[five];
	cout << "Enter the numbers:" << endl;
	InputMatrix(Matrix);
	for (int line = 0; line < five; ++line) {
		Matrix[line].Sort(0, five - 1);
	}
	cout << "Merged matrix:" << endl;
	OutMatrix(Matrix);
	Matrix->F(Matrix);
	sum (Matrix);

	return 0;
}