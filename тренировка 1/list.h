#pragma once

// заголовочный файл, в котором описывается двусвязный список

// элемент списка
struct list_element
{
	int value;	// значение данного элемента списка
	list_element* next;	// указатель на следующий элемент списка
	list_element* prev;	// указатель на предыдущий элемент списка
};

// список
class queue
{
public:
	// данные
	list_element* begin; // указатель на первый элемент списка
	list_element* end; // указатель на последний элемент списка
	size_t size;	// количество элементов в списке
//public:
	// конструктор
	queue();
	//конструктор копирования
	queue(const queue&);

	// функции
	bool empty() const;  // функция проверяет, пуст ли список
	void push(int new_value);  // добавление элемента в конец списка
	//void push_front(int new_value);  // добавление в начало списка
	//void pop_back();  // удаление последнего элемента
	void pop(); // удаление первого элемента
	int back() const; // возвращает значение последнего элемента
	int front() const; // возвращает значение первого элемента
	//friend queue concat(const queue& Q1, const queue& Q2);
};


queue concat(const queue& Q1, const queue& Q2);

class MyQueue : public queue
{
	int max_value();
};
