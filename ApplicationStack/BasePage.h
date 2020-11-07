#pragma once
#include <cstddef>
using namespace std;

class BasePage {
public:
    std::string title;
    BasePage* previous;
    BasePage() { }
    ~BasePage() { }

};