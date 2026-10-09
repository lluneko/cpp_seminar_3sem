#include "dinamic_list.h"
#include <iostream>
using namespace std;

DynamicArray::DynamicArray(int size) : size(size), capacity(size + 20) {
    if (size < 0) {
        throw invalid_argument("Ошибка! Некорректный размер: меньше 0.");
    }
    data = new int[this->capacity]();
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
        throw out_of_range("Ошибка! set: индекс:" + to_string(index) + " вне границ [0.." + to_string(size - 1) + "]. Не выполнено.");
    }
    if (value < -100 || value > 100) {
       throw invalid_argument("Ошибка! set: значение:" + to_string(value) + " вне диапазона [-100; 100]. Не выполнено.");
    }
    data[index] = value;
}

int DynamicArray::get(int index) const {
    if (index < 0 || index >= size) {
        throw out_of_range("Ошибка! get: индекс:" + to_string(index) + " вне границ [0.." + to_string(size - 1) + "]. Не выполнено.");
    }
    return data[index];
}

void DynamicArray::append(int value) {
    if (value < -100 || value > 100) {
        throw invalid_argument("Ошибка! append: значение: " + to_string(value) + " вне диапазона [-100; 100]. Не выполнено.");
    }
    if (capacity > size) {
        data[size + 1] = value;
        size++;
    } else {
        capacity = capacity + 20;
        int* newData = new int[capacity];
        for (int i = 0; i < size; ++i) newData[i] = data[i];
        newData[size] = value;
        delete[] data;
        data = newData;
        size++;
    }
}

void DynamicArray::add(const DynamicArray& other) {
    int minsize = (size < other.size) ? size : other.size;
    for (int i = 0; i < minsize; ++i) data[i] += other.data[i];
}

void DynamicArray::subtract(const DynamicArray& other) {
    int minsize = (size < other.size) ? size : other.size;
    for (int i = 0; i < minsize; ++i) data[i] -= other.data[i];
}