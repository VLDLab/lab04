#pragma once
#ifndef PROJECT_TEAM_V2_H
#define PROJECT_TEAM_V2_H

#include <string>
#include <vector>

class ProjectTeamV2 {
public:
    ProjectTeamV2() = default;
    explicit ProjectTeamV2(std::size_t capacity) {
        items_.reserve(capacity);
    }

    void add(const std::string& surname) {
        items_.push_back(surname);
    }

    std::size_t size() const { return items_.size(); }


private:
    std::vector<std::string> items_; 
};

#endif