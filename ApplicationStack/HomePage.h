#pragma once
#include "BasePage.h"
using namespace std;

// New Class and inherit Base Page
class HomePage : public BasePage {
public:
	// Invoke inheritted constructor and asign its public value
	HomePage(int p) : BasePage(p) {
		title = "Home Page";
	}
};
