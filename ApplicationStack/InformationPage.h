#pragma once
#include "BasePage.h"
using namespace std;

// New Class and inherit Base Page
class InformationPage : public BasePage {
public:
    // Invoke inherited constructor and assign its public value
    InformationPage(int p) : BasePage(p) {
        title = "Information Page";
    }
};
