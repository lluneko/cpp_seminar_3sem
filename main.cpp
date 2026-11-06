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

    cout << "Оператор []" << endl;
    DynamicArray<int> h(3);
    h[0] = 10; 
    h[1] = -50;
    h[2] = 99;
    cout << "h = " << h << endl;
    try {
        int x = a[10];
    } catch (const std::out_of_range& e) {
        cerr << e.what() << endl;
    }

    cout << "Сравнение" << endl;
    DynamicArray<int> r(3);
    r[0] = 10; r[1] = -50; r[2] = 99;
    if (h == r) cout << "h и r равны" << endl;
    r[0] = 5;
    if (h != r) cout << "После изменения r[0], h и r не равны" << endl;

    cout << "Составные операторы" << endl;
    DynamicArray<int> c(4);
    c[0] = 1; c[1] = 2; c[2] = 3; c[3] = 4;
    DynamicArray<int> d(2);
    d[0] = 10; d[1] = 20;
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;
    c += d;
    cout << "c += d: " << c << " (ожидалось [11, 22, 3, 4])" << endl;
    c += 5;
    cout << "c += 5: " << c << endl;
    c -= 1;
    cout << "c -= 1: " << c << endl;

    cout << "ТЕСТ ИТЕРАТОРОВ!" << endl;
    for (const auto& x : c) {
        cout << x << " ";
    }
    cout << endl;

    cout << "Проверка оператора присваивания:" << endl;
    DynamicArray<int> p(2), w(2);
    p[0] = 1; p[1] = 2;
    w[0] = 9; w[1] = 8;
    cout << "До p = w: p=" << p << ", w=" << w << endl;
    p = w; // Копирующее присваивание
    cout << "После p = w: p=" << p << ", b=" << w << endl;
    p = std::move(w); // Move-присваивание
    cout << "После p = move(w): p=" << p << ", b(пуст)=" << w << endl;

    cout << "всё!" << endl;
    return 0;
}