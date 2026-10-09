#pragma once
#include <iostream>

class DynamicArray {
private:
    int* data;      
    int size;
    int capacity;       

public:
    DynamicArray(int size);
    DynamicArray(const DynamicArray& other);
    ~DynamicArray();

    void print() const;
    void set(int index, int value);
    int get(int index) const;
    void append(int value);
    void add(const DynamicArray& other);
    void subtract(const DynamicArray& other);
    int getSize() const { return size; }
};