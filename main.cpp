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
    try {
        DynamicArray bad(-3);
        cout << "bad = ";
        bad.print();
    } catch (const invalid_argument& e) {
        cerr << e.what() << endl;
    }
    try {
        DynamicArray bad(10000*10000);
        cout << 1029382132 << endl;
    } catch (const bad_alloc& e) {
        cerr << e.what() << endl;
    }

    cout << "Проверки на set." << endl;
    try {
        a.set(100, 7);
    } catch (const out_of_range& e) {
        cerr << e.what() << endl;
    }
    try {
        a.set(0, 99999);
    } catch (const invalid_argument& e) {
        cerr << e.what() << endl;
    }
    a.set(0, 42);
    cout << "После этого массив: ";
    a.print();

    cout << "Проверки на get." << endl;
    cout << "get(2) = " << a.get(2) << endl;
    cout << "get(-1) = " << endl;
    try {
        a.get(-1);
    } catch (const out_of_range& e) {
        cerr << e.what() << endl;
    }

    cout << "Конструктор копирования" << endl;
    DynamicArray b(a);
    b.set(0, -5);
    cout << "a = ";
    a.print();
    cout << "b = ";
    b.print();

    cout << "Добавление значения в конец." << endl;
    a.append(77);
    try {
        a.append(500);
    } catch (const invalid_argument& e) {
        cerr << e.what() << endl;
    }
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

    // badalloc зациклить выделение памяти, либо огромный размер массива
    cout << "всё!" << endl;
    return 0;
}