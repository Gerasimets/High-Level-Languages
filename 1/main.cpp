#include <iostream>
using namespace std;

int main()
{
	const int N = 10;
	int a[N]; // массив из N элементов типа int
	for (int i = 0; i < N; i++) a[i] = 10 - i;
	for (int i = 0; i < N; i++) cout << "a[" << i << "]=" << a[i] << endl;
	return 0;
}
