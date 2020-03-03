#include <iostream>
#include "list.h"

int main()
{
	list MyList;
	MyList.push_back(5);
	MyList.push_front(7);
	int a = MyList.back();
	int b = MyList.front();
	if (!MyList.empty())	std::cout << MyList.back() << '\n';
	MyList.pop_back();
	if (!MyList.empty())	std::cout << MyList.front() << '\n';
	MyList.pop_front();
	if (MyList.empty()) std::cout << "List is empty\n";
	// то же самое с очередью. подобавлять, поудалять элементы, и убедиться, что они возвращаются в верном порядке
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

