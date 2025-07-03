#ifndef RECOMMENDER_H
#define RECOMMENDER_H
#include "User.h"

class Recommender {
public:
    void suggestProblems(const User& user);
};
#endif