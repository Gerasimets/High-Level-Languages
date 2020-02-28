#include <iostream>

// элемент списка
struct list_element
{
	int value;	// значение данного элемента списка
	list_element* next;	// указатель на следующий элемент списка
	list_element* prev;	// указатель на предыдущий элемент списка
};

// список
class list
{
public:

	// данные
	list_element* begin; // указатель на первый элемент списка
	list_element* end; // указатель на последний элемент списка
	size_t size;	// количество элементов в списке

	// конструктор
	list();

	// функции
	bool empty() const;  // функция проверяет, пуст ли список
	void push_back(int new_value);  // добавление элемента в конец списка
	void push_front(int new_value);  // добавление в начало списка
	void pop_back();  // удаление последнего элемента
	void pop_front(); // удаление первого элемента
	int back() const; // возвращает значение последнего элемента
	int front() const; // возвращает значение первого элемента
};

// this - указатель на объект, который вызвал данную фунцию

list::list() //конструктор
{
	begin = nullptr;
	end = nullptr;
	size = 0;
}

// функция проверяет, пуст ли список
bool list::empty() const
{
	if (size == 0) return 1;
	return 0;
}

// добавление элемента в конец списка
void list::push_back(int new_value)
{
	list_element* new_element = new list_element; // выделить память под переменную типа list_element и присвоить адрес
													// начала выделенной памяти в переменную-указатель new_element
	new_element->value = new_value; // пойти по указателю new_element, получить переменную типа list_element, которая там находится
									// и в ней изменить поле value
	new_element->next = nullptr;	// добавляем в конец, поэтому следующего элемента нет
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

// добавление в начало списка
void list::push_front(int new_value)
{
	list_element* new_element = new list_element;   // выделить память под переменную типа list_element и присвоить адрес
													// начала выделенной памяти в переменную-указатель new_element
	new_element->value = new_value; // пойти по указателю new_element, получить переменную типа list_element, которая там находится
									// и в ней изменить поле value
	new_element->next = begin; // теперь указателю на следующий элемент списка присваивается прошлый первый элемент списка 
	new_element->prev = nullptr; //указатель на предыдущий элемент пустой, так как добавляем первый элемент
	begin = new_element; // новый элемент является началом списка
	//если список не пустой
	if (!empty()) begin->prev = new_element; //
	//если список пустой
	if (empty()) end = new_element; // новый элемент теперь является концом списка
	size++; // размер списка увеличился на единицу
}

// удаление последнего элемента, возвращает значение этого элемента
void list::pop_back()
{ 
	list_element* del_element = end; // переменная-указатель(предыдущий элемент) типа list_element указывает на предпоследний элемент списка
	if (size != 1)
	{
		//end = end->prev; //указателю на последний элемент присваиваем предпоследний элемент  
		end = del_element->prev; //указатель на последний элемент теперь указывает на предпоследний
		                         //предпоследний элемент теперь является концом списка
		del_element->next = nullptr;
		delete del_element;
	}
	else
	{
		delete del_element;
		begin = nullptr;
		end = nullptr;
	}
	size--;
}

//удаление первого элемента
void list::pop_front()
{
	list_element* element_to_delete = begin;
	begin = begin->next;
	if (size==1) end = nullptr;
	delete element_to_delete;
	size--;
}

int list::back() const
{
	return end->value;
}

int list::front() const
{
	return begin->value;
}

int main()
{
	list MyList;
	MyList.push_back(7);
	MyList.push_back(11);
	MyList.push_back(17);
	MyList.push_back(25);
	MyList.push_front(3);
	MyList.push_front(1);
	if (!MyList.empty())	std::cout << MyList.back() << '\n';
	MyList.pop_back();
	if (!MyList.empty())	std::cout << MyList.back() << '\n';
	MyList.pop_back();
	if (!MyList.empty())	std::cout << MyList.back() << '\n';
	MyList.pop_back();
	if (!MyList.empty())	std::cout << MyList.back() << '\n';
	MyList.pop_back();
	if (!MyList.empty())	std::cout << MyList.back() << '\n';
	MyList.pop_back();
	if (!MyList.empty())	std::cout << MyList.back() << '\n';
	MyList.pop_back();
	if (!MyList.empty())	std::cout << MyList.back() << '\n';
}
