#include <iostream>
using namespace std;

int main()
{
	const int N = 5;
	int a[N]; // массив из N элементов типа int
	cout << "Enter 5 numbers" << endl;
	for (int i = 0; i < N; i++) cin >> a[i];
	for (int i = 0; i < N; i++)
	{
		if (a[i] % 2 == 1)
			cout << a[i] << endl;
	}
	return 0;
}
