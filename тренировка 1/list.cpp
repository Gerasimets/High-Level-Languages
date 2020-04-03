#include "list.h"

// this - указатель на объект, который вызвал данную фунцию

queue::queue() //конструктор
{
	begin = nullptr;
	end = nullptr;
	size = 0;
}

queue::queue(const queue & src) //конструктор копирования
{
	begin = nullptr;
	end = nullptr;
	size = 0;
	list_element* temp = src.begin; //начало списка, из которого копируем
	while (temp != 0) //пока не конец списка 
	{
		push(temp->value);
		temp = temp->next;
	}
}

// функция проверяет, пуст ли список
bool queue::empty() const
{
	if (size == 0) return 1;
	return 0;
}

// добавление элемента в конец списка
void queue::push(int new_value)
{
	list_element* new_element = new list_element; // выделить память под переменную типа list_element и присвоить адрес
													// начала выделенной памяти в переменную-указатель new_element
	new_element->value = new_value; // пойти по указателю new_element, получить переменную типа list_element, которая там находится
									// и в ней изменить поле value
	new_element->next = nullptr;	// добавляем в конец, поэтому следующего элемента нет
	new_element->prev = nullptr;	// добавляем в конец, поэтому следующего элемента нет
	// если список не пустой
	if (!empty())
	{
		end->next = new_element;	// прежний последний элемент списка теперь указвывает на новый элемент
		new_element->prev = end; //указатель на предыдущий элемент указывает на прошлый последний элемент
	}
	// если список пустой
	else begin = new_element;  // новый элемент является началом списка			
	end = new_element;	// новый элемент теперь является концом списка
	size++;		// размер списка увеличился на единицу
}
/*
// добавление в начало списка
void queue::push_front(int new_value)
{
	list_element* new_element = new list_element;   // выделить память под переменную типа list_element и присвоить адрес
													// начала выделенной памяти в переменную-указатель new_element
	new_element->value = new_value; // пойти по указателю new_element, получить переменную типа list_element, которая там находится
									// и в ней изменить поле value
	new_element->next = begin; // теперь указателю на следующий элемент списка присваивается прошлый первый элемент списка 
	new_element->prev = nullptr; //указатель на предыдущий элемент пустой, так как добавляем первый элемент
	//если список не пустой
	if (!empty()) begin->prev = new_element; //
	//если список пустой
	if (empty()) end = new_element; // новый элемент теперь является концом списка
	begin = new_element; // новый элемент является началом списка
	size++; // размер списка увеличился на единицу
}

// удаление последнего элемента, возвращает значение этого элемента
void queue::pop_back()
{ 
	list_element* del_element = end; // переменная-указатель(предыдущий элемент) типа list_element указывает на предпоследний элемент списка
	end = end->prev; //последний элемент списка теперь указывает на предыдущий 
	if (size == 1) begin = nullptr;
	delete del_element;
	if (size != 1) end->next = nullptr;
	size--;
}
*/
//удаление первого элемента
void queue::pop()
{
	list_element* element_to_delete = begin;
	begin = begin->next;
	if (size==1) end = nullptr;
	delete element_to_delete;
	if (size!=1) begin->prev = nullptr;
	size--;
}

int queue::back() const
{
	return end->value;
}

int queue::front() const
{
	return begin->value;
}

queue concat(const queue& Q1, const queue& Q2)
{
	queue Q;
	list_element* temp = Q1.begin; //начало списка, из которого копируем
	while (temp != 0) //пока не конец списка 
	{
		Q.push(temp->value);
		temp = temp->next;
	}

	temp = Q2.begin;
	while (temp != 0) //пока не конец списка 
	{
		Q.push(temp->value);
		temp = temp->next;
	}
	return Q;
}

int MyQueue::max_value()
{

}

int max()
{
	int a[5] = { 1,3,7,2,4 };
	int max = a[0];
	for (int i = 1; i < 5; i++)
	{

	}
}
