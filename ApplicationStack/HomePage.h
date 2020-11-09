#pragma once
#include "BasePage.h"
using namespace std;

// New Class and inherit Base Page
class HomePage : public BasePage {
public:
	// Invoke inherited constructor and assign its public value
	HomePage(int p) : BasePage(p) {
		title = "Home Page";
	}
};
