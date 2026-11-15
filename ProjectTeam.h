#ifndef PROJECT_TEAM_H
#define PROJECT_TEAM_H

#include <string>
#include <cstddef>
#include <algorithm>

class ProjectTeam {
public:
    ProjectTeam() = default;
    explicit ProjectTeam(std::size_t capacity);

    // Правило п'яти
    ~ProjectTeam();
    ProjectTeam(const ProjectTeam& other);
    ProjectTeam& operator=(ProjectTeam other) noexcept;
    ProjectTeam(ProjectTeam&& other) noexcept;
    ProjectTeam& operator=(ProjectTeam&& other) noexcept;

    // Функція swap для copy-and-swap
    friend void swap(ProjectTeam& first, ProjectTeam& second) noexcept {
        using std::swap;
        swap(first.items_, second.items_);
        swap(first.size_, second.size_);
        swap(first.capacity_, second.capacity_);
    }

    void add(const std::string& surname);
    std::size_t size() const { return size_; }

    // Статичні лічильники
    inline static int copy_count = 0;
    inline static int move_count = 0;

private:
    std::string* items_ = nullptr;
    std::size_t size_ = 0;
    std::size_t capacity_ = 0;
};

#endif