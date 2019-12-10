//Worker: Фамилия и инициалы, Должность, Год поступления на работу, Зарплата.Создать массив объектов.
//Вывести : а) список работников, стаж работы которых на данном предприятии превышает заданное число лет;
//список работников, зарплата которых больше заданной; в) список работников, занимающих заданную должность.
#include <iostream>
#include<locale.h>
#include<stdlib.h>
#include < string.h > 
//#include <pch.h>
//#define YES 1
//#define NO 0 

void show(int mode, int i);
using namespace std;

class Worker
{
private:
    //свойства класса
    char surname[100]; //фамилия и инициалы выводить посимвольно, вывод фором пока итый эл не станет /0
    char position[100]; //должность
    int start_of_work; //год поступления на работу
    int salary; //зарплата

public:
    //методы класса
    int sravni(int y) //у = стаж
    {
        if (2019 - start_of_work >= y) //если настоящий год минус год начала работы больше или равен введенному стажу, то
            return 0;
        else
            cout << "Нет работника с заданным стажом работы" << endl;
            return 1;
    }

    int srav(int a) // заданная зарплата 
    {
        if (salary > a) //если зарплата больше или равна заданной, то
            return 0;
        else
            cout << "Нет работника с заданной заплатой" << endl;
            return 1;
    }

    int srp(char x[100])
    {
        if (strcmp(x, position) == 0)
            return 0;
        else
            cout << "Нет работника с заданной должностью" << endl;
        return 1;
        system("pause");

    }

    void get(void)
    {
        /*system("cls");*/
        cout << "Фамилия и инициалы: " << surname << endl;
        cout << "Должность: " << position << endl;
        cout << "Год поступления на работу: " << start_of_work << endl;
        cout << "зарплата: " << salary << endl;
        system("pause");
    }

    void set(void)
    {
        cout << "Введите фамилию и инициалы работника: " << endl;
        cin.get();
        cin.getline(surname, 100);
        cout << "Введите должность: " << endl;
        cin.getline(position, 100);
        cout << "Введите год поступления на работу: " << endl;
        cin >> start_of_work;
        cout << "Введите зарплату: " << endl;
        cin >> salary;
    }
};

class Worker* library;


int main(void)
{
    int ans, i = 0;
    setlocale(LC_ALL, "Russian");
    do
    {
        system("cls");
        cout << "Хотите внести данные о новом работнике?\n 1 - да\n 2 - нет\n Любая другая кнопка - выход из программы" << endl;
        cin >> ans;
        if (ans == 1)
        {
            library = (class Worker*)realloc(library, (i + 1) * sizeof(class Worker));
            library[i].set();
            i++;
        }
        else if (ans == 2)
        {
            int ans2;
            cout << "Выберите:\n 1 - список работников, стаж работы которых на данном предприятии превышает заданное число лет" << endl;
            cout << "2 - список работников, зарплата которых больше заданной" << endl << "3 - список работников, занимающих заданную должность" << endl;
            cin >> ans;
            show(ans, i);
        }
        else
            break;
    } while (1);
    free(library);
    return 0;
}

void show(int mode, int i)
{
    switch (mode)
    {
    case(1):
    {
        int experience;
        cout << "Введите искомый стаж работы:" << endl;
        cin >> experience;
        for (int k = 0; k < i; k++)
        {
            if (library[k].sravni(experience) == 0)
                library[k].get();
        }
        break;
    }

    case(2):
    {
        int pay;
        cout << "Введите искомую зарплату:" << endl;
        cin >> pay;
        for (int k = 0; k < i; k++)
        {
            if (library[k].srav(pay) == 0)
                library[k].get();
        }
        break;
    }

    case(3):
    {
        char name[100];
        cout << "Введите искомую должность:" << endl;
        cin.get();
        cin.getline(name, 100);
        for (int k = 0; k < i; k++)
        {
            if (library[k].srp(name) == 0)
                library[k].get();
        }
        break;
    }
    }
    system("pause");
}
