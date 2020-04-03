#include <iostream>
#include "list.h"

int main()
{
	queue Q;
	Q.push(5);
	Q.push(2);
	Q.push(4);
	/*
	std::cout << Q.front() << '\n';
	Q.pop();
	std::cout << Q.front() << '\n';
	Q.pop();
	Q.push(6);
	std::cout << Q.front() << '\n';
	Q.pop();
	std::cout << Q.front() << '\n';
	Q.pop();
	if (Q.empty()) std::cout << "queue is empty\n";
	*/
	queue Q2(Q);
	/*
	Q.push(11);
	Q2.pop();
	*/
	queue Q3 = concat(Q, Q2);

	/*queue Q2 = Q;
	std::cout << Q2 << '\n';*/
}

/*
struct Point
{
	double x;
	double y;
	double z;
	char name;
};
*/
/*
int main()
{
	Point A{ 2,5,-3,'A' };
	A.x = 7;
	std::cout << "Point name is " << A.name << "  Coordinates: " << A.x << " " << A.y << " " << A.z << '\n';
	return 0;
}
*/
/*
int main()
{
	int a = 235;
	int* p; //указатель на переменную типа int. он может хранить адрес в памяти
	p = &a; //получить адрес в памяти переменной a и сохранить его в переменную p
	std::cout << *p << '\n'; //разыменовывание указателя - получаем значение по адресу, на который указывает указатель
}
*/

