#include "Problem.h"

Problem::Problem(const std::string& t, const std::string& c, bool s)
    : title(t), category(c), solved(s) {}

bool Problem::isSolved() const {
    return solved;
}

std::string Problem::getCategory() const {
    return category;
}

std::string Problem::getTitle() const {
    return title;
}