#include <iostream>
#include <math.h>
using namespace std;

class Vector {
private:
	int Five [5];
	int array[5];
public:
	friend void InputMatrix(Vector matrix[]) {
		for (int b = 0; b < five; ++b) {
			for (int a = 0; a < five; ++a) {
				cin >> matrix[a].array[b];
			}
		}

	}

	void sort(int start, int last) {
		if (start < last) {
			int mean = (start + last) / 2;
			sort(start, mean);
			sort(mean + 1, last);
			merge(start, mean, last);
		}
	}
	friend void sum(Vector matrix[])
	{
		int i, j, mnojenny = 1;
		double F = 0, f;
		for (i = 0; i < five; i++)
		{
			for (j = 0; j < five; j++)
			{
				mnojenny *= matrix[j].array[i];
				f = pow(mnojenny, 1 / j);
				F += f/i;
			}
			cout << "F =" << F << endl;
		}
		
	}


	friend void OutMatrix(Vector matrix[])
	{
		for (int b = 0; b < five; b++)
		{
			for (int a = 0; a < five; ++a) {
				cout << matrix[a].array[b] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	void merge(int start, int mean, int last) {
		int n[5];
		int b = start, a = mean + 1, a = 0;

		while (b <= mean && a <= last) {
			if (this->array[b] <= this->array[a]) {
				n[a] = this->array[b];
				a++;
				b++;
			}
			else {
				n[a] = this->array[a];
				a++;
				a++;
			}
		}

		while (b <= mean) {
			n[a] = this->array[b];
			a++;
			b++;
		}

		while (a <= last) {
			n[a] = this->array[a];
			a++;
			a++;
		}
		for (b = start; b <= last; b++) {
			this->array[b] = n[b - start];
		}
	}
};


int main()
{
	Vector Matrix[5];
	cout << "Enter the numbers:" << endl;
	InputMatrix(Matrix);
	for (int b = 0; b < 5; ++b) {
		Matrix[b].sort(0, 5 - 1);
	}
	cout << "Merged matrix:" << endl;
	OutMatrix(Matrix);
	Matrix->F(Matrix);
	sum (Matrix);

	return 0;
}