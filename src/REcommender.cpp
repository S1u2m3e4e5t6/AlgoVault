#include "Recommender.h"
#include <iostream>

void Recommender::suggestProblems(const User& user) {
    auto unsolved = user.getUnsolvedProblems();
    std::cout << "\nRecommended Problems:\n";
    for (const auto& p : unsolved) {
        std::cout << "- " << p.getTitle() << " (" << p.getCategory() << ")" << std::endl;
    }
}