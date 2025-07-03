#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "Problem.h"

class User {
private:
    std::string name;
    std::vector<Problem> problems;

public:
    User(const std::string& uname);
    void addProblem(const std::string& title, const std::string& category, bool solved);
    void displayProgress() const;
    std::vector<Problem> getUnsolvedProblems() const;

    // ✅ These functions must be inside the class
    void saveToFile() const;
    void loadFromFile();
    void displayStats() const;
};

#endif
