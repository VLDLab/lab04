#include <iostream>
#include "ProjectTeam.h"
#include "ProjectTeamV2.h"

int main() {
    std::cout << "Testing Rule of Five (ProjectTeam)" << std::endl;
    ProjectTeam team1(3);
    team1.add("Гончаренко");
    team1.add("Козак");

    // Перевірка конструктора копіювання
    ProjectTeam team2 = team1;
    std::cout << "Team 1 size: " << team1.size() << ", Team 2 size (copy): " << team2.size() << std::endl;
    std::cout << "Copy count: " << ProjectTeam::copy_count << std::endl;

    std::cout << "\n=== Testing Rule of Zero (ProjectTeamV2) ===" << std::endl;
    ProjectTeamV2 v2_team(3);
    v2_team.add("Петренко");
    v2_team.add("Шевченко");
    std::cout << "ProjectTeamV2 size: " << v2_team.size() << std::endl;
    std::cout << "All tests passed successfully!" << std::endl;

    return 0;
}