#include "ProjectTeam.h"
#include <algorithm>

// Звичайний конструктор
ProjectTeam::ProjectTeam(std::size_t capacity)
    : size_(0), capacity_(capacity) {
    items_ = new std::string[capacity_];
}

// Деструктор
ProjectTeam::~ProjectTeam() {
    delete[] items_;
}

// Конструктор копіювання (глибока копія + інкрементом лічильника)
ProjectTeam::ProjectTeam(const ProjectTeam& other)
    : size_(other.size_), capacity_(other.capacity_) {
    copy_count++;
    items_ = new std::string[capacity_];
    for (std::size_t i = 0; i < size_; ++i) {
        items_[i] = other.items_[i];
    }
}

// Оператор присвоєння копіюванням через copy-and-swap
ProjectTeam& ProjectTeam::operator=(ProjectTeam other) noexcept {
    swap(*this, other);
    return *this;
}

// Конструктор переміщення
ProjectTeam::ProjectTeam(ProjectTeam&& other) noexcept
    : items_(other.items_), size_(other.size_), capacity_(other.capacity_) {
    move_count++;
    other.items_ = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
}

// Оператор присвоєння переміщенням
ProjectTeam& ProjectTeam::operator=(ProjectTeam&& other) noexcept {
    if (this != &other) {
        delete[] items_;
        items_ = other.items_;
        size_ = other.size_;
        capacity_ = other.capacity_;

        other.items_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }
    return *this;
}

// Метод додавання елемента
void ProjectTeam::add(const std::string& surname) {
    if (size_ < capacity_) {
        items_[size_++] = surname;
    }
}