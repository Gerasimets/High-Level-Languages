#pragma once
#include "list.h"

class queue
{
	list list;
public:
	queue() {};
	void push(int value)
	{
		list.push_back(value);
	}
	int front()
	{
		return list.front();
	}
	void pop()
	{
		list.pop_front();
	}
	int empty()
	{
		return list.empty();
	}
};
