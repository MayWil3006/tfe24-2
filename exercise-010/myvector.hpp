#pragma once
#include <cstddef>
#include <stdexcept>
#include <algorithm>
#include <fmt/core.h> 

namespace tfe24 {

template <typename T>
class MyVector {
private:
    T* data_; // Zeiger auf Speicherblock in dem Elemente liegen
    size_t size_; // Anzahl der aktuell gespeicherten Elemente
    size_t capacity_; // Aktuelle Kapazität des Vektors (Wie viele Elemente in data platz haben bevor neu alloziert werden muss)

public:
    // Konstruktoren und Destruktor
    MyVector() noexcept // leerer Vektor ohne Speicher
        : data_(nullptr), size_(0), capacity_(0) {}

    explicit MyVector(size_t count) // Vektor mit count Elementen für die die richtige Menge an Speicher alloziert wird
        : data_(new T[count]()), size_(count), capacity_(count) {}

    ~MyVector() {
        delete[] data_;
    }

    // Copy-Konstruktor (Deep Copy)
    MyVector(const MyVector& other)
        : data_(new T[other.capacity_]),
          size_(other.size_),
          capacity_(other.capacity_) {
        std::copy(other.data_, other.data_ + other.size_, data_);
    }

    // Copy-Assignment (Deep Copy)
    MyVector& operator=(const MyVector& other) {
        if (this != &other) {
            T* new_data = new T[other.capacity_];
            std::copy(other.data_, other.data_ + other.size_, new_data);
            delete[] data_;
            data_ = new_data;
            size_ = other.size_;
            capacity_ = other.capacity_;
        }
        return *this;
    }

    // Element hinzufügen (mit Wachstum)
    void push_back(const T& value) {
        if (size_ >= capacity_) { // Wenn Speicher voll ist
            reserve(capacity_ == 0 ? 1 : capacity_ * 2); // Verdopple die Kapazität
        }
        data_[size_++] = value; // Füge das neue Element hinzu und erhöhe die Größe
    }

    // Zugriff mit Bereichsprüfung
    T& at(size_t index) {
        if (index >= size_) throw std::out_of_range("Index out of range");
        return data_[index];
    }

    const T& at(size_t index) const {
        if (index >= size_) throw std::out_of_range("Index out of range");
        return data_[index];
    }

    // Zugriff ohne Prüfung
    T& operator[](size_t index) noexcept { return data_[index]; }
    const T& operator[](size_t index) const noexcept { return data_[index]; }

    // Statusfunktionen
    size_t size() const noexcept { return size_; }
    size_t capacity() const noexcept { return capacity_; }

    // Methoden
    void clear() noexcept { size_ = 0; }

    // Prüft ob mehr Platz nötig ist; Allokiert größeren Speicherblock; Kopiert bisherige Elemente rüber; 
    //Löscht alten Speicher; Aktualisiert Zeiger und capacity_.
    void reserve(size_t new_cap) { 
        if (new_cap <= capacity_) return;
        T* new_data = new T[new_cap];
        for (size_t i = 0; i < size_; ++i)
            new_data[i] = data_[i];
        delete[] data_;
        data_ = new_data;
        capacity_ = new_cap;
    }

    void resize(size_t new_size) {
        if (new_size > capacity_) reserve(new_size);
        if (new_size > size_)
            for (size_t i = size_; i < new_size; ++i)
                data_[i] = T();
        size_ = new_size;
    }

    // Debug-/Demoausgabe
    void print() const {
        fmt::print("MyVector(size={}, capacity={}): ", size_, capacity_);
        for (size_t i = 0; i < size_; ++i) {
            fmt::print("{} ", data_[i]);
        }
        fmt::print("\n");
    }
};

} // namespace tfe24

