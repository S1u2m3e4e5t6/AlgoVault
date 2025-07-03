#ifndef PROBLEM_H
#define PROBLEM_H
#include <string>

class Problem {
private:
    std::string title;
    std::string category;
    bool solved;
public:
    Problem(const std::string& t, const std::string& c, bool s);
    bool isSolved() const;
    std::string getCategory() const;
    std::string getTitle() const;
};

#endif
