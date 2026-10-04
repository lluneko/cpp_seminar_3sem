#include "dinamic_list.h"
#include <iostream>
using namespace std;

DynamicArray::DynamicArray(int size) : size(size) {
    if (size < 0) {
        cerr << "Ошибка! Некорректный размер:" << size << ". Создан пустой массив." << endl;
        this->size = 0;
    }
    data = new int[this->size]();
}

DynamicArray::DynamicArray(const DynamicArray& other) : size(other.size) {
    data = new int[size];
    for (int i = 0; i < size; ++i) data[i] = other.data[i];
}

DynamicArray::~DynamicArray() {
    delete[] data;
}

void DynamicArray::print() const {
    cout << "[ ";
    for (int i = 0; i < size; ++i) cout << data[i] << (i + 1 < size ? ", " : " ");
    cout << "]" << endl;
}

void DynamicArray::set(int index, int value) {
    if (index < 0 || index >= size) {
        cerr << "Ошибка! set: индекс:" << index << " вне границ [0.." << size - 1 << "]. Не выполнено." << endl;
        return;
    }
    if (value < -100 || value > 100) {
        cerr << "Ошибка! set: значение:" << value << " вне диапазона [-100; 100]. Не выполнено." << endl;
        return;
    }
    data[index] = value;
}

int DynamicArray::get(int index) const {
    if (index < 0 || index >= size) {
        cerr << "Ошибка! get: индекс: " << index << " вне границ [0.." << size - 1 << "]. Возвращен 0." << endl;
        return 0;
    }
    return data[index];
}

void DynamicArray::append(int value) {
    if (value < -100 || value > 100) {
        cerr << "Ошибка! print: значение: " << value << " вне диапазона [-100; 100]. Не выполнено." << endl;
        return;
    }
    int* newData = new int[size + 1];
    for (int i = 0; i < size; ++i) newData[i] = data[i];
    newData[size] = value;
    delete[] data;
    data = newData;
    size++;
}

void DynamicArray::add(const DynamicArray& other) {
    int minsize = (size < other.size) ? size : other.size;
    for (int i = 0; i < minsize; ++i) data[i] += other.data[i];
}

void DynamicArray::subtract(const DynamicArray& other) {
    int minsize = (size < other.size) ? size : other.size;
    for (int i = 0; i < minsize; ++i) data[i] -= other.data[i];
}