#include "dinamic_list.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Создание массива" << endl;
    DynamicArray a(5);
    for (int i = 0; i < 5; ++i) a.set(i, (i + 1) * 10);
    cout << "a = "; 
    a.print();

    cout << "Проверка создания массива с плохим размером." << endl;
    DynamicArray bad(-3);
    cout << "bad = ";
    bad.print();

    cout << "Проверки на set." << endl;
    a.set(100, 7);
    a.set(0, 99999);
    a.set(0, 42);
    cout << "После этого массив: ";
    a.print();

    cout << "Проверки на get." << endl;
    cout << "get(2) = " << a.get(2) << endl;
    cout << "get(-1) = " << a.get(-1) << " (ошибка, вернётся 0)" << endl;

    cout << "Конструктор копирования" << endl;
    DynamicArray b(a);
    b.set(0, -5);
    cout << "a = ";
    a.print();
    cout << "b = ";
    b.print();

    cout << "Добавление значения в конец." << endl;
    a.append(77);
    a.append(500);
    a.append(-33);
    cout << "a = ";
    a.print();

    cout << "Сложение и вычитание." << endl;
    DynamicArray x(4), y(2);
    x.set(0, 10); x.set(1, 21); x.set(2, 34); x.set(3, 40);
    y.set(0, 8);  y.set(1, 5);
    cout << "x = ";
    x.print();
    cout << "y = ";
    y.print();
    DynamicArray x1(x);
    x.add(y);
    cout << "x.add(y) = ";
    x.print();
    x1.subtract(y);
    cout << "x.subtract(y) = ";
    x.print();

    cout << "всё!" << endl;
    return 0;
}