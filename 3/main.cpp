#include <iostream>

struct Point
{
	double x;
	double y;
};

void print_coord(Point A)
{
	std::cout << "(" << A.x << ";" << A.y << ")" << '\n';
}

double distance(Point A)
{
	return sqrt(A.x * A.x + A.y * A.y);
}

double dist(Point A, Point B)
{
	return sqrt((B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y));
}

int main()
{
	Point a;
	a.x = 2.3;
	a.y = 7;

	Point b;
	b.x = 3;
	b.y = 1;

	print_coord(a);
	std::cout << distance(a) << '\n';
	std::cout << dist(a,b) << '\n';
	return 0;
}
