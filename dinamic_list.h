#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <cmath>
using namespace std;

template <typename T>
class DynamicArray {
private:
    T* data;      
    int size;
    int capacity;       

public:
    DynamicArray(int size);
    DynamicArray(const DynamicArray& other);
    ~DynamicArray();

    void set(int index, const T& value);
    T get(int index) const;
    void append(const T& value);
    void add(const DynamicArray& other);
    void subtract(const DynamicArray& other);
    int getSize() const { return size; }
    double distance(const DynamicArray<T>& other) const;

    friend std::ostream& operator<<(std::ostream& stream, const DynamicArray<T>& arr) {
        stream << "[";
        for (int i = 0; i < arr.getSize(); i++) stream << arr.get(i) << (i < arr.getSize() - 1 ? ", " : "");
        stream << "]";
        return stream;
    }
};

template <typename T>
DynamicArray<T>::DynamicArray(int size) : size(size), capacity(size + 20) {
    if (size < 0) {
        throw invalid_argument("Ошибка! Некорректный размер: меньше 0.");
    }
    data = new T[this->capacity]();
}

template <typename T>
double DynamicArray<T>::distance(const DynamicArray<T>& other) const {
    if constexpr (!is_arithmetic_v<T>) {
        throw std::bad_typeid(); 
    } else {
        if (size != other.size) {
            throw std::invalid_argument("Ошибка distance: размеры массивов не совпадают.");
        }
        double sum = 0.0;
        for (int i = 0; i < size; ++i) {
            double diff = static_cast<double>(data[i]) - static_cast<double>(other.data[i]);
            sum += diff * diff;
        }
        return sqrt(sum);
    }
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& other) : size(other.size) {
    data = new T[size];
    for (int i = 0; i < size; ++i) data[i] = other.data[i];
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] data;
}

template <typename T>
void DynamicArray<T>::set(int index, const T& value) {
    if (index < 0 || index >= size) {
        throw out_of_range("Ошибка! set: индекс:" + to_string(index) + " вне границ [0.." + to_string(size - 1) + "]. Не выполнено.");
    }
    if constexpr(is_integral_v<T>) {
        if (value < static_cast<T>(-100) || value > static_cast<T>(100)) {
            throw invalid_argument("Ошибка! set: значение:" + to_string(value) + " вне диапазона [-100; 100]. Не выполнено.");
        }
    }
    data[index] = value;
}

template <typename T>
T DynamicArray<T>::get(int index) const {
    if (index < 0 || index >= size) {
        throw out_of_range("Ошибка! get: индекс:" + to_string(index) + " вне границ [0.." + to_string(size - 1) + "]. Не выполнено.");
    }
    return data[index];
}

template <typename T>
void DynamicArray<T>::append(const T& value) {
    if constexpr(is_integral_v<T>) {
        if (value < static_cast<T>(-100) || value > static_cast<T>(100)) {
            throw invalid_argument("Ошибка! append: значение: " + to_string(value) + " вне диапазона [-100; 100]. Не выполнено.");
        }
    }
    if (capacity > size) {
        data[size + 1] = value;
        size++;
    } else {
        capacity = capacity + 20;
        T* newData = new T[capacity];
        for (int i = 0; i < size; ++i) newData[i] = data[i];
        newData[size] = value;
        delete[] data;
        data = newData;
        size++;
    }
}

template <typename T>
void DynamicArray<T>::add(const DynamicArray& other) {
    int minsize = (size < other.size) ? size : other.size;
    for (int i = 0; i < minsize; ++i) data[i] += other.data[i];
}

template <typename T>
void DynamicArray<T>::subtract(const DynamicArray& other) {
    if constexpr(is_arithmetic_v<T>) {
        int minsize = (size < other.size) ? size : other.size;
        for (int i = 0; i < minsize; ++i) data[i] -= other.data[i];
    } else {
        throw invalid_argument("Ошибка! subtract: значения не являются числами.");
    }
    
}