#pragma once
#include "BasePage.h"
using namespace std;

// New Class and inherit Base Page
class InformationPage : public BasePage {
public:
    // Invoke inheritted constructor and asign its public value
    InformationPage(int p) : BasePage(p) {
        title = "Information Page";
    }
};
