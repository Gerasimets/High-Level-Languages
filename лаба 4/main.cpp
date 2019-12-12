#include <iostream>

using namespace std;
class Worker //описывает, то что мы можем выполнять с конкретными объектами
{
private:

    string surname;
    string initials;
    string position;
    int start_of_work;
    int salary;

public:

    void set()
    {
        cout << "Введите  фамилию и инициалы" << endl;
        cin >> surname;
        cin >> initials;
        cout << "Введите должность" << endl;
        cin >> position;
        cout << "Введите год поступления на работу" << endl;
        cin >> start_of_work;
        cout << "Введите зарплату" << endl;
        cin >> salary;
    }
    void show()
    {
        cout << "фамилия и инициалы: " << surname; cout << " ";  cout << initials << endl;
        cout << "должность: " << position << endl;
        cout << "год поступления на работу: " << start_of_work << endl;
        cout << "зарплата: " << salary << endl;
    }
    //несколько get чтобы, когда нам нужно вызвать одну переменную, мы не вызывали сразу все
    string get_position()
    {
        return position;
    }
    int get_salary()
    {
        return salary;
    }
    int get_start_of_work()
    {
        return start_of_work;
    }
};

int main(int argc, const char* argv[])
{
    setlocale(LC_ALL, "Russian");

    int menu_1 = 0;
    int cnt = 0;

    class Worker** Work; // объект

    Work = new Worker * [1];
    while (menu_1 != 2)
    {
        cout << "Меню:\n  1:Ввести данные о новом работнике?\n  2:Перейти в меню поиска" << endl;
        cin >> menu_1;

        switch (menu_1)
        {
        case 1:

            Work[0] = new Worker[cnt + 1];
            for (int i = 0; i < cnt; i++)
            {
                Work[0][i] = Work[1][i];
            }
            Work[1] = new Worker[cnt + 1];

            Work[0][cnt].set();
            for (int i = 0; i < cnt + 1; i++)
            {
                Work[1][i] = Work[0][i];
            }

            cnt++;
            break;
        }

    }

    string zad_position;
    int zad_salary;
    int menu_2 = 0;
    int N; // введенный стаж
    while (menu_2 != 5)
    {
        cout << "Меню:\n    1:Поиск работников, заданной должности\n    2:Поиск работников, больше заданной зарплаты\n    3:Поиск работников, работающих больше заданного стажа\n    5:выход " << endl;
        cin >> menu_2;
        switch (menu_2)
        {
        case 1:
            cout << "Поиск работников, заданной должности\n" << "Введите должность" << endl;
            cin >> zad_position;
            for (int j = 0; j < cnt; j++)
            {
                if (zad_position == Work[0][j].get_position())
                {
                    Work[0][j].show();
                    cout << endl;
                }
            }
            break;

        case 2:
            cout << "Поиск книг, больше заданной зарплаты\n" << "Введите зарплату" << endl;
            cin >> zad_salary;
            for (int j = 0; j < cnt; j++)
            {
                if (zad_salary < Work[0][j].get_salary())
                {
                    Work[0][j].show();
                    cout << endl;
                }
            }
            break;

        case 3:
            cout << "Поиск работников, чей стаж работы больше заданного\n" << "Введите необходимый стаж" << endl;
            cin >> N;
            cout << "работники, чей стаж больше" << endl;
            for (int j = 0; j < cnt; j++)
            {
                if (2019 - Work[0][j].get_start_of_work() > N)
                {
                    Work[0][j].show();
                    cout << endl;
                }
            }
            break;
        }
    }
    cout << "конец программы" << endl;
    return 0;
}
