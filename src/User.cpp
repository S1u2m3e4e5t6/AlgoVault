#include "User.h"
#include <iostream>
#include <fstream>

// Constructor
User::User(const std::string& uname) : name(uname) {}

// Add a new problem
void User::addProblem(const std::string& title, const std::string& category, bool solved) {
    problems.emplace_back(title, category, solved);
}

// Display all problems
void User::displayProgress() const {
    std::cout << "\nProgress for: " << name << std::endl;
    for (const auto& p : problems) {
        std::cout << "- " << p.getTitle() << " [" << p.getCategory() << "] - "
                  << (p.isSolved() ? "Solved" : "Unsolved") << std::endl;
    }
}

// Return all unsolved problems
std::vector<Problem> User::getUnsolvedProblems() const {
    std::vector<Problem> unsolved;
    for (const auto& p : problems) {
        if (!p.isSolved()) {
            unsolved.push_back(p);
        }
    }
    return unsolved;
}

// Save to file
void User::saveToFile() const {
    std::ofstream fout("data/" + name + ".txt");
    if (!fout.is_open()) {
        std::cerr << "[ERROR] Could not open file for writing: data/" << name << ".txt\n";
        return;
    }

    for (const auto& p : problems) {
        fout << p.getTitle() << "|" << p.getCategory() << "|" << p.isSolved() << "\n";
    }

    fout.close();
}

// Load from file
void User::loadFromFile() {
    std::ifstream fin("data/" + name + ".txt");
    if (!fin.is_open()) {
        std::cerr << "[INFO] No existing file found for user: " << name << "\n";
        return;
    }

    std::string line;
    while (std::getline(fin, line)) {
        size_t p1 = line.find('|');
        size_t p2 = line.find('|', p1 + 1);
        std::string title = line.substr(0, p1);
        std::string category = line.substr(p1 + 1, p2 - p1 - 1);
        bool solved = (line.substr(p2 + 1) == "1");

        problems.emplace_back(title, category, solved);
    }

    fin.close();
}

#include <map>
#include <iomanip>

void User::displayStats() const {
    std::map<std::string, std::pair<int, int>> stats; // category → {solved, total}

    for (const auto& p : problems) {
        std::string cat = p.getCategory();
        stats[cat].second++;  // total++
        if (p.isSolved()) stats[cat].first++;  // solved++
    }

    std::cout << "\n📊 DSA Progress Summary:\n";
    for (const auto& entry : stats) {
        std::cout << "- " << std::setw(6) << entry.first << " : "
                  << entry.second.first << " solved out of " << entry.second.second << "\n";
    }
}
