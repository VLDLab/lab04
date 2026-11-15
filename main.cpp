#include <iostream>
#include "ProjectTeam.h"

void testCopy(ProjectTeam team) {
    std::cout << "Inside testCopy, size: " << team.size() << std::endl;
}

int main() {
    ProjectTeam team(3);
    team.add("Гончаренко");
    team.add("Козак");

    std::cout << "Original team size: " << team.size() << std::endl;
    testCopy(team); // Тут спрацює конструктор копіювання

    return 0;
}