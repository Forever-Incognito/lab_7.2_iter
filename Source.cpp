//lab_7.2_iter

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Creat(int** a, const int k, const int n, int Low, int High)
{
	for (int i = 0; i < k; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int k, const int n)
{
	cout << endl;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

int SearchMinMax(int** a, const int k, const int n)
{
	int* max = new int[k];
		for (int i = 0; i < k; i++)
		{
			if (k % 2 == 0)
			{
				max[i] = a[i][0];
				for (int j = 0; j < n; j++)
					if (a[i][j] > max[i])
						max[i] = a[i][j];
			}
		}

	int min = max[0];
	for (int i = 0; i < n; i++)
		if (max[i] < min)
			min = max[i];

	delete[]max;

	return min;
}

int main()
{
	srand((unsigned)time(NULL));

	int Low = -15;
	int High = 75;

	int k, n;
	cout << " k = "; cin >> k;
	cout << " n = "; cin >> n;

	int** a = new int* [k];
	for (int i=0; i < k; i++)
		a[i] = new int[n];

	Creat(a, k, n, Low, High);
	Print(a, k, n);

	int minMax = SearchMinMax(a, k, n);
	cout << " MinMax = " << minMax << endl;

	for (int i = 0; i < k; i++)
		delete[] a[i];
	delete[] a;

	return 0;
}