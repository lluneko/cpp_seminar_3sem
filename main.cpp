#include "dinamic_list.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Создание массива" << endl;
    DynamicArray<int> a(5);
    for (int i = 0; i < 5; ++i) a.set(i, (i + 1) * 10);
    cout << "a = " << a << endl;
    DynamicArray<string> sl(3);
    sl.set(0, "hellooo");
    sl.set(1, "myyy");
    sl.set(2, "wooorld");
    cout << "sl = " << sl << endl;

    cout << "Проверка создания массива с плохим размером." << endl;
    try {
        DynamicArray<int> bad(-3);
        cout << "bad = " << bad << endl;
    } catch (const invalid_argument& e) {
        cerr << e.what() << endl;
    }
    try {
        DynamicArray<int> bad(10000*10000);
        cout << bad.get(10000*10000 - 1) << endl;
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
    cout << "После этого массив: " << a;

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
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    cout << "Добавление значения в конец." << endl;
    a.append(77);
    try {
        a.append(500);
    } catch (const invalid_argument& e) {
        cerr << e.what() << endl;
    }
    a.append(-33);
    cout << "a = " << a << endl;

    cout << "Сложение и вычитание." << endl;
    DynamicArray<int> x(4), y(2);
    x.set(0, 10); x.set(1, 21); x.set(2, 34); x.set(3, 40);
    y.set(0, 8);  y.set(1, 5);
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    DynamicArray<int> x1(x);
    x.add(y);
    cout << "x.add(y) = " << x << endl;
    x1.subtract(y);
    cout << "x.subtract(y) = " << x1 << endl;

    cout << "Нахождение расстояния" << endl;
    DynamicArray<int> v1(3);
    DynamicArray<int> v2(3);
    v1.set(0, 1); v1.set(1, 2); v1.set(2, 3);
    v2.set(0, 4); v2.set(1, 6); v2.set(2, 3);
    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;
    cout << "Расстояние между v1 и v2: " << v1.distance(v2) << endl;
    DynamicArray<int> v3(2);
    cout << "Нахождение расстояния - ошибки:" << endl;
    v3.set(0, 1); v3.set(1, 1);
    try {
        cout << "v1.distance(v3): ";
        cout << v1.distance(v3) << endl;
    } catch (const std::invalid_argument& e) {
        cerr << e.what() << endl;
    }
    DynamicArray<string> s1(2);
    DynamicArray<string> s2(2);
    s1.set(0, "a"); s1.set(1, "b");
    s2.set(0, "c"); s2.set(1, "d");
    try {
        cout << "s1.distance(s2): ";
        cout << s1.distance(s2) << endl;
    } catch (const std::bad_typeid& e) {
        cerr << "std::bad_typeid! Нечисловой тип данных." << endl;
    }

    cout << "всё!" << endl;
    return 0;
}