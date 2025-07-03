#include <iostream>
#include <string>
#include "include/User.h"
#include "include/Recommender.h"

int main() {
    std::string username;
    std::cout << "Enter your username: ";
    std::getline(std::cin, username);

    User user(username);
    user.loadFromFile();  // 🗂 Load existing data

    user.addProblem("Array Sum", "Array", true);
    user.addProblem("Binary Tree DFS", "Tree", false);
    user.addProblem("Binary Search", "Array", false);

    user.displayProgress();   // ✅ Show problem list
    user.displayStats();      // ✅ Show category stats

    Recommender rec;
    rec.suggestProblems(user);

    user.saveToFile();        // 💾 Save progress

    return 0;
}
